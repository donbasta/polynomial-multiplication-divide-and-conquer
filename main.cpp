#include <bits/stdc++.h>
#include "Polinom.cpp"

using namespace std;

void inputPolinomial(Polinom *P){

	int degree;

	cout << "Masukkan derajat polinom: ";
	cin >> degree;

	P->setDeg(degree);
	int x;
	for(int i=0; i<=degree; i++){
		cout << "Masukkan koefisien x^" << i << ": ";
		cin >> x;
		P->setKoef(i,x);
	}

}

int main(){

	Polinom P1;
	Polinom P2;
	Polinom Product;
	clock_t ti, tf;

	inputPolinomial(&P1);
	inputPolinomial(&P2);

	ti = clock();
	Product = P1 * P2;
	tf = clock();
  double waktu_eksekusi_bf = (double)(tf-ti)/CLOCKS_PER_SEC;

  ti = clock();
	Product = fast_mul(P1,P2);
	tf = clock();
  double waktu_eksekusi_dnc = (double)(tf-ti)/CLOCKS_PER_SEC;

  cout << waktu_eksekusi_bf;





	



}