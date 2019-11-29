#include "Farmacie_offline.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Farmacie_offline::Farmacie_offline() : Farmacie_abstracta("")
{
	this->nr_luni = 0;
	this->cifra_afaceri_luna = new double[0];
}

Farmacie_offline::Farmacie_offline(int nr_luni, double* cifra_afaceri_luna, std::string denumire) : Farmacie_abstracta(denumire)
{
	this->nr_luni = nr_luni;
	this->cifra_afaceri_luna = cifra_afaceri_luna;
}

Farmacie_offline::~Farmacie_offline()
{
	delete[] this->cifra_afaceri_luna;
}

Farmacie_offline::Farmacie_offline(Farmacie_offline& obj) : Farmacie_abstracta(obj.denumire)
{
	this->nr_luni = obj.nr_luni;
	this->cifra_afaceri_luna = new double[obj.nr_luni];
	for (int i = 0; i < obj.nr_luni; i++)
	{
		this->cifra_afaceri_luna[i] = obj.cifra_afaceri_luna[i];
	}

}

Farmacie_offline& Farmacie_offline::operator=(Farmacie_offline const& obj)
{
	if (this != &obj)
	{
		nr_luni = obj.nr_luni;
		denumire = obj.denumire;

		this->cifra_afaceri_luna = new double[obj.nr_luni];
		for (int i = 0; i < obj.nr_luni; i++)
		{
			this->cifra_afaceri_luna[i] = obj.cifra_afaceri_luna[i];
		}

	}

	return *this;
}

void Farmacie_offline::Afisare()
{
	Farmacie_abstracta::Afisare();
	cout << endl;
	cout << "Nr. luni: " << this->nr_luni << endl;
	cout << "Cifra afaceri luni:" << endl;
	for (int i = 0; i < this->nr_luni; i++)
	{
		cout << i + 1 << " - " << this->cifra_afaceri_luna[i] << endl;
	}

}


double Farmacie_offline::calcul_venit()
{
	double sum = 0;
	for (int i = 0; i < this->nr_luni; i++)
	{
		sum = sum + this->cifra_afaceri_luna[i];
	}

	return sum;
}


int Farmacie_offline::getNrLuni()
{
	return this->nr_luni;
}

double* Farmacie_offline::getCifraAfaceriLuna()
{
	return this->cifra_afaceri_luna;
}


istream& operator>>(istream& in, Farmacie_offline& obj)
{
	std::ifstream myfile("2.txt");
	myfile >> obj.nr_luni;
	for (int i = 0; i < obj.nr_luni; i++) {
		myfile >> obj.cifra_afaceri_luna[i];
	}
	myfile.close();
	return in;
}



