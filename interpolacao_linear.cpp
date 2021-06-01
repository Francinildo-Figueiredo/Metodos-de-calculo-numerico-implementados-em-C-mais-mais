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
	
	vector<vector<float>> mat_x(n);
	
	for(int i(0); i < n; i++){
		for(int j(n-1); j >= 0; j--){
			mat_x[i].push_back(pow(x[i],j));
		}
	}
	
	for(int i(0); i < n; i++){
		for(int j(0); j < n; j ++){
			cout << setw(6) << mat_x[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
