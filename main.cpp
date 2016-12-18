#include "bitfield.h"
#include "set.h"
#include <iostream>
using namespace std;

void main()
{
	int sel;
	unsigned int PowA,PowB;
	cout << "Input the power of A: ";
	do
		cin >> PowA;
	while(PowA<1);
	set A(PowA);
	cout << "A sets default empty ";
	cin.get();
	cin.get();
	do
	{
		system("cls");
		cout << "1. Insert an element into the set" << endl
			 << "2. Delete the element from the set" << endl
			 << "3. Input the whole set" << endl
			 << "4. Output the set" << endl
			 << "5. Output the set as bitfield" << endl
			 << "6. Input another set and output union and crossing" << endl
			 << "7. Output the addiction to the universe" << endl
			 << "0. Exit" << endl << endl
			 << "Your command: ";
		cin >> sel;
		system("cls");
		switch(sel)
		{
		case 1: 
		{
			int elem;
			cout << "Input the element: ";
			cin >> elem;
			A.ins(elem); break;
		}
		case 2: 
		{
			int elem;
			cout << "Input the element: ";
			cin >> elem;
			A.del(elem); break;
		}
		case 3:
		{
			cin >> A; break;
		}
		case 4:
		{
			cout << A; break;
		}
		case 5:
		{
			A.outAsBitfield(); break;
		}
		case 6:
		{
			cout << "Input the power of B: ";
			do
				cin >> PowB;
			while(PowB<1);
			set B(PowB);
			cout << "Input the set: " << endl;
			cin >> B;
			system("cls");
			set Union(PowA), Crossing(PowA);
			Union = A + B;
			Crossing = A * B;
			cout << "Union: " << Union << endl
				<< "Crossing: " << Crossing << endl; break;
		}
		case  7:
		{
			set Uni(PowA);
			Uni = ~A;
			cout << "Addiction to the universe: " << Uni << endl; break;
		}
		}
		cin.get();
		cin.get();
	}
	while(sel != 0);
}