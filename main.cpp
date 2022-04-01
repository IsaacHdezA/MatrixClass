#include <iostream>
#include "includes/matrix.hpp"

using namespace std;

int main( void ) {

	Matrix m1( 3, 3 ), m2( 3, 3 );
	double arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	cout << "Matriz 1(" << m1.getRows() << ", " << m1.getCols() << " ): " << m1
	     << "Matriz 2(" << m2.getRows() << ", " << m2.getCols() << " ): " << m2;

	cout << "Matriz 1 (generada aleatoriamente): " << m1.randomMatrix();
	cout << "Matriz 2 (generada aleatoriamente): " << m2.randomMatrix();

	cout << "Matriz 1 y Matriz 2 son iguales: "    << (m1 == m2) << endl;
	cout << "Matriz 1 y Matriz 2 son diferentes: " << (m1 != m2) << endl;

	Matrix m3;
	cout << "Matriz 3(" << m3.getRows() << ", " << m3.getCols() << "): " << m3;

	Matrix m4( arr, 9, 1, 9 );

	m3 = m1*m2;
	cout << "Matriz 1(" << m1.getRows() << ", " << m1.getCols() << "): " << m1
	     << "Matriz 2(" << m2.getRows() << ", " << m2.getCols() << "): " << m2
	     << "Matriz 3(" << m3.getRows() << ", " << m3.getCols() << "): " << m3
	     << "Matriz 4(" << m4.getRows() << ", " << m4.getCols() << "): " << m4 << endl;

	return 0;
}
