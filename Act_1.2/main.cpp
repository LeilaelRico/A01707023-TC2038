/***********************************************************
 *                      ITESM Querétaro                    *
 *                          TC2038                         *
 *          Análisis y Diseño de Algoritmos Avanzados      *
 *                       Actividad 1.2                     *
 *              Olivia Araceli Morales Quezada             *
 *              Cristian Leilael Rico Espinosa             *
 ***********************************************************/

#include <iostream>

using namespace std;

void mergeArray(double arr[], double arrAux[], int low, int mid, int high) {

  int i, j, k;

  i = low;
  j = mid + 1;
  k = low;

  while (i <= mid && j <= high) {
    if (arr[i] < arr[j]) {
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

void mergeSort(double a[], int size) {
  mergeSplit(a, 0, size - 1);

  cout << "\nSus numeros ordenados: \n";

  for (int i = 0; i < size; i++) {
    cout << a[i] << endl;
  }
}

int main() {

  int numTotal, nums;

  cout << "----------Actividad 1.2.-----------\n";
  cout
      << "Implementacion de la tecnica de programacion 'divide y venceras'\n\n";

  cout << "Ingresa la cantidad total de  numeros que quieres ordenar: \n";
  cin >> numTotal;

  cout << "Ingresa los " << numTotal << " numeros a ordenar: \n";

  double numsSort[numTotal];

  for (int i = 0; numTotal > i; i++) {
    cin >> nums;
    numsSort[i] = nums;
  }

  mergeSort(numsSort, numTotal);
}