#ifndef registro_faltas_h
#define registro_faltas_h
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "hashmap_eda.h"
#include "treemap_eda.h"

using namespace std;

#define clave first
#define valor second

using alumno = std::string;
using falta = std::string;

class registro_faltas {
	using info_alumno = pair<int, unorder_map<falta, int>>;
	map<alumno, info_alumno> tabla;
public:
   registro_faltas() {}

   void registrar(falta const& f, alumno const& a) {
	   auto& info = tabla[a];
	   ++info.first;
	   ++info.second[f];
   }

   void borrar_falta(falta const& f, alumno const& a) {
      
   }

   void borrar(alumno const& a) {
      
   }

   int cantidad_falta(falta const& f, alumno const& a) const {
      
   }

   int cantidad(alumno const& a) const {
      
   }

   std::vector<alumno> lista_negra_falta(falta const& f, int n) const {
      
   }

   std::vector<alumno> lista_negra(int n) const { 
      
   }
};

#endif
