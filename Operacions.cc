/** @file Operacions.cc
    @brief Implementació de la classe Operacions
*/

#include "Operacions.hh"

Operacions::Operacions() {
}

Operacions::Operacions(string &nom, string &parametres, string &definicio) {
	ops[nom].param = parametres;
	ops[nom].def = definicio;
}

void Operacions::afegir_operacio(string &nom, string &parametres, string &definicio) {
	map<string,info>::iterator it = ops.find(nom);
	if (it==ops.end()) {
		ops[nom].param = parametres;
		ops[nom].def = definicio;
	}
}

void Operacions::modificar_operacio(string &nom, string &parametres, string &definicio) {
	map<string,info>::iterator it = ops.find(nom);
	if (it!=ops.end()) {
		ops[nom].param = parametres;
		ops[nom].def = definicio;
	}
}

bool Operacions::esta_definida(string& nom) {
	map<string,info>::iterator it = ops.find(nom);
	if (it!=ops.end()) return true;
	else return false;
}

int Operacions::num_param(string &nom) {
	int count=1;
	int tam = ops[nom].param.size();
	if (tam==0) count = 0;
	else {
		for (int i=0; i<tam; i++) {
			if (ops[nom].param[i] ==' ') count++;
		}
	}
	return count;
}

string Operacions::obtenir_def(string& nom) {
	return ops[nom].def;
}

string Operacions::obtenir_param(string& nom) {
	return ops[nom].param;
}

void Operacions::escriure_operacio(string &nom) {
	cout<<nom<<" "<<"#"<<num_param(nom)<<endl;
}

void Operacions::escriure_operacions() {
	map<string,info>::iterator it = ops.begin(); 
	while (it != ops.end()) {
		string nom = it -> first;
		escriure_operacio(nom);
		++it;
	}
}