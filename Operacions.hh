/** @file Operacions.hh
    @brief Especificació de la classe Operacions
*/

#ifndef OPERACIONS_HH
#define OPERACIONS_HH

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <list>
#include <iostream>
#endif

using namespace std;

/** @class Operacions
 *  @brief Representa una classe amb les operacions definides per l'usuari, emmagatzemades en un map
 */

class Operacions {

private:

	struct info {
		string param;
		string def;
	};

	map<string, info> ops;

public:

	//Constructores

	/** @brief Creadora per defecte

	 	S'executa automàticament al declarar Operacions
	 	\pre Cert
	 	\post Crea un on objecte amb map buit
	*/
	Operacions();

	/** @brief Creadora definida

	 	\pre nom, parametres i definicio són strings. nom no correspon a cap operació primitiva
	 	\post Crea un objecte amb un map, inicialitzat amb la clau nom, param parametres, i def definició
	*/
	Operacions(string &nom, string &parametres, string &definicio);

	//Modificadores

	/** @brief Afegeix una operació al P.I.

	\pre nom , parametres i definicio són strings. nom no correspon a cap operació primitiva,
		a cap operació definida al P.I., ni a cap variable definida
	\post Afegeix una operació al P.I., inicialitzada amb clau nom, param parametres i def definicio.
*/
	void afegir_operacio(string &nom, string &parametres, string &def);

	/** @brief Modifica una operació del P.I.

	\pre nom , parametres i definicio són strings. nom no correspon a cap operació primitiva,
	 	ni a cap variable definida, i nom correspon a una operació definida al P.I.
	\post Modifica l'operació amb clau nom del P.I., amb els nous parametres i definicio
*/
	void modificar_operacio(string &nom, string &parametres, string &def);

	// Consultores

	/** @brief Consulta si l'operació està definida al map.

	\pre nom és un string
	\post Retorna cert si existeix una operació amb clau nom al P.I. Retorna fals altrement
*/
	bool esta_definida(string &nom);

	/** @brief Comprova el número de paràmetres de l'operació definida

	\pre L'operació amb clau nom està definida
	\post Retorna el número de paràmetres de l'operació amb clau nom del P.I.
*/
	int num_param(string &nom);

	/** @brief Obté la definició de l'operació

	\pre L'operació amb clau nom està definida
	\post Retorna la definició de l'operació amb clau nom del P.I., en forma d'string
*/
	string obtenir_def(string& nom);

	/** @brief Obté els paràmetres de l'operació

	\pre L'operació amb clau nom està definida
	\post Retorna els paràmetres de l'operació amb clau nom del P.I., en formna d'string
*/
	string obtenir_param(string& nom);

	// Lectura i escriptura

	/** @brief Escriptura d'operació

	\pre L'operació amb clau nom està definida
	\post Escriu pel canal de sortida el nom de l'operació del P.I., seguit de "#" i el número de paràmetres de la operació
*/
	void escriure_operacio(string &nom);

	/** @brief Escriptura del map d'operacions

	\pre cert
	\post Escriu totes les operacions del map del P.I. pel canal de soritda.
	 	Escriu el nom de l'operació, seguit de "#" i el número de paràmetres d'aquesta operació
*/
	void escriure_operacions();

};

#endif //OPERACIONS_HH
