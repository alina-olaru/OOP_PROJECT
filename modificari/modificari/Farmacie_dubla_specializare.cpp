#include "Farmacie_dubla_specializare.h"
#include <iostream>
#include <fstream>
//#include "1.txt"

using namespace std;

Farmacie_dubla_specializare::Farmacie_dubla_specializare() : Farmacie_online(), Farmacie_offline()
{
	this->nr_angajati = 0;
}

Farmacie_dubla_specializare::Farmacie_dubla_specializare(int nr_angajati, string denumire, int nr_luni, double* cifra_afaceri_luna, char* adresa_web, int nr_vizitatori)
	: Farmacie_online(adresa_web, nr_vizitatori, denumire),
	Farmacie_offline(nr_luni, cifra_afaceri_luna, denumire),
	Farmacie_abstracta(denumire)
{
	this->nr_angajati = nr_angajati;
}

Farmacie_dubla_specializare::~Farmacie_dubla_specializare()
{
	cout << endl << "Destructor Farmacie_dubla_specializare" << endl;
}

Farmacie_dubla_specializare::Farmacie_dubla_specializare(Farmacie_dubla_specializare& obj) : Farmacie_online(obj), Farmacie_offline(obj)
{
	this->nr_angajati = obj.nr_angajati;
}

Farmacie_dubla_specializare& Farmacie_dubla_specializare::operator=(Farmacie_dubla_specializare& obj)
{
	Farmacie_offline::operator=(obj);
	Farmacie_online::operator=(obj);
	this->nr_angajati = obj.nr_angajati;
	return *this;
}


void Farmacie_dubla_specializare::Afisare()
{
	Farmacie_offline::Afisare();
	Farmacie_online::Afisare();

	cout << endl << "Nr angajati: " << this->nr_angajati << endl;

}


int Farmacie_dubla_specializare::getNrAngajati()
{
	return this->nr_angajati;
}

Farmacie_dubla_specializare::operator int()
{
	return this->nr_angajati;
}

istream& operator>>(istream& in, Farmacie_dubla_specializare& obj)
{
	std::ifstream myfile("1.txt");

	myfile >> obj.nr_angajati;

	myfile.close();
	return in;

}

double Farmacie_dubla_specializare::calcul_venit()
{
	return Farmacie_offline::calcul_venit();
}