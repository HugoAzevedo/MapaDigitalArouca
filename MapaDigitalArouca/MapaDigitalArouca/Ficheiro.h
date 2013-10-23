#ifndef Ficheiro_
#define Ficheiro_

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include "InteresseTuristico.h"
#include "AutoEstrada.h"
#include "EstradaNacional.h"
#include "Turistico_Hist_Cult.h"
#include "TuristicoNaturais.h"
#include "ViaLigacao.h"
#include <list>

using namespace std;

class Ficheiro
{

private:

	list <ViaLigacao *> vecViaLigacao;
	list <InteresseTuristico *> vecInteresseTuristico; 

public:

	//Construtores
	Ficheiro();//C1
	Ficheiro(const Ficheiro &fich);//Construtores
	~Ficheiro();//CDestrutor

};

//C1
Ficheiro::Ficheiro(){
}

#endif