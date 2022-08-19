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
using namespace std;

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
		cout << "Moneda " << i+1 << ": " << monCambio[i] << "\n";
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

	resultado = coinChange(denominaciones, cambio);
	cout << "Total de monedas: " << resultado << endl;
}