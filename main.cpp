#include <bits/stdc++.h>
#include "Polinom.cpp"

using namespace std;

const int MAX = 20;

void inputPolinomial(Polinom *P){

	int degree;

	cout << "Masukkan derajat polinom: ";
	cin >> degree;

	P->setDeg(degree);
	int x;

	srand(time(NULL));
	for(int i=0; i<=degree; i++){
		// cout << "Masukkan koefisien x^" << i << ": ";
		x = rand()%(MAX);
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

  cout << fixed << setprecision(10) << waktu_eksekusi_bf << '\n';
  cout << fixed << setprecision(10) << waktu_eksekusi_dnc << '\n';





	



}