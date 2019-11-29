#pragma once
#include <iostream>
#include "Farmacie_online.h"
#include "Farmacie_offline.h"

using namespace  std;

class Farmacie_dubla_specializare : public Farmacie_offline, public Farmacie_online
{
protected:
	int nr_angajati;
public:
	Farmacie_dubla_specializare();
	Farmacie_dubla_specializare(int nr_angajati, string denumire, int nr_luni, double* cifra_afaceri_luna, char* adresa_web, int nr_vizitatori);
	virtual ~Farmacie_dubla_specializare();
	Farmacie_dubla_specializare(Farmacie_dubla_specializare& obj);
	Farmacie_dubla_specializare& operator=(Farmacie_dubla_specializare& obj);
	void Afisare() override;

	operator int();

	int getNrAngajati();
	double calcul_venit() override;
	friend istream& operator>>(istream& in, Farmacie_dubla_specializare& obj);
};