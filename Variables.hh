/** @file Variables.hh
    @brief Especificació de la classe Variables
*/

#ifndef VARIABLES_HH
#define VARIABLES_HH

#include "Resultat.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <iostream>
#endif

using namespace std;

/** @class Variables
 *  @brief Representa una classe amb les variables definides per l'usuari, emmagatzemades en un map
 */

class Variables {

private:

	map<string,Resultat> vars;

public:

	//Constructores

	/** @brief Creadora per defecte

 		S'executa automàticament al declarar Variables
 		\pre Cert
 		\post Crea un on objecte amb map buit
*/
	Variables();

	/** @brief Creadora definida

 		\pre nom és un string, res és un Resultat. nom no correspon a cap operació primitiva ni definida del P.I.
	 	\post Crea un objecte amb un map, inicialitzat amb clau nom, Resultat res
*/
	Variables(string &nom, Resultat &res);

	//Modificadores

	/** @brief Afegeix una variable al P.I.

		\pre nom és un string, Res és un resultat, nom no correspon a cap operació primitiva ni definida del P.I.
		ni a cap variable definida al P.I.
		\post Afegeix al map una variable amb clau nom, i Resultat res.
*/
	void afegir_variable(string &nom, Resultat &res);

	/** @brief Modifica una variable del P.I.

		\pre nom és un string, Res és un resultat, nom no correspon a cap operació primitiva ni definida del P.I.,
			nom correspon a una variable definida al P.I.
		\post Modifica la variable amb clau nom del P.I. amb el nou Resultat res
*/
	void modificar_variable(string &nom, Resultat &res);

	// Consultores

	/** @brief Consulta si la variable està definida al map

		\pre nom és un string
		\post Retorna cert si existeix una variable amb clau nom al map del P.I., i fals altrement
*/
	bool esta_definida(string &nom);

	/** @brief Obté el Resultat de la variable

		\pre nom és un string
		\post Retorna el Resultat corresponent a la  clau nom del P.I.
*/
	Resultat obtenir_resultat(string& nom);

	// Lectura i escriptura

	/** @brief Escriptura de variable

		\pre nom és un string
		\post Escriu pel canal estàndar de sortida el nom de la variable del P.I.,
 			seguit del seu Resultat corresponent en forma d'enter o llista d'enters
*/
	void escriure_variable(string &nom);
	/** @brief Escriptura del map de variables

		\pre nom és un string
		\post Escriu pel canal estàndar totes les variables del P.I.
			Escriu el nom de variable, seguit del seu Resultat corresponent en forma d'enter o llista d'enters
*/
	void escriure_variables();

};


#endif //VARIABLES_HH
