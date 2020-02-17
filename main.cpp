#include <bits/stdc++.h>
#include "Polinom.cpp"

using namespace std;

Polinom Q;
int degree;

Polinom inputPolinomial(){

	cout << "Masukkan derajat polinom: ";
	cin >> degree;
	Polinom P = Polinom(degree);

	int x;
	for(int i=0; i<=P.getDeg(); i++){
		cout << "Masukkan koefisien x^" << i << ": ";
		cin >> x;
		P.setKoef(i,x);
	}

	return P;
}

int main(){

	Q = inputPolinomial();

	for(int i=0; i<=Q.getDeg(); i++){
		cout << "koefisien x^" << i << ": ";
		cout << Q.getKoef(i) << '\n';
	}


	



}