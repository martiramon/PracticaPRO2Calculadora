/** @file Resultat.hh
    @brief Especificació de la classe Resultat
*/

#ifndef Resultat_HH
#define Resultat_HH

#include "Resultat.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <stdlib.h>
#include <list>
#include <string>
#endif

using namespace std;

/** @class Resultat
 	@brief Classe per representar els resultats obtinguts per la calculadora
 */

class Resultat {

private:

	bool definit;
	bool enter;
	list<int> val;
	
public:

	//Constructores
	/** @brief Creadora per defecte

	  	S'executa automàticament al declarar un resultat
	  	\pre Cert
	  	\post Crea un resultat no definit, no enter, i amb llista val buida
	 */
	Resultat();

	/** @brief Creadora de Resultat enter expressat en un string

	 	\pre  s és un string d'un número enter
	  	\post Crea un resultat definit, enter, i amb llista val amb l'enter de l'string s
	 */
	void Resultat_enter(const string& s);

	/** @brief Creadora de Resultat enter expressat en un enter

 		\pre  e és un enter
  		\post Crea un resultat definit, enter, i amb llista val amb l'enter e
 */
	void crear_res_ent(int e);

	/** @brief Creadora de Resultat llista buida

 		\pre  Cert
 		\post Crea un resultat definit, no enter, i amb llista val buida
*/
	void crear_list();

	/** @brief Creadora de Resultat comparació igualtat de dos Resultats

		\pre  r1 i r2 són Resultats creats
 		\post Crea un objecte Resultat definit, enter, i com a únic element
	  		de llista val, 1 si r1 i r2 són iguals, 0 altrement
*/
	void fer_igual(Resultat& r1, Resultat& r2);

	/** @brief Creadora de Resultat comparació inferioritat de dos Resultats

 		\pre  r1 i r2 són Resultats creats
  		\post Crea un objecte resultat definit, enter i com a únic element
	 		de llista val, 1 si r1<r2, 0 altrement
 */
	void fer_inferior(Resultat& r1, Resultat& r2);

	//Consultores

	/** @brief Consulta si el resultat és un enter

 		\pre  Cert
 		\post Retorna true si el P.I. és un enter, false altrement
 */
	bool ets_enter();

	/** @brief Consulta si el resultat éstà definit

 		\pre  Cert
 		\post Retorna true si el P.I. està definit, false altrement
*/
	bool ets_definit();

	/** @brief Obté el resultat enter

 		\pre  El resultat és enter, i té una llista val amb un sol enter
  		\post Retorna l'enter de la llista val del P.I.
 */
	int obtenir_enter();

	/** @brief Consulta si el resultat és una llista buida

  		\pre  Cert
 		\post Retorna true si el P.I. no és enter i llista val està buida. False altrement
 */
	bool llista_buida();

	//Modificadores

	/** @brief Neteja el Resultat

		\pre  El P.I. no està buit
		\post Neteja el P.I., deixant definit false, enter false, i llista val buida
*/
	void clear();

	/** @brief Afegeix un enter al final de P.I.

  		\pre  e és un enter
  		\post Afegeix un enter e al final de llista val del P.I., enter passa a ser fals
 */
	void afegir_enter(int e);

	/** @brief Afegeix un enter al principi de P.I.

 		\pre  e és un enter
 		\post Afegeix un enter e al principi de la llista val del P.I., enter passa a ser fals
*/
	void afegir_principi(int e);

	/** @brief Modifica si el Resultat està definit

 		\pre  b és un booleà
  		\post Canvia el P.I. definit per b
 */
	void modificar_definit(bool b);

	/** @brief Elimina el primer enter del P.I.

		\pre  Cert
 		\post Elimina el primer element de la llista val del P.I.
*/
	void eliminar_front();

	//Escriptura

	/** @brief Operació d'escriptura

		\pre  Cert
 		\post Escriu el Resultat pel canal estàndar de sortida.
	 		Si el resultat és enter, en forma d'enter. Si no és enter, en forma de llista d'enters.
	  		Si no està definit, escriu "indefinit"
*/
	void escriure();

};
#endif 
