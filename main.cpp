#include <iostream>
#include "includes/matrix.hpp"

using namespace std;

int main( void ) {

	Matrix m1( 3, 3 );
	Matrix m2;

	cout << "Matriz 1: " << m1 << "Matriz 2: " << m2;
	cin >> m1;
	m2 = m1;
	cout << "Matriz 1: " << m1 << "Matriz 2: " << m2;

	return 0;
}
