/** @file Resultat.cc
    @brief Implementació de la classe Resultat
*/

#include "Resultat.hh"

Resultat::Resultat(){
  definit = false;
}

void Resultat::Resultat_enter(const string &s) {
	int x = atoi(s.c_str());
	val.insert(val.end(),x);
	definit = true;
	enter = true;
}

void Resultat::crear_res_ent(int e) {
	list<int>::iterator it = val.begin();
	val.insert(it,e);
	enter = true;
	definit = true;
}

void Resultat::crear_list() {
	val.clear();
	enter = false;
	definit = true;
}

void Resultat::fer_igual(Resultat& r1, Resultat& r2) {
	int e;
	if (r1.ets_definit() and r2.ets_definit()) {
		if (r1.ets_enter() and r2.ets_enter()) {
			int e1 = r1.obtenir_enter();
			int e2 = r2.obtenir_enter();
			if (e1 == e2) e = 1;
			else e = 0;
			val.push_front(e);
			definit = true;
			enter = true;
		} else if (not r1.ets_enter() and not r2.ets_enter()) {
			if (r1.val == r2.val) e = 1;
			else e = 0;
			val.push_front(e);
			definit = true;
			enter = true;
		}
	}
}

void Resultat::fer_inferior(Resultat& r1, Resultat& r2) {
	int e;
	if (r1.ets_definit() and r2.ets_definit()) {
		if (r1.ets_enter() and r2.ets_enter()) {
			int e1 = r1.obtenir_enter();
			int e2 = r2.obtenir_enter();
			if (e1<e2) e = 1;
			else e = 0;
			val.push_front(e);
			definit = true;
			enter = true;
		}
		else if (not r1.ets_enter() and not r2.ets_enter()) {
			if (r1.val < r2.val ) e = 1;
			else e = 0;
			val.push_front(e);
			definit = true;
			enter = true;
		}
	}
}

bool Resultat::ets_enter() {
	return enter;
}

bool Resultat::ets_definit(){
  return definit;
}

int Resultat::obtenir_enter() {
	int e;
	list<int>::iterator it = val.begin();
	e = *it;
	return e;
}

bool Resultat::llista_buida() {
	return val.empty();
}

void Resultat::clear() {
	definit = false;
	enter = false;
	val.clear();
}

void Resultat::afegir_enter(int e) {
	val.push_back(e);
	enter = false;
	definit = true;
}

void Resultat::afegir_principi(int e) {
	val.push_front(e);
	enter = false;
	definit = true;
}

void Resultat::modificar_definit(bool b) {
	definit = b;
}

void Resultat::eliminar_front() {
	if (val.size() > 0) {
		val.pop_front();
		definit = true;
		enter = false;
	}
}

void Resultat::escriure(){
	if (definit) {
		list<int>::iterator it = val.begin();
		if (enter) cout <<*it << endl;
		else {
			bool primer = true;
			cout<<"(";
			while (it != val.end()) {
				if (primer) {
					primer = false;
					cout << *it;
				}		
				else cout << " " << *it;
				++it;
			}
			cout << ")" <<endl;
		}
	}
	else cout << "indefinit" <<endl;
}
