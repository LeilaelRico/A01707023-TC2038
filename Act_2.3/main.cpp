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

vector<string> vec;
vector<string> vec_aux;
// O(n^2)
int main() {
  string word;

  cout << "---------------------- Actividad 2.3 ----------------------\n";
	cout << "Implementacion de Suffix Array\n\n";

  cout << "Ingrese la palabra a utilizar: ";
  cin >> word;
  int count = 0;

  /* La función descompone el vector en todos los substrings */
  // Complejidad: O(n)
  for (int i = 0; i < word.length(); i++) {
    vec.push_back(word.substr(count, word.length()));
    count++;
  }

  vec_aux = vec;

  /* Con la función sort, el arreglo pasa a ordenarse de forma alfabética */
  // Complejidad: O(nLogN)
  sort(vec_aux.begin(), vec_aux.end());

  /* Con ayuda de un loop for anidado, se imprime el vector de forma alfabética
     no sin antes imprimir el índice que indica en qué posición el sufijo se
     descompuso. */
  // Complejidad: O(n^2)
  for (int i = 0; i < word.length(); i++) {
    for (int j = 0; j < vec.size(); j++) {

      if (vec_aux[i] == vec[j]) {
        cout << j << ": " << vec[j] << endl;
      }
    }
  }

  // Complejidad Global O(n^2).

  return 0;
}