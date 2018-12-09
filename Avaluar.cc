/** @file Avaluar.cc
    @brief Implementació de la classe Avaluar
*/

#include "Avaluar.hh"

void extraer(string &s, int &i, string &subs) {
	int n = s.size();
	while (i < n and s[i] == ' ') ++i;
	if (s[0] == '(' and i == 0) ++i;
	if (s[i] == '(') {
		bool trobat = false;
		int cont_par = 1;
		while (cont_par != 0 and i < n) {
			subs.push_back(s[i]);
			if (s[i] == '(' and trobat == true) ++cont_par;
			else if(s[i] == ')') --cont_par;
			trobat = true;
			++i;
		}
	}
	else {
		while (i < n and s[i] != ' ' and s[i] != ')') {
			subs.push_back(s[i]); 
			++i;
	}
	}
	++i;
}

//retorna si hi ha un define a la frase
bool define(const string &s) {
	if (not s.empty()) {
		if (s[1] == 'd' and s[2] == 'e' and s[3] == 'f' and s[4] == 'i' and s[5] == 'n' and s[6] == 'e') return true;
	}
	return false;
}

//retorna si es una operacio(cert) o assignacio (false)
bool operacio(const string &s) {
		string nom, vars, expr;
		separar_operacions(s,nom,vars,expr);
	int cont_par = 0;
	int cont = 0;  //contem quants cops tenim "(", si son 3 voldra dir que es una definicio
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') ++cont_par;
		else if (s[i] == ')') --cont_par;
		if (((s[i] == '(' or s[i] == ')')) and cont_par == 1) ++cont; // nomes ho tenim en compte quan estem en parentesis 
			//ja que sino, en molts chars el nombre de parentesis no varia i el contador aniria pujant tot el rato  
	}
	if  (cont == 3 or (vars.empty() and not expr.empty())) return true;
		else return false;
}

void separar_operacions(const string &s,string &nom, string &vars, string &expr) {
	//si estem aqui significa que definicio == 1 and operacio == 1
	bool trobat = false;
	int i = 8;// int i = 8 -> apartir del (define ....)
	while (i < s.size() and not trobat) {  //copiem el nom de la nova operacio al string nom
		if (s[i] == '(' or s[i] == ' ') trobat = true;
		else nom.push_back(s[i]);
		++i;
	}
	while (s[i] == ' ' or s[i] == '(') ++i;
	//sortim del bucle amb i apuntant despres del segon parentesis, es a dir, a les variables
		trobat = false;
		while(i < s.size() and not trobat) {
			if (s[i] == ')') trobat = true;
			else vars.push_back(s[i]);    //copiem les variables al string vars
			++i;
		}
		if (s[s.size()-2] != ')') { //l'expressió no està entre parèntesis, és un enter
				i = i + 1; 
				while (i < s.size() - 1) {  // el menys dos es per no copiar l'ultim
					// parentesis que tanca que correspon al del define          
					if (s[i] != ' ' or s[i + 1] != ')') expr.push_back(s[i]);
					++i;
				}
		}
		else {
				i = i + 2; // no copiem el primer parentesis de l'expressio
				while (i < s.size() - 2) {  // el menys dos es per no copiar l'ultim
					// parentesis que tanca que correspon al del define
					// i el que no copiem abans d'entrar aquest bucle
					if (s[i] != ' ' or s[i + 1] != ')') expr.push_back(s[i]);
					++i;
				}
		}

}  

void separar_variables(const string &s,string &nom, string &expr) {	
	int i = 8;  // "(define "
	bool trobat = false;
	while (i < s.size() -1 and not trobat) {
		if (s[i] == ' ') trobat = true;
		else {
			nom.push_back(s[i]);
		}
		++i;
	}	
	while (i < s.size() - 1) {
		expr.push_back(s[i]);
		++i;
	}	
}

string treure_espais(const string &s) {
		string ayudame;
		bool b = false;
		if(s.size() != 0) {
			int i = 0;
			while (i < s.size() -1) {
				if (s[i] != ' ') {
					ayudame.push_back(s[i]);
					b = false;
				}
				else if (s[i] == ' ' and not b and s[i + 1] != ' ' and s[i + 1] != ')')  {  // not b -> la posicio anterior era diferent d'espai
					b = true;
					ayudame.push_back(s[i]);
				}
			++i;
		};
		if (s[s.size() - 1] != ' ') ayudame.push_back(s[i]);  // afegir parentesis
	}
	return ayudame;
}

string leer() {
	int cont_par = 0;
	int i = 1;
	string s;
	getline(cin,s);
	if (not s.empty() and s[0] == '(') {
		++cont_par;
		while (cont_par != 0) {
			for (i = 1; i < s.length(); ++i) {	
				if(s[i] == '(') ++cont_par;
				else if (s[i] == ')') --cont_par;
			}
			if (cont_par != 0) {
				cont_par = 1;
				string aux;
				getline(cin,aux);
				s.append(" ");
				s.append(aux);
			}
		}
	}
	return s;
}

vector<string> extraer_todos(string &s) {
	int k = 0;
	string aux;
	vector<string> v;
	while (k < s.size()) {
		extraer(s, k, aux);
		v.push_back(aux);
		aux.clear();
	}
	return v;
}

bool es_enter(const string &s) {
	return (s[0] == '-' and s.size() != 1) or (s[0] >= '0' and s[0] <= '9');
}


Resultat Avaluem(string& s, Variables& var, Operacions& op) {
	Resultat r;    
	if (es_enter(s)) {
	r.Resultat_enter(s);
	}
	else if ((s[0]=='(' and s[1]==')') or (s[0]=='(' and s[1]==' ' and s[2]==')')) {
		r.crear_list();
	}
	else {
		vector<string> params = extraer_todos(s);
		bool l = (s[0] == '(' and s[s.size()-1] == ')');
		bool has_only_digits = params[0].find_first_not_of( "(-0123456789" ); //Ho necessitare per saber si entro al bucle de ops i vars
		if (params[0] == "+") { 
			Resultat r1,r2;
			if (params.size() == 3) {
				r1 = Avaluem(params[1], var, op);
				if (r1.ets_definit() and r1.ets_enter()) {
					r2 = Avaluem(params[2], var, op);
					if (r2.ets_definit() and r2.ets_enter()) {
						int e, e1, e2;
						e1 = r1.obtenir_enter();
						e2 = r2.obtenir_enter();
						e = e1+e2;
						r.crear_res_ent(e);
					}
				}
			}
		}
		else if(params[0] == "-") { 
			if (params.size() == 2) {
				Resultat r1;
				if (not params[1].empty()) {	
					r1 = Avaluem(params[1], var, op);
					if (r1.ets_definit() and r1.ets_enter()) {
						int e,e1;
						e1 = r1.obtenir_enter();
						e = -e1;
						r.crear_res_ent(e);
					}
				}
			}
		}
		else if (params[0] == "cons") { 
			if (params.size() == 3) {
				Resultat r1, r2;
				int e;
				r1 = Avaluem(params[1], var, op);
				if (r1.ets_definit() and r1.ets_enter()) {
					r2 = Avaluem(params[2], var, op);
					if (r2.ets_definit() and not r2.ets_enter()) {
						e = r1.obtenir_enter();
						r2.afegir_principi(e);
						r = r2;
					}
				}
			}	
		}
		else if (params[0] == "head") { 
			if (params.size() == 2) {
				Resultat r1;
				if (not params[1].empty()) {
					r1 = Avaluem(params[1], var, op);
					if (r1.ets_definit() and not r1.ets_enter() and not r1.llista_buida()) {
					int e = r1.obtenir_enter();
					r.crear_res_ent(e);
					}
				}
			}
		}
		else if (params[0] == "tail") {
				if (params.size() == 2) {
					Resultat r1,r2;
					if (not params[1].empty() and params[1] != "()") {
						r2 = Avaluem(params[1], var, op);
						if (r2.ets_definit() and not r2.ets_enter() and not r2.llista_buida()) {
							r2.eliminar_front();
							r = r2;
						}
					}
				}
		}
		else if (params[0] == "=") {
			if (params.size() == 3) {
				Resultat r, r1, r2;
				r1 = Avaluem(params[1], var, op);
				r2 = Avaluem(params[2], var, op);
				r.fer_igual(r1,r2);					
				return r;					
			}			
		}
		else if (params[0] == "<") {
			if (params.size() == 3) {
				Resultat r,r1,r2;
				r1 = Avaluem(params[1],var, op);
				r2 = Avaluem(params[2], var, op);
				r.fer_inferior(r1,r2);				  
				return r;			  
			}
		}
		else if (params[0] == "not") {
			if (params.size() == 2) {
				Resultat r1;
				int e, e1;
				if (not params[1].empty()) {
					r1 = Avaluem(params[1], var, op);
					if (r1.ets_definit() and r1.ets_enter()) {
						e1 = r1.obtenir_enter();
						if (e1 == 0) {
							e = 1;
							r.crear_res_ent(e);
						}
						else if (e1 == 1) {
							e = 0;
							r.crear_res_ent(e);
							return r;
						}
					}
				}
			}
		}
		else if (params[0] == "and") {
			if (params.size() == 3) {
				Resultat r1,r2;
				int e,e1,e2;
				r1 = Avaluem(params[1], var, op);
				r2 = Avaluem(params[2], var, op);
				if (r1.ets_definit() and r1.ets_enter() and r2.ets_definit() and r2.ets_enter()) {
					e1 = r1.obtenir_enter();
					e2 = r2.obtenir_enter();
					if (e1 == 1 and e2 == 1) {
						e = 1;
						r.crear_res_ent(e);                       
					}
					else if ((e1==0 or e1== 1) and (e2==0 or e2==1)) {
						e = 0;
						r.crear_res_ent(e);
						return r;
					}
				}
			}
		}
		else if (params[0] == "or") {
			if (params.size() == 3) {
				Resultat r1,r2;
				int e, e1,e2;
				r1 = Avaluem(params[1], var, op);
				r2 = Avaluem(params[2], var, op);
				if (r1.ets_definit() and r1.ets_enter() and r2.ets_definit() and r2.ets_enter()) {
					e1 = r1.obtenir_enter();
					e2 = r2.obtenir_enter();
					if ((e1 == 1 and e2 == 0) or (e1 == 0 and e2 == 1) or (e1 == 1 and e2 == 1)) {
						e = 1;
						r.crear_res_ent(e);                           
					}
					else if ((e1 == 0 or e1 == 1) and (e2 == 0 or e2 == 1)) {
						e = 0;
						r.crear_res_ent(e);
						return r;
					}
				}
			}
		}
		else if (params[0] == "if") {
			if (params.size() == 4 ) {
				Resultat r1;
				r1 = Avaluem(params[1], var, op);
				if (r1.ets_definit() and r1.ets_enter() and r1.obtenir_enter() == 1) {
					r = Avaluem(params[2], var, op);
				}
				else if (r1.ets_definit() and r1.ets_enter() and r1.obtenir_enter() == 0) {
					r = Avaluem(params[3],  var, op);
				}
				return r;
			}
		}
		else if (not has_only_digits) {
			if (var.esta_definida(params[0]) and not l) {
				r = var.obtenir_resultat(s);
			} else if (op.esta_definida(params[0])) {
					if (op.num_param(params[0]) == (params.size() - 1)) {
						string n = op.obtenir_def(params[0]); // Expressio
						string p = op.obtenir_param(params[0]);
						vector <string> params_func = extraer_todos(p);
						if (params_func.size() == params.size() - 1) {
							//comprovem que el nombre de parametres coincideix amb el de la funcio
							int i = 1;
							int k = 0;
							bool definit = true;
							Resultat r2;
							Variables var2;
							while (k < params_func.size() and definit) {  //bucle per cada param
								r2 = Avaluem(params[i], var, op);        //r2 = avaluo cadascun
								var2.afegir_variable(params_func[k], r2);    //afegeixo a var2(parametre,r2)
								if (not r2.ets_definit()) definit = false;
								++i;
								++k;
							} 
							r = Avaluem(n, var2, op);
							return r;
						}
					}
			} else if (l) { 
					Resultat r1;
					int i = 0;
					bool fin = false;
					while (i < params.size() and not fin) {
						r1 = Avaluem(params[i], var, op);
						if (r1.ets_definit() and r1.ets_enter() and not r1.llista_buida()) {
							r.afegir_enter(r1.obtenir_enter());
						} else {
								fin = true;
								r.modificar_definit(false);
						}
						++i;
					}
			}
			return r;
		} else { 
				Resultat r1;
				int i = 0;
				bool fin = false;
				while (i < params.size() and not fin) {
					r1 = Avaluem(params[i], var, op);
					if (r1.ets_definit() and r1.ets_enter() and not r1.llista_buida()) {
						r.afegir_enter(r1.obtenir_enter());
					} else {
							fin = true;
							r.modificar_definit(false);
					}
					++i;
				}
		}
	}
	return r;
}




