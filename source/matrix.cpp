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

// Constructor paramétrico y por defecto de la clase.
Matrix::Matrix( int nRen, int nCol ) {
	m = ( nRen > 0 ) ? nRen : 1;
	n = ( nCol > 0 ) ? nCol : 1;

	// Creamos el arreglo que contendrá todos los elementos de la matriz.
	elemPtr = new double[ n*m ];

	// Verificamos si se pudo crear correctamente.
	assert( elemPtr != 0 );

	// Si no se detuvo el programa, inicializamos en ceros la matriz.
	for( int i = 0; i < ( m*n ); i++ ) elemPtr[ i ] = 0.0;
}

// Constructor copia: Crea matriz a partir de otra.
Matrix::Matrix( const Matrix &matrix ) : Matrix( matrix.m, matrix.n ) {
	// Copiamos los elementos de la matriz a copiar en la nueva.
	for( int i = 0; i < ( m*n ); i++ ) elemPtr[i] = matrix.elemPtr[i];
}

// Destructor, libera la memoria almacenada con new.
Matrix::~Matrix() {
	delete [] elemPtr;
}

// Funciones miembro.
	// Rellena la matriz con valores (enteros) aleatorios.
void Matrix::randomMatrix() {
	for( int i = 0; i < ( m*n ); i++ ) elemPtr[i] = ranNum( 0, 100 );
}

// Funciones utilitarias.
int Matrix::ranNum( int min, int max ) { return ( rand()%max ) + min; }

// Operadores sobrecargados.
	// Operador de asignación.
const Matrix &Matrix::operator =( const Matrix &right ) {

	// Para evitar autoasignación.
	if( &right != this ) {
		delete [] elemPtr;
		m = right.m; n = right.n;

		elemPtr = new double[ m*n ];
		for( int i = 0; i < ( m*n ); i++ ) elemPtr[i] = right.elemPtr[i];
	}

	return *this;
}

	// Operador de adición.
const Matrix Matrix::operator +( const Matrix &right ) {
	Matrix res;
	
	// Si la matriz tiene las mismas dimensiones se realiza la operación.
	if( m == right.m && n == right.n ) {
		res.m = m; res.n = n;
		if( res.elemPtr ) delete [] res.elemPtr;

		res.elemPtr = new double [ res.m*res.n ]; 
		for( int i = 0; i < ( m*n ); i++ )
			res.elemPtr[i] = elemPtr[i] + right.elemPtr[i];
	}

	return res;
}

const Matrix Matrix::operator -( const Matrix &right ) {
	Matrix res;

	// Si la matriz tiene las mismas dimensiones se realiza la operación.
	if( m == right.m && n == right.n ) {
		res.m = m; res.n = n;
		if( res.elemPtr ) delete [] res.elemPtr;

		res.elemPtr = new double [ res.m*res.n ]; 
		for( int i = 0; i < ( m*n ); i++ )
			res.elemPtr[i] = elemPtr[i] - right.elemPtr[i];
	}

	return res;
}

const Matrix Matrix::operator *( const Matrix &right ) {
	Matrix res;

	// Verificamos si las matrices son multiplicables.
	if( n == right.m ) {
		res.m = m; res.n = right.n;
		if( res.elemPtr ) delete [] res.elemPtr;

		res.elemPtr = new double[ res.m*res.n ];

		for( int i = 0; i < res.m; i++ )
			for( int j = 0; j < res.n; j++ )
				for( int k = 0; k < res.m; k++ )
					res.elemPtr[ (i*res.n) + j ] += elemPtr[ (i*n) + k ] * right.elemPtr[ (k*right.n) + j ];

	}

	return res;
}

// Verificar que no se pase del límite de elementos.
double &Matrix::operator ()( int x, int y ) {
	if( (x-1) <= m && (y-1) <= n )
		return elemPtr[ (x-1)*n + (y-1) ];
	return elemPtr[0];
}
const double Matrix::operator ()( int x, int y ) const {
	if( (x-1) <= m && (y-1) <= n )
		return elemPtr[ (x-1)*n + (y-1) ];
	return elemPtr[0];
}

// Operador << sobrecargado, muestra la matriz en pantalla en formato cuadriculado.
ostream &operator <<( ostream &output, const Matrix &matrix ) {
	// Imprime cada elemento del arreglo en formato cuadrado con salto cada n+1 elementos.
	output << endl;
	for( int i = 0; i < ( matrix.m*matrix.n ); i++ )
		output << setw( 12 ) << matrix.elemPtr[ i ] << ( ( (i+1)%matrix.n == 0 ) ? '\n' : ' ' );
	output << endl;

	return output;
}

// Operador >> sobrecargado, permite introducir una matriz.
istream &operator >>( istream &input, Matrix &matrix ) {
	cout << endl;
	for( int i = 0; i < matrix.m; i++ ) {
		for( int j = 0; j < matrix.n; j++ ) {
			cout << "Elemento [" << i << ", " << j << "] = ";
			input >> matrix.elemPtr[ (i*matrix.n) + j ];
		}
	}
	cout << endl;

	return input;
}
