#include "Farmacie_abstracta.h"
#include <iostream>
using namespace std;

Farmacie_abstracta::Farmacie_abstracta()
{
	this->denumire = "";
}


Farmacie_abstracta::Farmacie_abstracta(std::string denumire)
{
	this->denumire = denumire;
}

void Farmacie_abstracta::Afisare()
{
	cout << endl;
	cout << "Denumirea farmaciei: " << this->denumire;
	cout << endl;
}

string Farmacie_abstracta::getDenumire()
{
	return this->denumire;
}

