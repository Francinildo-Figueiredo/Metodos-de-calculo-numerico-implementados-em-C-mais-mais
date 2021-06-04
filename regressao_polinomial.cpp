// Esse programa realiza regressão polinomial a partir de um sistema de equações lineares

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL, "portuguese");
	
	int p,g;
	cout << "Quantos pontos serão utilizados? ";
	cin >> p;
	cout << "Qual o grau do polinômio? ";
	cin >> g;
	
	int n(g+1);
	vector<float> x,y;
	float elem;
	
	cout << "Primeiro insira os valores de X:" << endl;
	for(int i(0); i < p; i++){
		cout << "X" << i << ": ";
		cin >> elem;
		x.push_back(elem);
	}
	system("cls");
	cout << "Agora insira os valores de f(X):" << endl;
	for(int i(0); i < p; i++){
		cout << "f(X" << i << "): ";
		cin >> elem;
		y.push_back(elem);
	}
	system("cls");
	
	cout << setw(10) << "X" << setw(10) << " f(X)" << endl;
	for(int i(0); i < p; i++){
		cout << right << setw(10) << x[i] << right << setw(10) << y[i] << endl;
	}
	cout << endl;
	
	// Montando a matriz com todos os somatórios das potências de X
	vector<vector<float>> mat_x(n);
	float soma(0);
	for(int i(0); i < n; i++){
		for(int j(0); j < n; j++){
			for(int k(0); k < p; k++){
				soma += pow(x[k], j+i);
			}
			mat_x[i].push_back(soma);
			soma = 0;
		}
	}
	
	vector<float> mat_y;
	for(int i(0); i < n; i++){
		for(int k(0); k < p; k++){
			soma += pow(x[k], i)*y[k];
		}
		mat_y.push_back(soma);
		soma = 0;
	}
	
	//Método de eliminação de Gauss-Jordan
	vector<vector<float>> m(n, vector<float>(n,0));
	for (int j(0); j < n; j++){
		for (int i(0); i < n; i++){
			if(i!=j){
	    		m[i][j] = mat_x[i][j]/mat_x[j][j];
	    		
	    		for (int k(j); k < n; k++){
	    			mat_x[i][k] = mat_x[i][k] - m[i][j]*mat_x[j][k];
	    		}
	    		mat_y[i] = mat_y[i] - m[i][j]*mat_y[j];
	    	}
		}
	}
	
	// Determinando os coeficientes do polinômio regredido
	vector<float> a(n);
	cout << "Coeficientes calculados: " << endl;
	for (int i(0); i < n; i++){
		a[i] = mat_y[i]/mat_x[i][i];
		cout << "a" << i << " = " << a[i] << endl;
	}
	
	cout << "\nPolinômio Regredido: " << endl;
	cout << "\nP(X) = ";
	int ind(n-1);
	for(int i(n-1); i >= 0; i--){
		if(a[i] != 0 && a[i] != -0 && a[i] > 0)
			cout << " +";
		else if(a[i] < 0)
			cout << " ";
		if(a[i] == 0 || a[i] == -0)
			cout << "";
		else if(ind == 1 && a[i] != 1 && a[i] != -1)
			cout << a[i] << "*X";
		else if(ind == 0)
			cout << a[i];
		else if(ind == 1 && a[i] == 1)
			cout << "X";
		else if(ind == 1 && a[i] == -1)
			cout << " -X";
		else if(a[i] == 1)
			cout << "X^" << ind;
		else if(a[i] == -1)
			cout << " -X^" << ind;
		else
			cout << a[i] << "*X^" << ind;
		ind--;
	}
	
	return 0;
}
