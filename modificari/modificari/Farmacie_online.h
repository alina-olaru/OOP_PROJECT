#pragma once
#include "Farmacie_abstracta.h"
#include <iostream>

using namespace  std;

class Farmacie_online : virtual  public Farmacie_abstracta
{
	static const float medie;
protected:
	char* adresa_web;
	int nr_vizitatori;
public:
	double calcul_venit() override;
	Farmacie_online();
	Farmacie_online(char* adresa_web, int nr_vizitatori, string denumire);
	virtual ~Farmacie_online();
	Farmacie_online(Farmacie_online& obj);
	Farmacie_online& operator=(Farmacie_online& obj);
	void  Afisare() override;

	char* getAdresaWeb();
	int getNrVizitatori();

	friend istream& operator>>(istream& in, Farmacie_online& obj);
};
