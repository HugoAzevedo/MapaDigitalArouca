#ifndef TuristicoNaturais_
#define TuristicoNaturais_

#include "InteresseTuristico.h" //Include da superclasse INTERESSE TURISTICO

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std; // or using std::string;


class TuristicoNaturais: public InteresseTuristico
{

private:

	//Variaveis	
	double area;	//Em km^2
	//EndVariaveis

public:

	InteresseTuristico* clone() const ;

	//Construtores
	TuristicoNaturais();//C1
	TuristicoNaturais(string descr, double area);//C2
	TuristicoNaturais(const TuristicoNaturais &tn);//C3
	~TuristicoNaturais();//CDestrutor
	//EndConstrutores

	//Metodos Get
	double getArea() const; //G1	
	//End Metodos Get

	//Metodos Set
	void setArea(double area); //S1	
	//End Metodos Set

	//Metodos
	void TuristicoNaturais::escreve(ostream &out) const;
	//End Metodos

	//Sobrecarga de Operadores
	virtual TuristicoNaturais&operator = (const TuristicoNaturais &tn);
	bool operator == (const TuristicoNaturais &tn)const;
	bool operator > (const TuristicoNaturais &tn)const;
	bool operator < (const TuristicoNaturais &tn)const;
	//End Sobrecarga de Operadores

};

//C1
TuristicoNaturais::TuristicoNaturais(){

	area = 0;

}

//C2
TuristicoNaturais::TuristicoNaturais(string descr, double are):InteresseTuristico(descr){

	area = are;

}

//C3
TuristicoNaturais::TuristicoNaturais(const TuristicoNaturais &tn){

	setArea(tn.area);

}

//CDestrutor
TuristicoNaturais::~TuristicoNaturais(){
}

//G1
double TuristicoNaturais::getArea() const{
	return area;
}

//S1
void TuristicoNaturais::setArea(double ar){
	area = ar;	
}

//Sobrecarga de operadores
TuristicoNaturais &TuristicoNaturais:: operator = (const TuristicoNaturais &tn){
	if (this != &tn){
		setArea(tn.area);		
	}
	return *this;
}

bool TuristicoNaturais::operator == (const TuristicoNaturais &tn)const{
	if (area == tn.area)
		return true;
	else
		return false;
}

bool TuristicoNaturais::operator > (const TuristicoNaturais &tn)const{	
	return (area > tn.area);//Verificar
}

//bool TuristicoNaturais::operator < (const TuristicoNaturais &tn)const{	
//}
//End Sobrecarga de operadores

InteresseTuristico* TuristicoNaturais::clone() const 
{
	return new TuristicoNaturais(*this);
}

void TuristicoNaturais::escreve(ostream &out) const{
	InteresseTuristico::escreve(out);
	out << "Area: "<< area <<"." << endl;
}


#endif