/**
 * @mainpage Calculadora d'expressions aritmètiques
 *
 *
 *La pràctica consta del programa principal, i les classes Avaluar, Resultat, Operacions, Variables i Resultat.
 *
 *Avaluar només té operacions públiques, cridades pel programa principal, i és on s'arregla, i s'avalua l'expressió rebuda.
 *
 *Resultat és la classe encarregada de representar els diferents resultats obtinguts de tractar les expressions.
 *
 *Variables i Operacions són dues classes encarregades d'emmagatzemar les variables i operacions que l'usuari defineix.
 *
 */

/** @file program.cc
    @brief Programa principal de la calculadora
*/

#include "Operacions.hh"
#include "Variables.hh"
#include "Resultat.hh"
#include "Avaluar.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#endif

/** @brief Programa principal de la calculadora
*/

using namespace std;

int main() {
	string s; 
	Operacions ops;
	Variables var;
	Resultat r;
	s = leer(); //llegeix tota la instruccio 
	s = treure_espais(s); // treu els espais de més en l'string s 
	while (s != "****") {
		if (define(s) and operacio(s)) {
			string nom;
			string vars;
			string expr;
			separar_operacions(s,nom, vars,expr);
			if (ops.esta_definida(nom)) {
				ops.modificar_operacio(nom,vars,expr);
			}
			else {
				ops.afegir_operacio(nom, vars,expr);
			}
			cout << nom << " #" << ops.num_param(nom)<<endl;
		}
		else if(define(s) and not operacio(s)) {  // not operacio -> variable (define x 10)
			string nom;
			string expr;
			separar_variables(s,nom,expr);
			if ((nom[0]>='a' and nom[0]<= 'z') or (nom[0]>='A' and nom[0]<= 'Z')) {
				r = Avaluem(expr, var, ops);
				if (var.esta_definida(nom) and r.ets_definit()) {
					var.modificar_variable(nom,r);
				}
				else if (r.ets_definit()) {
					var.afegir_variable(nom,r);
				}
				cout << nom << " ";
			}
			r.escriure();
		}
		else {
			if(not s.empty()){
			r = Avaluem(s, var, ops);
			r.escriure();
			}
		}
		r.clear();
		s.clear();
		s = leer();
		s = treure_espais(s);		
	}
	cout << "Variables:" << endl;
	var.escriure_variables();
	cout << "Operacions:" << endl;
	ops.escriure_operacions();
}
