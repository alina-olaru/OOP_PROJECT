#include "Farmacie_online.h"
#include <iostream>
#include <fstream>

using namespace std;

const float Farmacie_online::medie = 123;

Farmacie_online::Farmacie_online() : Farmacie_abstracta("")
{
	this->nr_vizitatori = 0;
	this->adresa_web = new char[0];
}

Farmacie_online::Farmacie_online(char* adresa_web, int nr_vizitatori, string denumire) :Farmacie_abstracta(denumire)
{
	this->nr_vizitatori = nr_vizitatori;
	this->adresa_web = adresa_web;
}

Farmacie_online::~Farmacie_online()
{
	delete[] this->adresa_web;
}

Farmacie_online::Farmacie_online(Farmacie_online& obj) : Farmacie_abstracta(obj.denumire)
{
	this->nr_vizitatori = obj.nr_vizitatori;
	this->adresa_web = new char[strlen(obj.adresa_web)];
	strcpy_s(this->adresa_web, strlen(obj.adresa_web), obj.adresa_web);
}

Farmacie_online& Farmacie_online::operator=(Farmacie_online& obj)
{
	this->denumire = obj.denumire;
	this->nr_vizitatori = obj.nr_vizitatori;
	this->adresa_web = new char[strlen(obj.adresa_web)];
	strcpy_s(this->adresa_web, strlen(obj.adresa_web), obj.adresa_web);
	return *this;
}


void Farmacie_online::Afisare()
{
	Farmacie_abstracta::Afisare();
	cout << endl;
	cout << "Nr vizitatori: " << this->nr_vizitatori << endl;
	cout << "Adresa web: " << this->adresa_web << endl;

}

int Farmacie_online::getNrVizitatori()
{
	return this->nr_vizitatori;
}

char* Farmacie_online::getAdresaWeb()
{
	return this->adresa_web;
}

istream& operator>>(istream& in, Farmacie_online& obj)
{
	std::ifstream myfile("3.txt");
	myfile >> obj.nr_vizitatori;
	myfile >> obj.adresa_web;

	return in;
}


double Farmacie_online::calcul_venit()
{
	return Farmacie_online::medie;
}