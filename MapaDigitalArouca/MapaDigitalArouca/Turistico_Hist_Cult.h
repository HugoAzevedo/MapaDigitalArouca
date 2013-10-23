#ifndef Turistico_Hist_Cult_
#define Turistico_Hist_Cult_

#include "InteresseTuristico.h" //Include da superclasse INTERESSE TURISTICO

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std; // or using std::string;


class Turistico_Hist_Cult: public InteresseTuristico
{

private:

	//Variaveis	
	float tempomedio;
	float hr_abertura;
	float hr_encerramento;
	//EndVariaveis

public:

	InteresseTuristico* clone() const ;

	//Construtores
	Turistico_Hist_Cult();//C1
	Turistico_Hist_Cult(string descr, float tempmed, float hr_abert, float hr_encerr);//C2
	Turistico_Hist_Cult(const Turistico_Hist_Cult &hc);//C3
	~Turistico_Hist_Cult();//CDestrutor
	//EndConstrutores

	//Metodos Get
	float getTempo() const; //G1
	float getHra() const; //G2
	float getHrc() const; //G3
	//End Metodos Get

	//Metodos Set
	void setTempo(float tempmed);
	void setHra(float hra);
	void setHrc(float hrc);
	//End Metodos Set

	//Metodos
	void Turistico_Hist_Cult::escreve(ostream &out) const;
	//End Metodos

	//Sobrecarga de Operadores
	virtual Turistico_Hist_Cult &operator = (const Turistico_Hist_Cult &hc);
	bool operator == (const Turistico_Hist_Cult &hc)const;
	bool operator > (const Turistico_Hist_Cult &hc)const;
	bool operator < (const Turistico_Hist_Cult &hc)const;
	//End Sobrecarga de Operadores

};

//C1
Turistico_Hist_Cult::Turistico_Hist_Cult(){

	tempomedio = 0.0f;
	hr_abertura = 0.0f;
	hr_encerramento = 0.0f;

}

//C2
Turistico_Hist_Cult::Turistico_Hist_Cult(string descr, float tempmed, float hr_abert, float hr_encerr):InteresseTuristico(descr){

	tempomedio =  tempmed;
	hr_abertura = hr_abert;
	hr_encerramento = hr_encerr;

}

//C3
Turistico_Hist_Cult::Turistico_Hist_Cult(const Turistico_Hist_Cult &hc){

	setTempo(hc.tempomedio);
	setHra(hc.hr_abertura);
	setHrc(hc.hr_encerramento);

}

//CDestrutor
Turistico_Hist_Cult::~Turistico_Hist_Cult(){
}

//G1
float Turistico_Hist_Cult::getTempo() const{
	return tempomedio;
}

//G2
float Turistico_Hist_Cult::getHra() const{
	return hr_abertura;
}

//G3
float Turistico_Hist_Cult::getHrc() const{
	return hr_encerramento;
}

//S1
void Turistico_Hist_Cult::setTempo(float tempme){
	tempomedio = tempme;	
}

//S2
void Turistico_Hist_Cult::setHra(float hra ){
	hr_abertura = hra;	
}

//S3
void Turistico_Hist_Cult::setHrc(float hrc ){
	hr_encerramento	= hrc;
}

//Sobrecarga de operadores
Turistico_Hist_Cult &Turistico_Hist_Cult:: operator = (const Turistico_Hist_Cult &hc){
	if (this != &hc){
		setTempo(hc.tempomedio);
		setHra(hc.hr_abertura);
		setHrc(hc.hr_encerramento);
	}
	return *this;
}

bool Turistico_Hist_Cult::operator == (const Turistico_Hist_Cult &hc)const{
	if (tempomedio == hc.tempomedio && hr_abertura == hc.hr_abertura && hr_encerramento == hc.hr_encerramento)
		return true;
	else
		return false;
}

bool Turistico_Hist_Cult::operator > (const Turistico_Hist_Cult &hc)const{	
	return (tempomedio > hc.tempomedio);//Verificar
}

//bool Turistico_Hist_Cult::operator < (const Turistico_Hist_Cult &hc)const{	
//}

//End Sobrecarga de operadores

InteresseTuristico* Turistico_Hist_Cult::clone() const 
{
	return new Turistico_Hist_Cult(*this);
}

void Turistico_Hist_Cult::escreve(ostream &out) const{
	InteresseTuristico::escreve(out);
	out << "Tempo Medio: "<< tempomedio <<"." << endl;
	out << "Hora de Abertura: "<< hr_abertura <<"." << endl;
	out << "Hora de Encerramento: "<< hr_encerramento <<"." << endl;
}

#endif