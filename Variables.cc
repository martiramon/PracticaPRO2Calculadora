/** @file Variables.cc
    @brief Implementació de la classe Variables
*/

#include "Variables.hh"

Variables::Variables() {
}

Variables::Variables(string &nom, Resultat &res) {
	vars[nom] = res;
}

void Variables::afegir_variable(string &nom, Resultat &res) {
	map<string,Resultat>::iterator it = vars.find(nom);
	if (it==vars.end()) {
		vars[nom] = res;
	}
}

void Variables::modificar_variable(string &nom, Resultat &res) {
	map<string,Resultat>::iterator it = vars.find(nom);
	if (it!=vars.end()) vars[nom] = res;
}

bool Variables::esta_definida(string &nom) {
	map<string,Resultat>::iterator it = vars.find(nom);
	if (it!=vars.end()) {
		return true;
	}
	return false;
}

void Variables::escriure_variable(string &nom) {
	Resultat r;
	cout << nom << " " << r.obtenir_enter() << endl;
}

Resultat Variables::obtenir_resultat(string& nom) {
	return vars[nom];
}

void Variables::escriure_variables() {
	map<string,Resultat>::iterator it = vars.begin(); 
	while (it != vars.end()) {
		cout << it ->first  <<" ";
		it -> second.escriure();
		++it;
	}  
}

