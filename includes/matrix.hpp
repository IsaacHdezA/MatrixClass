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

	friend ostream &operator <<( ostream &, const Matrix & );
	friend istream &operator >>( istream &, Matrix & );
	
	public:
		Matrix( int = 1, int = 1 ); // Constructor paramétrico/por defecto.
		Matrix( const Matrix & ); // Constructor copia.
		~Matrix(); // Destructor.
		const Matrix &operator +( const Matrix & );
		const Matrix &operator -( const Matrix & );
	private:
		int m; // Número de renglones de la matriz.
		int n; // Número de columnas de la matrix.
		double *elemPtr; // Apuntador a tipo double que contendrá los elementos de la matrix.
};

#endif
