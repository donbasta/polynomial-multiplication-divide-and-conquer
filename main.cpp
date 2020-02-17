#include "Polinom.cpp"

Polinom P;
int degree;

Polinom inputPolinomial(){
	Polinom P;

	cout << "Masukkan derajat polinom: ";
	cin >> degree;
	P = Polinom(degree);

	for(int i=0; i<=P.size; i++){
		cout << "Masukkan koefisien x^" << i << ": ";
		cin >> P.koef[i];
	}

	return P;
}

int main(){

	cout << "Masukkan derajat polinom: ";
	cin >> degree;

	P = inputPolinomial();
	Q = inputPolinomial();

	cout << P;


	



}