#ifndef ViaLigacao_
#define ViaLigacao_

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include "InteresseTuristico.h"

using namespace std;

class ViaLigacao
{

private:

	string codVia;
	float totalKms;
	int tempMed;
	InteresseTuristico origem;
	InteresseTuristico destino;

	//Inserir Vias
	int dimensao;
	int atual;
	ViaLigacao * * vecVia; //vetor dinamico
	// End Inserir Vias

public:

	//Construtores
	ViaLigacao(); //C1
	ViaLigacao(const InteresseTuristico &o, const InteresseTuristico &d,string cdvia, float tkms, int tMed);//C2
	ViaLigacao(const ViaLigacao &v);//C3
	virtual ~ViaLigacao();//CDestrutor
	//EndConstrutores

	//Metodos Get
	string getCodVia() const;//G1
	float getTotalKms() const;//G2
	int getTempMed() const;//G3
	//End Metodos Get

	//Metodos Set
	void setCodVia(string codigo);//S1
	void setTotalKms(float total);//S2
	void setTempMed(int tempo);//S3
	//End Metodos Set

	//Metodos 
	virtual void escreve(ostream &out) const;
	virtual ViaLigacao * clone() const = 0; //funcao virtual pura *Usada TP1*
	virtual void inserirVias(ViaLigacao * vias); //Metodo para inserir vias de ligação (Pedido- 2)
	//virtual void contabilizarVias() const; //Metodo para contabilizar vias de ligação (Pedido- 3)
	//virtual void contabilizarVias(const char *c) const; //Metodo para contabilizar vias de ligação (Pedido- 3)
	//End Metodos 

	//Sobrecarga de Operadores
	virtual ViaLigacao &operator = (const ViaLigacao &v);
	bool operator == (const ViaLigacao &v)const;
	bool operator > (const ViaLigacao &v)const;
	bool operator < (const ViaLigacao &v)const;
	bool operator << (const ViaLigacao &v)const;
	//End Sobrecarga de Operadores

};

//C1
ViaLigacao::ViaLigacao(){
	codVia= "";
	totalKms= 0;
	tempMed= 0;
}

//C2
ViaLigacao::ViaLigacao(const InteresseTuristico &o, const InteresseTuristico &d,string cdvia, float tkms, int tMed) : origem(o), destino(d){
	codVia= cdvia;
	totalKms= tkms;
	tempMed= tMed;
}

//C3
ViaLigacao::ViaLigacao(const ViaLigacao &v){
	setCodVia(v.codVia);
	setTotalKms(v.totalKms);
	setTempMed(v.tempMed);
}

//CDestrutor
ViaLigacao::~ViaLigacao(){
}

//G1
string ViaLigacao::getCodVia() const{
	return codVia;
}

//G2
float ViaLigacao::getTotalKms() const{
	return totalKms;
}

//G3
int ViaLigacao::getTempMed() const{
	return tempMed;
}

//S1
void ViaLigacao::setCodVia(string codigo){
	codVia = codigo;
}

//S2
void ViaLigacao::setTotalKms(float total){
	totalKms = total;
}

//S3
void ViaLigacao::setTempMed(int tempo){
	tempMed = tempo;
}

//Sobrecarga de operadores
ViaLigacao &ViaLigacao:: operator = (const ViaLigacao &v){
	if (this != &v){
		setCodVia(v.codVia);
		setTotalKms(v.totalKms);
		setTempMed(v.tempMed);
	}
	return *this;
}

bool ViaLigacao::operator == (const ViaLigacao &v)const{
	if (codVia == v.codVia && totalKms == v.totalKms && tempMed == v.tempMed)
		return true;
	else
		return false;
}

bool ViaLigacao::operator > (const ViaLigacao &v)const{	
	return (totalKms > v.totalKms);//Verificar
}
//
//bool ViaLigacao::operator < (const ViaLigacao &v)const{	
//}
ostream& operator << (ostream &out, const ViaLigacao &v){
	v.escreve(out);
	return out;
}
//End Sobrecarga de operadores

//Metodo para inserir vias de ligação (Pedido- 2)
void ViaLigacao:: inserirVias(ViaLigacao *vias){
	if(atual == dimensao){
		ViaLigacao * * vecViaTemp; //vetor temporário
		vecViaTemp = new ViaLigacao * [2*dimensao];

		for (int i = 0; i < dimensao; i++)
		{
			vecViaTemp[i] = vecVia[i];
		}
		dimensao = 2*dimensao;//**Verificar se está correto**//
		delete[] vecVia;
		vecVia = vecViaTemp;
	}
	vecVia[atual] = vias->clone();
	atual++;
}
//End Metodo para inserir vias de ligação (Pedido- 2)

//Metodo para contabilizar vias de ligação (Pedido- 3)
//void ViaLigacao::contabilizarVias(const char *c) const{
//	int numEstradasNacionais = 0;
//	int numAutoEstradas = 0;
//
//	for (int i =0; i<atual;i++){
//
//		if(typeid(* vecVia[i]) == typeid(EstradaNacional)) 
//			numEstradasNacionais++;
//
//		if (typeid(* vecVia[i]) == typeid(AutoEstrada))
//			numAutoEstradas++;
//	}
//	//A impressão feita diretamente na classe *ou* poderia ser feita no cpp através do return do num de Estradas e AutoEstradas
//	cout << "Total Vias de Ligação ► Resultado: " << endl;
//	cout << "-----Nº de Vias de Ligação de Estradas Nacionais: " << numEstradasNacionais << "." << endl;
//	cout << "-----Nº de Vias de Ligação de Auto - Estradas: " << numAutoEstradas << "." << endl;
//}
//End Metodo para contabilizar vias de ligação (Pedido- 3)

//Metodo Escreve *****Verificar/N está como pedido*****
void ViaLigacao::escreve(ostream &out) const{
	out << "Local Origem: " << origem.getDesc() << endl;
	out << "Local Destino: " << destino.getDesc() << endl;
	out << "Codigo da Via: " << codVia <<endl;
	out << "Total de Kilometros: " << totalKms << "Km"<< endl; 
	out<< "Tempo Medio: " << tempMed << " Minutos" <<endl; // Em minutos
}
//End Escreve 


#endif

