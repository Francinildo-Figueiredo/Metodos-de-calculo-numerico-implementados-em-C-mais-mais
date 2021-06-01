#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
#include <locale>

using namespace std;

int main(){
	
	setlocale(LC_ALL, "portuguese");
	
	int n(1), ind;
	string mat_a, mat_b;
	
	cout << "Insira a matriz dos coeficientes no padrão [1 2 3;4 5 6;7 8 9]:\n" << endl;
	getline(cin, mat_a);
	cout << "\nInsira a matriz igualdade no padrão [1;2;3]:\n" << endl;
	getline(cin, mat_b);
	cout << endl;
	
	// Determinando a dimensão n do sistema
	for(int i(0); i < mat_a.size(); i++){
		if(mat_a[i] == ';')
			n++;
	}
	
	vector<vector<float>> A(n);
	vector<float> B;
	vector<string> aux(n);
	
	// Se parando cada linha da matriz dos coeficientes em uma string diferente
	mat_a.erase(mat_a.begin());
	for(int i(0); i < n; i++){
		ind = mat_a.find(';');
		if(ind != -1){
			aux[i].insert(aux[i].begin(),mat_a.begin(),mat_a.begin()+ind);
			mat_a.erase(mat_a.begin(),mat_a.begin()+ind+1);	
		}
		else{
			aux[i].insert(aux[i].begin(),mat_a.begin(),mat_a.end()-1);
		}
	}
	// Convertendo os valores das strings para float e passando para a matriz A
	for(int i(0); i < n; i++){
		for(int k(0); k < n; k++){
			A[i].push_back(stof(aux[i]));
			aux[i].erase(aux[i].begin(),aux[i].begin()+aux[i].find(' ')+1);
		}
	}
	
	mat_b.erase(mat_b.begin());
	for(int i(0); i < n; i++){
		B.push_back(stof(mat_b));
		mat_b.erase(mat_b.begin(),mat_b.begin()+mat_b.find(';')+1);
	}
	
	vector<float> X(B.size());
	int t = 2*n;
	
	cout << "Sistema a ser calculado:" << endl;
	for(int i(0); i < n; i++){
		for(int j(0); j < n; j++){
			cout << setw(5) << A[i][j] << " ";
		}
		cout << "  X" << i+1;
		if(i == n/2 || i == (n/2 + 0.5))
			cout << " = " ;
		else
			cout << "   ";
		cout << setw(5) << B[i] << endl;
	}
	
	for(int i(0); i < n; i++){
		for(int j(0); j < n; j++){
			if(i != j)
				A[i].push_back(0);
			else
				A[i].push_back(1);
		}
	}

	vector<vector<float>> m(A.size(), vector<float>(A.size(),0));
	
	//Método de eliminação de Jordan
	for (int j(0); j < n; j++){
		for (int i(0); i < n; i++){
			if(i!=j){
	    		m[i][j] = A[i][j]/A[j][j];
	    		
	    		for (int k(j); k < t; k++){
	    			A[i][k] = A[i][k] - m[i][j]*A[j][k];
	    		}
	    		B[i] = B[i] - m[i][j]*B[j];
	    	}
		}
	}
	vector<vector<float>> Inv(n, vector<float>(n,0));
	cout << "\n\nAproximação da solução:" << endl;
	for (int i(0); i < n; i++){
		X[i] = B[i]/A[i][i];
		//A(i,:) = A(i,:)/A(i,i);
		int k(0);
		for(int j(n); j < t; j++){
			Inv[i][k] = A[i][j]/A[i][i];
			k++; 
		}
		cout << "X" << i+1 << " = " << X[i] << endl;
	}
	
	cout << "\n\nMatriz inversa dos coeficientes:" << endl;
	for(int i(0); i < n; i++){
		for(int j(0); j < n; j++){
			cout << fixed << setprecision(6);
			cout << setw(10) << Inv[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
