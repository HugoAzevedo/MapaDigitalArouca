#ifndef EstradaNacional_
#define EstradaNacional_

#include <stdio.h>
#include <string.h>
using namespace std;
#include "ViaLigacao.h"//Classe principal(Mãe)

class EstradaNacional: public ViaLigacao
{

private:
	string tipoPavimento;

public:

	ViaLigacao* clone() const ;//Testar Metodo Virtual Puro ****** Verificar********

	//Construtores 
	EstradaNacional();//C1
	EstradaNacional(const InteresseTuristico &o, const InteresseTuristico &d,string codVia, float totalkms, int tempMedio, string tPavimento );//C2
	EstradaNacional(const EstradaNacional &e);//C3
	~EstradaNacional();//CDestrutor
	//End Construtores

	//Metodo Get
	string getTipoPavimento() const;//G1
	//End Metodo Get

	//Metodo Set
	void setTipoPavimento(string tPavimento);//S1
	//End Metodos Set

	void EstradaNacional::escreve(ostream &out) const;

	//Sobrecarga de Operadores
	EstradaNacional & operator = (const EstradaNacional &e);
	bool operator == (const EstradaNacional &e)const;
	bool operator > (const EstradaNacional &e)const;
	bool operator < (const EstradaNacional &e)const;
	//End Sobrecarga de Operadores
};

//C1
EstradaNacional::EstradaNacional(){
	tipoPavimento= "sem descrição";
}

//C2
EstradaNacional::EstradaNacional(const InteresseTuristico &o, const InteresseTuristico &d,string codVia, float totalkms, int tempMedio, string tPavimento):ViaLigacao(o,d,codVia,totalkms,tempMedio){
	tipoPavimento = tPavimento;
}

//C3
EstradaNacional::EstradaNacional(const EstradaNacional &e){
	setTipoPavimento(e.tipoPavimento);
}

//CDestrutor
EstradaNacional::~EstradaNacional(){
}

//G1
string EstradaNacional::getTipoPavimento() const {
	return tipoPavimento;
}

//S1
void EstradaNacional::setTipoPavimento(string tPavimento){
	tipoPavimento = tPavimento;
}

ViaLigacao* EstradaNacional::clone() const 
{
	return new EstradaNacional(*this);
}

void EstradaNacional::escreve(ostream &out) const{
	ViaLigacao::escreve(out);
	out << "Tipo de Pavimento: "<< tipoPavimento <<"." << endl;
}


#endif
