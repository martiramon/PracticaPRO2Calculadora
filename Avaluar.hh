/** @file Avaluar.hh
    @brief Especificació de la classe Avaluar
*/

#ifndef Avaluar_HH
#define Avaluar_HH

#include "Operacions.hh"
#include "Variables.hh"
#include "Resultat.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <map>
#endif

using namespace std;

/** @class Avaluar
 *  @brief Representa una classe amb funcions per avaluar i realitzar les operacions
 */

	/** @brief Consulta si al string s hi ha un define.

	\pre El string s és no buit.
	\post Retorna cert si s conté define just despres del primer parèntesis i fals altrament.
*/
	bool define(const string &s);


	/** @brief Consulta si al string s és de tipus operació o variable.

	\pre El string s és no buit.
	\post Retorna cert si s és una operació i fals si és variable.
*/
	bool operacio(const string &s);


	/** @brief Separa el string s en un de nom, vars i expressió.

	\pre El string s és no buit.
	\post El string nom conté el nom de l'operació, vars conté els paràmetres de l'operació i expr
	conté la expressió de l'operació.
*/
	void separar_operacions(const string &s,string &nom, string &vars, string &expr);


	/** @brief Separa el string s en un de nom i expressió.

	\pre El string s és no buit.
	\post El string nom conté el nom de la variable i expr conté la expressió.
*/
	void separar_variables(const string &s,string &nom, string &expr);


	/** @brief Donat un string s amb múltiples espais seguits es capaç de suprimir-los i quedar-se amb un únic espai.

	\pre s és un string no buit.
	\post Retorna el string s amb els espais adequats amb el string subs, i apunta a la posició on s'ha quedat el string s
	per poder rependre la extracció posteriorment des del punt on s'havia quedat.
*/
	string treure_espais(const string &s);


	/** @brief Permet llegir una expressió.

	\pre Cert.
	\post Retorna un string de tota la instrucció llegida fins al final sense la reducció dels espais.
*/
	string leer();


        /** @brief Donat un string s amb múltiples expressions retorna una expressió més petita.

	\pre s és un string no buit.
	\post Retorna una expressió del string s més petita a través del string subs.
*/
	void extraer(string &s, int &i, string &subs);


	/** @brief Donat un string s amb múltiples expressions retorna cada una de les expressons a través d'un vector de strings.

	\pre s és un string no buit.
	\post Retorna un vector de strings on a cada posició s'ha guardat la expressió corresponent al retorn de la funció
	extraer.
*/
	vector<string> extraer_todos(string &s);

	/** @brief Consulta si el string s conté únicament un enter o una llista.

	\pre El string s és no buit.
	\post Retorna cert si el string s conté únicament un enter, fals si és llista.

*/
	bool es_enter(const string &s);

	/** @brief Retorna un resultat avaluat.

	\pre El string s és no buit.
	\post Retorna el resultat de primitives, operacions i variables.
*/
	Resultat Avaluem(string& s, Variables& var, Operacions &op);


#endif
