#ifndef InteresseTuristico_
#define InteresseTuristico_

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std; // or using std::string;


class InteresseTuristico{

private:

	//Variaveis	
	string descricao;
	//EndVariaveis

	//Contentor:
	int actual;
	InteresseTuristico **vec;

public:

	//Construtores
	InteresseTuristico();//C1
	InteresseTuristico(string descricao);//C2
	InteresseTuristico(const InteresseTuristico &it);//C3
	virtual ~InteresseTuristico();//CDestrutor
	//EndConstrutores

	//Metodos Get
	string getDesc() const;//G1
	int getActual() const;//G2
	//End Metodos Get

	//Metodos Set
	void setDesc(string desc);//S1
	void setActual(int act);//S2	
	//End Metodos Set

	//Metodos 

	virtual void escreve(ostream &out) const;
	InteresseTuristico * clone() const;
	virtual void inserirLocaisIntTur(InteresseTuristico * locais); //Metodo para inserir locais de interesse turistico (Pedido- 2)
	virtual void contarLocaisIntTur() const; //Metodo para contabilizar os locais de interesse turistico (Pedido- 3)
	
	//End Metodos

	//Sobrecarga de Operadores
	virtual InteresseTuristico &operator = (const InteresseTuristico &it);
	bool operator == (const InteresseTuristico &it)const;
	bool operator > (const InteresseTuristico &it)const;
	//bool operator < (const InteresseTuristico &it)const;
	bool operator << (const InteresseTuristico &it)const;
	//End Sobrecarga de Operadores

};

//C1
InteresseTuristico::InteresseTuristico(){

	descricao = "Nenhuma";
}

//C2
InteresseTuristico::InteresseTuristico(string desc){

	descricao = desc;
}

//C3
InteresseTuristico::InteresseTuristico(const InteresseTuristico &it){

	setDesc(it.descricao);
}

//CDestrutor
InteresseTuristico::~InteresseTuristico(){
}

//G1
string InteresseTuristico::getDesc() const{
	return descricao;
}

void InteresseTuristico::setDesc(string desc){
	descricao = desc;
}

//Sobrecarga de operadores
InteresseTuristico &InteresseTuristico:: operator = (const InteresseTuristico &it){
	if (this != &it){
		setDesc(it.descricao);		
	}
	return *this;
}

bool InteresseTuristico::operator == (const InteresseTuristico &it)const{
	if (descricao == it.descricao)
		return true;
	else
		return false;
}

//bool InteresseTuristico::operator > (const InteresseTuristico &it)const{	
//
//}
//
//bool InteresseTuristico::operator < (const InteresseTuristico &it)const{	
//}

ostream& operator << (ostream &out, const InteresseTuristico &it){
	it.escreve(out);
	return out;
}
//End Sobrecarga de operadores

//Metodo para contabilizar vias de ligação (Pedido- 3)
void InteresseTuristico::contarLocaisIntTur() const
{
	int historicos = 0;
	int naturais = 0;

	for (int i=0; i<actual; i++)
	{
		if (typeid(*(vec[i])) == typeid(TuristicoNaturais)) historicos++;
		if (typeid(*(vec[i])) == typeid(Turistico_Hist_Cult)) naturais++;
	}
	
	cout << "Total de Locais" << endl;
	cout << "::::::::::Locais Naturais: " << historicos << " vias." << endl;
	cout << "::::::::::Locais Historicos Naturais: " << naturais << " vias." << endl;
}

//Metodo Escreve *****Verificar/N está como pedido*****
void InteresseTuristico::escreve(ostream &out) const{
	out << "Descricao: " << descricao <<endl;
}
//End Escreve 


#endif