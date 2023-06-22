
// ADRIÁN PÉREZ PEINADOR 

/*
LA SOLUCION PROPUESTA CONSISTE EN LA UTILIZACION DE UN MAPA NO ORDENADO PARA LOS ALUMNOS,
DONDE PARA CADA UNO SE GUARDA EL GRUPO EN EL QUE ESTÁ (0 SI ESTÁ GRADUADO) Y UN PUNTERO
A LA LISTA DE ALUMNOS DE ESE GRUPO.
ESTAS LISTAS ESTÁN ORGANIZADAS EN UN ARRAY Y DEBEN SER LISTAS EN LUGAR DE COLAS PORQUE SE
TIENE QUE PODER ELIMINAR UN ELEMENTO QUE ESTE EN EL MEDIO, A TRAVES DE SU ITERADOR.
APARTE, LOS GRADUADOS LOS GUARDAMOS EN UN SET PORQUE AQUÍ NOS INTERESA EL ORDEN ALFABÉTICO,
EN LUGAR DEL ORDEN DE LLEGADA.

EL COSTE DE nuevo_estudiante ES CONSTANTE PUES SE HACEN UN NUMERO CONSTANTE DE COSAS CUYO
COSTE ES CONSTANTE. LO MISMO OCURRE EN grupoestudiante y novato.
EN promocionar sin embargo es log n por la operacion insert
En graduados es O(n) porque hacemos un bucle con coste constante para los n elementos del set
*/


#ifndef ACADEMIACHINO
#define ACADEMIACHINO

#include <iostream>     
#include <string>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class academia_chino {
	using dni = string;
	using grupo = int;

	unordered_map<dni, pair<grupo, list<dni>::iterator >> alumnos;
	set<dni> grads;
	list<dni> grupos[6];

public:
	

   void nuevo_estudiante(dni d, grupo g){
	   if (!alumnos.count(d)) {
		   if (g < 1 || g > 6) { throw domain_error("Grupo incorrecto"); }
		   list<dni>::iterator it = grupos[g - 1].insert(grupos[g - 1].end(), d);
		   alumnos.insert({ d, {g, it} });
		}
	   else { throw domain_error("Estudiante existente"); }
   }

   void promocionar(dni d) {
	   if (!alumnos.count(d)) {  throw domain_error("Estudiante no existente");}
	   if (alumnos[d].first == 0) { throw domain_error("Estudiante ya graduado"); }
	   grupo g = alumnos[d].first;
	   if(alumnos[d].first == 6){
		   grupos[g - 1].erase(alumnos[d].second);
		   alumnos[d].first = 0;
		   grads.insert(d);
	   }
	   else {
		   grupos[g-1].erase(alumnos[d].second);
		   alumnos[d].second = grupos[g].insert(grupos[g].end(), d);
		   alumnos[d].first = g + 1;
	   }
   }

   int grupo_estudiante(dni d){
	   if (!alumnos.count(d)) { throw domain_error("Estudiante no existente"); }
	   if (alumnos[d].first == 0) {throw domain_error("Estudiante ya graduado"); }
	   return alumnos[d].first;
   }

   list<dni> graduados(){
	   list<dni> l;
	   for (auto const& s : grads) {
		   l.push_back(s);
	   }
	   return l;
   }
   dni novato(grupo g){
		if(g < 1 || g > 6){ throw domain_error("Grupo incorrecto"); }
		if (grupos[g - 1].empty()) { throw domain_error("Grupo vacio"); }
		return grupos[g - 1].back();
   }

};

#endif
