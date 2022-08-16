/***********************************************************
 *                      ITESM Querétaro                    *
 *                          TC2038                         *
 *          Análisis y Diseño de Algoritmos Avanzados      *
 *                       Actividad 1.2                     *
 *                        15/08/2022                       *
 *           Olivia Araceli Morales Quezada A10707371      *
 *           Cristian Leilael Rico Espinosa A01707023      *
 ***********************************************************/

/***********************************************************
 * Implementación del algoritmo MergeSort utilizando la    *
 * técnica "Divide y Vencerás".                            *
 ***********************************************************/

#include <iostream>

using namespace std;

/************************************************************
*  La función mergeArray se encarga de ir recorriendo el    *
*  arreglo de números dados por el usuario                  *
*  para después fusionarlos de forma ordenada.              *
*  Consta de 3 variables de tipo entero que serán           *
*  utilizadas para representar el posicionamiento del       *
*  recorrido, siendo "i" la posisción actual, "j" la        *
*  aquella que determinará el lugar donde el arreglo debe   *
*  partirse y "k" la posición final del arreglo.            *
************************************************************/

void mergeArray(double arr[], double arrAux[], int low, int mid, int high) {

  int i, j, k;

  i = low;
  j = mid + 1;
  k = low;

  while (i <= mid && j <= high) {
    if (arr[i] > arr[j]) {
      arrAux[k] = arr[i];
      i++;
    } else {
      arrAux[k] = arr[j];
      j++;
    }
    k++;
  }
  if (i > mid) {
    for (; j <= high; j++) {
      arrAux[k++] = arr[j];
    }
  } else {
    for (; i <= mid; i++) {
      arrAux[k++] = arr[i];
    }
  }
  for (int i = low; i <= high; i++) {
    arr[i] = arrAux[i];
  }
}

/*************************************************************
*  La función mergeSplit separa a la mitad el arreglo,       *
*  y se apoya en el método mergeArray para juntarlos,        *
*  esto se realiza de manera recursiva.                      *
*  Recibe como parámetros el arreglo a ordenar, su           *
*  inicio y final.                                           *
*              No regresa ningun parámetro.                  *
*************************************************************/

void mergeSplit(double arr[], int low, int high) {
  int mid;

  double arrAux[high];

  if ((high - low) < 1) {
    return;
  }
  mid = (high + low) / 2;
  mergeSplit(arr, low, mid);
  mergeSplit(arr, mid + 1, high);
  mergeArray(arr, arrAux, low, mid, high);
}

/************************************************************
 *  La función mergeSort es la función principal de este    *
 *  programa; esta recibe los datos iniciales del usuario   *
 *  para después pasárselos en forma de parámetros a        *
 *  mergeSplit.                                             *
 *  Una vez que el arreglo es modificado por las dos        *
 *  funciones anteriores, esta función imprime en consola   *
 *  el arreglo ordenado.                                    *
 ************************************************************/

void mergeSort(double a[], int size) {
  mergeSplit(a, 0, size - 1);

  cout << "\nSus numeros ordenados de mayor a menor: \n";

  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
}

int main() {

  int numTotal, nums;

  cout << "----------Actividad 1.2.-----------\n";
  cout
      << "Implementacion de la tecnica de programacion 'divide y venceras'\n\n";

  cout << "Ingresa la cantidad total de numeros que quieres ordenar: \n";
  cin >> numTotal;

  cout << "Ingresa los " << numTotal << " numeros a ordenar: \n";

  double numsSort[numTotal];

  for (int i = 0; numTotal > i; i++) {
    cin >> nums;
    numsSort[i] = nums;
  }

  mergeSort(numsSort, numTotal);
}