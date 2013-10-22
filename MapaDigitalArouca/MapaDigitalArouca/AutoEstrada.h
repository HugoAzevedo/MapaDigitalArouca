#ifndef AutoEstrada_
#define AutoEstrada_

#include <stdio.h>
#include <string.h>
using namespace std;
#include "ViaLigacao.h"//Classe principal(Mãe)

class AutoEstrada : public ViaLigacao
{

private:
	double precoPortagem;

public:

	ViaLigacao* clone() const ;//Testar Metodo Virtual Puro ****** Verificar********

	//Construtores 
	AutoEstrada();//C1
	AutoEstrada(const InteresseTuristico &o, const InteresseTuristico &d, string codVia, float totalkms, int tempMedio, double pPortagem);//C2
	AutoEstrada(const AutoEstrada &a);//C3
	~AutoEstrada();//CDestrutor
	//End Construtores

	//Metodo Get
	double getPrecoPortagem() const;//G1
	//End Metodo Get

	//Metodo Set
	void setPrecoPortagem(double pPortagem);//S1
	//End Metodos Set

	void AutoEstrada::escreve(ostream &out) const;

	//Sobrecarga de Operadores
	AutoEstrada & operator = (const AutoEstrada &a);
	bool operator == (const AutoEstrada &a)const;
	bool operator > (const AutoEstrada &a)const;
	bool operator < (const AutoEstrada &a)const;
	//End Sobrecarga de Operadores
};

//C1
AutoEstrada::AutoEstrada(){
	precoPortagem= 0;//sem valor, valor por omissão, construtor vazio
}

//C2
AutoEstrada::AutoEstrada(const InteresseTuristico &o, const InteresseTuristico &d,string codVia, float totalkms, int tempMedio, double pPortagem):ViaLigacao(o,d,codVia,totalkms,tempMedio){
	precoPortagem = pPortagem;
}

//C3
AutoEstrada::AutoEstrada(const AutoEstrada &a){
	setPrecoPortagem(a.precoPortagem);
}

//CDestrutor
AutoEstrada::~AutoEstrada(){
}

//G1
double AutoEstrada::getPrecoPortagem() const {
	return precoPortagem;
}

//S1
void AutoEstrada::setPrecoPortagem(double pPortagem){
	precoPortagem = pPortagem;
}

ViaLigacao* AutoEstrada::clone() const 
{
	return new AutoEstrada(*this);
}

void AutoEstrada::escreve(ostream &out) const{
	ViaLigacao::escreve(out);
	out << "Preco de portagem: "<< precoPortagem <<" Euros" << endl;
}

#endif