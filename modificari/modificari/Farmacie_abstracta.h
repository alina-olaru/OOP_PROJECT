#pragma once
#include <stdlib.h>
#include <string>

using namespace std;

class Farmacie_abstracta
{
protected:
	string denumire;
public:
	Farmacie_abstracta();
	Farmacie_abstracta(string denumire);
	string getDenumire();
	virtual double calcul_venit() = 0;
	virtual void Afisare();
};
