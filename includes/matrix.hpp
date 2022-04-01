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
		Matrix( const double *, int, int, int ); // Constructor copia por apuntador.
		~Matrix(); // Destructor.

		// Funciones miembro.
		int getRows()   const { return m; }
		int getCols()   const { return n; }
		int getLength() const { return m * n; }
		const Matrix randomMatrix();

		// Operadores sobrecargados.
		const Matrix &operator =( const Matrix & ); // Operador de copia.
		const Matrix  operator +( const Matrix & ) const; // Operador de adición.
		const Matrix  operator -( const Matrix & ) const; // Operador de sustracción.
		const Matrix  operator *( const Matrix & ) const; // Operador de producto (mult. matrices).
		bool operator ==( const Matrix &  ) const;  // Operador de igualdad.
		bool operator !=( const Matrix &m ) const { return !( *this == m ); }
		const double operator ()( int, int ) const; // Operador paréntesis (sólo lectura).
		double &operator ()( int, int );           //Operador paréntesis (permite modificar un elemento).

	private:
		int m; // Número de renglones de la matriz.
		int n; // Número de columnas de la matrix.
		double *elemPtr; // Apuntador a tipo double que contendrá los elementos de la matrix.

		// Función utilitaria.
		int ranNum( int, int );
};

#endif
