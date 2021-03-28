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

		// Funciones miembro.
		int getRows() { return m; }
		int getCols() { return n; }
		void randomMatrix();

		// Operadores sobrecargados.
		const Matrix &operator =( const Matrix & ); // Operador de copia.
		const Matrix operator +( const Matrix & ); // Operador de adición.
		const Matrix operator -( const Matrix & ); // Operador de sustracción.
		const Matrix operator *( const Matrix & ); // Operador de producto.
		double &operator ()( int, int ); //Operador paréntesis (permite modificar un elemento).
		const double operator()( int, int ) const; // Operador paréntesis (sólo lectura).

	private:
		int m; // Número de renglones de la matriz.
		int n; // Número de columnas de la matrix.
		double *elemPtr; // Apuntador a tipo double que contendrá los elementos de la matrix.

		// Función utilitaria.
		int ranNum( int, int );
};

#endif
