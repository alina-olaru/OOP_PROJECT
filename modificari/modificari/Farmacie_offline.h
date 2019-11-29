#pragma once
#include "Farmacie_abstracta.h"

class Farmacie_offline : virtual  public Farmacie_abstracta
{

protected:
	int nr_luni;
	double* cifra_afaceri_luna;
public:
	Farmacie_offline();
	Farmacie_offline(int nr_luni, double* cifra_afaceri_luna, std::string denumire);
	virtual ~Farmacie_offline();
	Farmacie_offline(Farmacie_offline& obj);
	Farmacie_offline& operator=(Farmacie_offline const& obj);
	void Afisare() override;

	int getNrLuni();
	double* getCifraAfaceriLuna();

	double calcul_venit() override;

	friend istream& operator>>(istream& in, Farmacie_offline& obj);
};
