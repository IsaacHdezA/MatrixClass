#include <iostream>
#include "includes/matrix.hpp"

using namespace std;

int main( void ) {

	Matrix m1( 2, 3 ), m2( 3, 2 );

	cout << "Matriz 1(" << m1.getRows() << ", " << m1.getCols() << "): " << m1
	     << "Matriz 2(" << m2.getRows() << ", " << m2.getCols() << "): " << m2;

	cout << "Matriz 1: " << m1;
	cin >> m1;

	cout << "Matriz 2: " << m2;
	cin >> m2;

	Matrix m3;
	cout << "Matriz 3(" << m3.getRows() << ", " << m3.getCols() << "): " << m3;

	m3 = m1*m2;
	cout << "Matriz 1(" << m1.getRows() << ", " << m1.getCols() << "): " << m1
	     << "Matriz 2(" << m2.getRows() << ", " << m2.getCols() << "): " << m2
	     << "Matriz 3(" << m3.getRows() << ", " << m3.getCols() << "): " << m3;


	return 0;
}
