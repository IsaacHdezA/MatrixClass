/*
 * Desarrollado por: Aldo Isaac Hernández Antonio.
 * Fecha de creación: 03/03/2021.
 * Descripción: Definición clase Matrix para números de punto doble, declaración en includes/matrix.hpp.
 * 	Universidad de Guanajuato, División de Ingenierías Irapuato-Salamanca.
 */

#include <iostream>
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
Matrix::Matrix( const Matrix &matrix ) {
	// En caso de ser una matriz ya inicializada, eliminamos sus elementos.
	if( elemPtr ) delete [] elemPtr;

	// Asignamos el número de elementos de la nueva matriz.
	m = matrix.m; n = matrix.n;

	// Apartamos el espacio necesario para almacenar la nueva matriz.
	elemPtr = new double[ m*n ];

	// Copiamos los elementos de la matriz a copiar en la nueva.
	for( int i = 0; i < ( m*n ); i++ ) elemPtr[i] = matrix.elemPtr[i];
}

// Destructor, libera la memoria almacenada con new.
Matrix::~Matrix() {
	delete [] elemPtr;
	elemPtr = 0;
}

// Operadores sobrecargados.
	// Operador de adición.
//const Matrix &Matrix::operator +( const Matrix &m ) {
//}
//
//const Matrix &operator -( const Matrix & );

// Operador << sobrecargado, muestra la matriz en pantalla en formato cuadriculado.
ostream &operator <<( ostream &output, const Matrix &matrix ) {
	// Imprime cada elemento del arreglo en formato cuadrado con salto cada n+1 elementos.
	cout << endl;
	for( int i = 0; i < ( matrix.m*matrix.n ); i++ )
		output << setw( 12 ) << matrix.elemPtr[ i ] << ( ( (i+1)%matrix.n == 0 ) ? "\n" : " " );
	cout << endl;

	return output;
}

istream &operator >>( istream &input, Matrix &matrix ) {
	cout << endl;
	for( int i = 0; i < matrix.m; i++ ) {
		for( int j = 0; j < matrix.n; j++ ) {
			cout << "Elemento [" << i << ", " << j << "] = ";
			input >> matrix.elemPtr[ (i*matrix.m) + j ];
		}
	}
	cout << endl;

	return input;
}
