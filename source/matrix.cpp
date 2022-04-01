/*
 * Desarrollado por: Aldo Isaac Hernández Antonio.
 * Fecha de creación: 03/03/2021.
 * Descripción: Definición clase Matrix para números de punto doble, declaración en includes/matrix.hpp.
 * 	Universidad de Guanajuato, División de Ingenierías Irapuato-Salamanca.
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include "../includes/matrix.hpp"

using std::setw;
using namespace std;

// Default constructor
Matrix::Matrix(int nRen, int nCol) {
	m = (nRen > 0) ? nRen : 1;
	n = (nCol > 0) ? nCol : 1;

	elemPtr = new double[m * n];
	assert(elemPtr != 0);

	for(int i = 0; i < (m * n); i++) elemPtr[i] = 0.0;
}

// Copy constructor
Matrix::Matrix(const Matrix &matrix) : Matrix(matrix.m, matrix.n) {
	for(int i = 0; i < (m * n); i++) elemPtr[i] = matrix.elemPtr[i];
}

// Array constructor, copies data from an array and creates a Matrix object.
Matrix::Matrix(const double *arr, unsigned int size, unsigned int nRen, unsigned int nCol) : Matrix(nRen, nCol) {
	if(size > 0) {
		if(size == (nRen * nCol))
			for(int i = 0; i < (m * n); i++) elemPtr[i] = arr[i];
		else {
			m = 1; n = 1;
			elemPtr = new double[m * n];

			assert(elemPtr != 0);
			for(int i = 0; i < (m * n); i++) elemPtr[i] = 0.0;
		}
	} else return;
}

// Destructor, frees allocated memory.
Matrix::~Matrix() {
	delete [] elemPtr;
	elemPtr = NULL;
}

// Creates and return matrix with random values.
const Matrix Matrix::randomMatrix() {
	for(int i = 0; i < (m * n); i++) elemPtr[i] = ranNum(0, 100);
	return *this;
}

// Overloaded assignment operator (copy)
const Matrix &Matrix::operator =(const Matrix &right) {
	// Verifying self-assignment
	if(&right != this) {
		delete [] elemPtr;
		m = right.m; n = right.n;

		elemPtr = new double[m * n];
		for(int i = 0; i < (m * n); i++) elemPtr[i] = right.elemPtr[i];
	}

	return *this;
}

const Matrix Matrix::operator +(const Matrix &right) const {
	Matrix res;
	
	if((m == right.m) && (n == right.n)) {
		res.m = m; res.n = n;
		if(res.elemPtr) delete [] res.elemPtr;

		res.elemPtr = new double [res.m * res.n]; 
		for(int i = 0; i < (m * n); i++ )
			res.elemPtr[i] = elemPtr[i] + right.elemPtr[i];
	}

	return res;
}


const Matrix Matrix::operator -(const Matrix &right) const {
	Matrix res;

	if((m == right.m) && (n == right.n)) {
		res.m = m; res.n = n;
		if(res.elemPtr) delete [] res.elemPtr;

		res.elemPtr = new double [res.m * res.n]; 
		for(int i = 0; i < (m * n); i++ )
			res.elemPtr[i] = elemPtr[i] - right.elemPtr[i];
	}

	return res;
}

const Matrix Matrix::operator *(const Matrix &right) const {
	Matrix res;

	if(n == right.m) {
		res.m = m; res.n = right.n;
		if(res.elemPtr) delete [] res.elemPtr;

		res.elemPtr = new double[res.m * res.n];

		for(int i = 0; i < res.m; i++)
			for(int j = 0; j < res.n; j++)
				for(int k = 0; k < res.m; k++)
					res.elemPtr[(i * res.n) + j] += elemPtr[(i * n) + k] * right.elemPtr[(k * right.n) + j];
	}

	return res;
}

Matrix operator *(double number, const Matrix &right) {
	Matrix res(right.m, right.n);
	
	for(int i = 0; i < right.getLength(); i++)
		res.elemPtr[i] = right.elemPtr[i] * number;

	return res;
}

const Matrix Matrix::operator *(int number) const {
	Matrix res(m, n);
	
	for(int i = 0; i < getLength(); i++)
		res.elemPtr[i] = elemPtr[i] * number;

	return res;
}

bool Matrix::operator ==(const Matrix &right) const {
	if((this->m == right.m) && (this->n == right.n)) {
		const unsigned int SIZE = this->getLength();
		for(int i = 0; i < SIZE; i++)
			if(this->elemPtr[i] != right.elemPtr[i])
				return false;
	} else return false;

	return true;
}

// Parenthesis operator, returns a reference to the element we want to modify
double &Matrix::operator ()(int row, int col) {
	if((row < m) && (col < n)) return elemPtr[(row * n) + col];
	return elemPtr[0];
}

// Parenthesis operator, returns the element 
const double Matrix::operator ()(int row, int col) const {
	if((row < m) && (col < n)) return elemPtr[(row * n) + col];
	return elemPtr[0];
}

ostream &operator <<(ostream &output, const Matrix &matrix) {
	// Imprime cada elemento del arreglo en formato cuadrado con salto cada n+1 elementos.
	output << endl;
	for(int i = 0; i < (matrix.m * matrix.n); i++)
		output << setprecision(4) << matrix.elemPtr[i] << (((i + 1) % matrix.n == 0) ? '\n' : '\t');
	output << endl;

	return output;
}

istream &operator >>(istream &input, Matrix &matrix) {
	cout << endl;
	for(int i = 0; i < matrix.m; i++)
		input >> matrix.elemPtr[i];
	cout << endl;

	return input;
}

// Utility functions
int Matrix::ranNum(int min, int max) { return (rand()%max) + min; }

