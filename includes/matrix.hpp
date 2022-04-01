/*
 * Desarrollado por: Aldo Isaac Hernández Antonio.
 * Fecha de creación: 03/03/2021.
 * Descripción: Declaración clase Matrix para números de punto doble, definición en source/matrix.cpp.
 * 	Universidad de Guanajuato, División de Ingenierías Irapuato-Salamanca.
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

using std::ostream;
using std::istream;

class Matrix {
	friend ostream &operator <<(ostream &, const Matrix &);
	friend istream &operator >>(istream &, Matrix &);
	friend Matrix  operator  *(double, const Matrix &);
	
	public:
		Matrix(int = 1, int = 1);
		Matrix(const Matrix &); // Copy constructor
		Matrix(const double *, unsigned int, unsigned int, unsigned int); // Array constructor
		~Matrix();

		// Methods
		int getRows()   const { return m; }
		int getCols()   const { return n; }
		int getLength() const { return m * n; }
		const Matrix randomMatrix();

		// Operadores sobrecargados.
		const Matrix &operator =(const Matrix &);
		const Matrix  operator +(const Matrix &) const;
		const Matrix  operator -(const Matrix &) const;
		const Matrix  operator *(const Matrix &) const;
		const Matrix  operator *(int) const;
		bool operator ==(const Matrix & ) const;
		bool operator !=(const Matrix &m) const { return !(*this == m); }
		const double operator ()(int, int) const; // Parenthesis operator (read only)
		double &operator ()(int, int);            // Parenthesis operator (write)
							     
	private:
		int m; // Rows
		int n; // Cols
		double *elemPtr; // Data array

		// Utility functions
		int ranNum(int, int);
};

#endif
