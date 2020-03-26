/*
** EPITECH PROJECT, 2020
** 108trigo
** File description:
** main
*/

//libC
#include <iostream>

//mylibs
#include "trigo.h"
#include "matrix.h"

//namespaces
using namespace std;

//functions
int main(int argc, char *argv[])
{
	Matrix m(2, 2);
	Matrix b(2, 2);
	m.setAt(0, 0, 1);
	m.setAt(0, 1, 4);
	m.setAt(1, 0, 2);
	m.setAt(1, 1, 5);
	b.setAt(0, 0, 7);
	b.setAt(0, 1, 9);
	b.setAt(1, 0, 8);
	b.setAt(1, 1, 10);
	m.Display();
	cout << endl;
	b.Display();
	cout << endl;
	Matrix t = m + b;
	t.Display();
	cout << endl;
	t = m - b;
	t.Display();
	cout << endl;
	t = m * b;
	t.Display();
	cout << endl;
	return trigo();
}
