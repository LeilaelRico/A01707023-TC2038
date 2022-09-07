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
// O(nlogn)
int main() {
  string word;

  cout << "---------------------- Actividad 2.3 ----------------------\n";
	cout << "Implementacion de Suffix Array\n\n";

  cout << "Ingrese la palabra a utilizar: ";
  cin >> word;
  int count = 0;

  // O(n)
  for (int i = 0; i < word.length(); i++) {
    vec.push_back(word.substr(count, word.length()));
    count++;
  }

  vec_aux = vec;

  // O(nLogN)
  sort(vec_aux.begin(), vec_aux.end());

  // O(n)
  for (int i = 0; i < word.length(); i++) {
    for (int j = 0; j < vec.size(); j++) {

      if (vec_aux[i] == vec[j]) {
        cout << j << ": " << vec[j] << endl;
      }
    }
  }

  return 0;
}