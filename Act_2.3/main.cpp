/***********************************************************
 *                      ITESM Querétaro                    *
 *                          TC2038                         *
 *          Análisis y Diseño de Algoritmos Avanzados      *
 *                       Actividad 2.3                     *
 *                        06/09/2022                       *
 *           Olivia Araceli Morales Quezada A10707371      *
 *           Cristian Leilael Rico Espinosa A01707023      *
 ***********************************************************/

/***********************************************************
 * Implementación de Suffix Array                          *
 ***********************************************************/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* La función descompone el vector en todos los substrings */
// Complejidad: O(n)
vector<string> allSuffix(string w, vector<string> mainVec) {
  int count = 0;

  for (int i = 0; i < w.length(); i++) {
    mainVec.push_back(w.substr(count, w.length()));
    count++;
  }

  return mainVec;
}
/* Con ayuda de un loop for anidado, se imprime el vector de forma alfabética
   no sin antes imprimir el índice que indica en qué posición el sufijo se
   descompuso. */
// Complejidad: O(n^2)

void printSuffix(string w, vector<string> mainVec) {

  vector<string> auxVec;

  auxVec = mainVec;

  /* Con la función sort, el arreglo pasa a ordenarse de forma alfabética */
  // Complejidad: O(nLogN)
  sort(auxVec.begin(), auxVec.end());

  for (int i = 0; i < w.length(); i++) {
    for (int j = 0; j < mainVec.size(); j++) {

      if (auxVec[i] == mainVec[j]) {
        cout << j << ": " << mainVec[j] << endl;
      }
    }
  }
}

int main() {
  vector<string> vec;
  vector<string> vec_aux;
  string word;

  cout << "---------------------- Actividad 2.3 ----------------------\n";
  cout << "Implementacion de Suffix Array\n\n";

  cout << "Ingrese la palabra a utilizar: ";
  cin >> word;
  cout << endl;

  vec_aux = allSuffix(word, vec);

  printSuffix(word, vec_aux);

  // Complejidad global de O(n^2).

  return 0;
}