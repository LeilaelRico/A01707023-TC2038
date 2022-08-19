/***********************************************************
 *                      ITESM Querétaro                    *
 *                          TC2038                         *
 *          Análisis y Diseño de Algoritmos Avanzados      *
 *                       Actividad 1.3                     *
 *                        19/08/2022                       *
 *           Olivia Araceli Morales Quezada A10707371      *
 *           Cristian Leilael Rico Espinosa A01707023      *
 ***********************************************************/

/***********************************************************
 * Implementación de Programación Dinámica y Algoritmos    *
 * Avaros.                                                 *
 ***********************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

/***********************************************************
 * 					Programación Dinámica                  *
 ***********************************************************/

/************************************************************
*  Su complejidad es de O(n*m).                             *
*  Encuentra el número mínimo de monedas para regresar      *
*  como cambio; para esto, utiliza los valores que se       *
*  se guardan en el vector monCambio como forma de          *
*  "Memorization".                                          *
*  La función termina imprimiendo el valor de las           *
*  monedas a dar como cambio así como el total de estas.    *
************************************************************/


int dp_coinChange(vector<int> coins, int amount)
{
	int auxAmount = amount;
	int minimum = 0;
	vector<int> monCambio;
	vector<int> denoCambio;
	monCambio.push_back(0);
	denoCambio.push_back(0);
	for (int m = 1; m <= amount; m++)
	{
		monCambio.push_back(m);
		denoCambio.push_back(m);
		for (int i = 0; i < coins.size(); i++)
		{
			if (m >= coins[i])
			{
				minimum = monCambio[m - coins[i]] + 1;
				if (minimum < monCambio[m])
				{
					monCambio[m] = minimum;
					denoCambio[m] = coins[i];
				}
			}
		}
	}
	while (auxAmount > 0)
	{
		cout << "DP -> Moneda: " << denoCambio[auxAmount] << "\n";
		auxAmount -= denoCambio[auxAmount];
	}
	return monCambio[amount];
}

/***********************************************************
 * 					  Algoritmo Avaro                      *
 ***********************************************************/

/************************************************************
*  Su complejidad es de O(nlog(n)).                         *
*  Encuentra el número mínimo de monedas para regresar      *
*  como cambio; para esto, comienza seleccionando las       *
*  monedas con mayor denominación hasta que ya              *
*  no le es posible.                                        *    
*  La función termina imprimiendo el valor de las           *
*  monedas a dar como cambio así como el total de estas.    *
************************************************************/

bool compare(int i, int j)
{
	return (i > j);
}

int coinChange(vector<int> coins, int amount)
{
	int minimum = 0;

	sort(coins.begin(), coins.end(), compare);

	vector<int> monCambio;

	for (int i = 0; i < coins.size(); i++)
	{
		while (amount >= coins[i])
		{
			amount = amount - coins[i];
			monCambio.push_back(coins[i]);
			minimum++;
		}
	}

	for (int i = 0; i < minimum; i++)
	{
		cout << "GREEDY -> Moneda: " << monCambio[i] << "\n";
	}

	return minimum;
}


int main()
{

	int denoTotal, den, precioProducto, pago, cambio, resultado;

	cout << "----------Actividad 1.3.-----------\n";
	cout << "Implementacion de la tecnica de Programacion dinamica y algoritmos avaros\n\n";

	cout << "Primero creemos nuestro sistema monetario: \n";

	cout << "Monedas que existen en tu sistema: \n";
	cin >> denoTotal;

	cout << "Ingresa las denominaciones de las " << denoTotal << " monedas: \n";

	vector<int> denominaciones;

	for (int i = 0; denoTotal > i; i++)
	{
		cin >> den;
		denominaciones.push_back(den);
	}

	cout << "Ingresa el precio del producto a comprar:" << endl;
	cin >> precioProducto;

	cout << "Billete o moneda con la que pagaras:" << endl;
	cin >> pago;

	cambio = pago - precioProducto;

	// Algoritmo Avaro

	cout << endl;
	cout << "===================================================================="  << endl;

	resultado = coinChange(denominaciones, cambio);
	cout << "GREEDY -> Total de monedas: " << resultado << endl;

	// Programación Dinámica

	cout << endl;
	cout << "===================================================================="  << endl;

	cout << "DP -> Total de Monedas: " << dp_coinChange(denominaciones, cambio) << endl;
}