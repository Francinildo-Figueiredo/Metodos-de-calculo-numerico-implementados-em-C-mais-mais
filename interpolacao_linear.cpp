#include <iostream>
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL, "portuguese");
	
	int n;
	cout << "Quantos pontos serão interpolados? ";
	cin >> n;
	
	return 0;
}
