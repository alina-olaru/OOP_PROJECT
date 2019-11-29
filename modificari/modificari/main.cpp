#include <iostream>
#include "Farmacie_dubla_specializare.h"

int main()
{
	Farmacie_abstracta** farmacii = new Farmacie_abstracta * [100];

	double* cifra_afaceri_1 = new double[3]{ 10000.5, 3450, 8900.74 };
	double* cifra_afaceri_2 = new double[4]{ 45000, 6785.25, 9645.23, 8000 };
	double* cifra_afaceri_3 = new double[5]{ 1000, 65000, 6485.25, 2645.23, 4000 };

	string ad_web_1 = "www.google.com";
	string ad_web_2 = "www.facebook.com";
	string ad_web_3 = "www.twitter.com";

	char* adresa_web_1 = _strdup(ad_web_1.c_str());
	char* adresa_web_2 = _strdup(ad_web_2.c_str());
	char* adresa_web_3 = _strdup(ad_web_3.c_str());


	Farmacie_abstracta* f_off1 = new Farmacie_offline(3, cifra_afaceri_1, "Farmacie offline 1");
	Farmacie_abstracta* f_onn1 = new Farmacie_online(adresa_web_1, 100, "Farmacie online 1");
	Farmacie_abstracta* f_dublu_1 = new Farmacie_dubla_specializare(50, "Farmacie dubla specializare 1", 4, cifra_afaceri_2, adresa_web_2, 500);
	Farmacie_dubla_specializare* f_dublu_2 = new Farmacie_dubla_specializare(5, "Farmacie dubla specializare 2", 4, cifra_afaceri_3, adresa_web_3, 1000);

	double venit1 = dynamic_cast<Farmacie_offline*>(f_off1)->calcul_venit();
	cout << endl << "Venit farmacie offline 1: " << venit1 << endl << endl;

	double venit2 = dynamic_cast<Farmacie_dubla_specializare*>(f_dublu_1)->calcul_venit();
	cout << endl << "Venit farmacie dubla specializare 1: " << venit1 << endl << endl;


	f_off1->Afisare();
	f_onn1->Afisare();
	f_dublu_1->Afisare();

	farmacii[0] = f_off1;
	farmacii[1] = f_onn1;
	farmacii[2] = f_dublu_1;

	Farmacie_offline* f_off2 = new Farmacie_offline(*dynamic_cast<Farmacie_offline*>(f_dublu_2));
	//Farmacie_offline* f_off2 = new Farmacie_offline(dynamic_cast<Farmacie_offline>(f_dublu_2));
	f_off2->Afisare();
	farmacii[3] = f_off2;

	for (int i = 0; i < 4; i++)
	{
		farmacii[i]->Afisare();
	}



}