/* 
O objetivo da interpolação é obter um polinômio P(X) de grau (n - 1), que passe por todos os pontos de
um conjunto de dados {Xi, f(Xi)}. Quanto maior a quatidade n de pontos do conjunto, maior será o grau
do polinômio.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL, "portuguese");
	
	int n;
	cout << "Quantos pontos serão interpolados? ";
	cin >> n;
	
	vector<float> x,y;
	float elem;
	
	cout << "Primeiro insira os valores de X:" << endl;
	for(int i(0); i < n; i++){
		cout << "X" << i << ": ";
		cin >> elem;
		x.push_back(elem);
	}
	system("cls");
	cout << "Agora insira os valores de f(X):" << endl;
	for(int i(0); i < n; i++){
		cout << "f(X" << i << "): ";
		cin >> elem;
		y.push_back(elem);
	}
	system("cls");
	
	cout << setw(10) << "X" << setw(10) << " f(X)" << endl;
	for(int i(0); i < n; i++){
		cout << right << setw(10) << x[i] << right << setw(10) << y[i] << endl;
	}
	cout << endl;
	
	// Montando a matriz com as potências de Xi
	vector<vector<float>> mat_x(n);
	for(int i(0); i < n; i++){
		for(int j(n-1); j >= 0; j--){
			mat_x[i].push_back(pow(x[i],j));
		}
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
	    		y[i] = y[i] - m[i][j]*y[j];
	    	}
		}
	}
	
	// Determinando os coeficientes do polinômio interpolador
	vector<float> a(n);
	int ind(n-1);
	cout << "Coeficientes calculados: " << endl;
	for (int i(0); i < n; i++){
		a[i] = y[i]/mat_x[i][i];
		cout << "a" << ind << " = " << a[i] << endl;
		ind--;
	}
	
	cout << "\nPolinômio interpolador: " << endl;
	cout << "\nP(X) = ";
	ind = n-1;
	for(int i(0); i < n; i++){
		if(a[i] != 0 && a[i] != -0 && a[i] > 0 && i != 0)
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
