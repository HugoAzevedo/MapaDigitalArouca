#include <iostream>

using namespace std;

#include "ViaLigacao.h"
#include "AutoEstrada.h"
#include "EstradaNacional.h"
#include "InteresseTuristico.h"
#include "Turistico_Hist_Cult.h"
#include "TuristicoNaturais.h"


void main()
{	

	TuristicoNaturais t1("LocTurist1",9000);
	cout << t1 << endl;
	TuristicoNaturais t2("LocTurist2",5500);
	cout << t2 << endl;


	EstradaNacional e1(t1,t2,"EN1",100,90,"asfalto");
	cout << e1 << endl;

	Turistico_Hist_Cult th1("LocTirist3",120,9.30,17.30);
	cout << th1 << endl;

	Turistico_Hist_Cult th2("LocTirist4",120,10.30,18);
	cout << th2 << endl;

	AutoEstrada a1(th1,th2,"A3", 200, 2,12.25);
	cout << a1 << endl;

	cin.get();
}