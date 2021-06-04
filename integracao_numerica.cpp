// Este programa utiliza a regra de Simpson para obter uma aproxima��o da integral definida.
// As entradas s�o o intervalo de integra��o e algumas sa�das da fun��o.
// A fun��o tamb�m pode ser inserida no c�digo por meio de algumas edi��es.

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std;

float funcao(float x){
	float y;
	y = 5*pow(x,5)*sin(x) - 11*pow(x,3)*exp(4*x);
	
	return y;
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	float a,b;
	cout << "Informe os limites de integra��o:" << endl;
	cout << "Limite inferior a: ";
	cin >> a;
	cout << "Limite superior b: ";
	cin >> b;
	
	// Definindo a dimens�o da subdivis�o do intervalo
	int n(6);
	float h = (b-a)/n, aux(a);
	n += 1; 
	vector<float> x,y;
	for(int i(0); i < n; i++){
		x.push_back(aux);
		aux += h;
	}
	
	//cout << "\nInsira os valores da fun��o para os seguintes valores de X: " << endl;
	for(int i(0); i < n; i++){
		//cout << fixed << setprecision(4) << "f(" << x[i] << ") = ";
		//cin >> aux;
		aux = funcao(x[i]);
		y.push_back(aux);
	}
	
	// M�todo de Simpson
	float soma(0);
	for(int i(0); i < n; i++){
		if(i == 0 || i == n-1)
			soma += y[i];
		else if(i % 2 == 0)
			soma += 2*y[i];
		else
			soma += 4*y[i];
	}
	float area = (h/3)*soma;
	
	cout << fixed << setprecision(2);
	cout << "\nAproxima��o do resultado da integral no intervalo [" << a << "," << b << "]: " << area << endl;
	
	return 0;
}
