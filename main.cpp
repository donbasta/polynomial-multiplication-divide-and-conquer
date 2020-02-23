#include <bits/stdc++.h>
#include "Polinom4.cpp"

using namespace std;

const int MAX = 20;

void inputPolinomialRandom(Polinom *P){

	int degree;

	cout << "Masukkan derajat polinom: ";
	cin >> degree;
					
	P->setDeg(degree);
	
	srand(time(NULL));
	for(int i=0; i<=degree; i++){
		int x;
		x = rand()%(MAX);
		P->setKoef(i,x);
	}

}

void inputPolinomialManual(Polinom *P){

	int degree;

	cout << "Masukkan derajat polinom: ";
	cin >> degree;
					
	P->setDeg(degree);
	
	srand(time(NULL));
	for(int i=0; i<=degree; i++){
		int x;
		cout << "Masukkan koefisien dari x^" << i << ": ";
		cin >> x;
		P->setKoef(i,x);
	}

}

Polinom P1;
Polinom P2;
Polinom Product1;
Polinom Product2;
clock_t ti, tf;
int sum1, sum2, mul1, mul2;
int ok;


int main(){

	cout << "Selamat datang di aplikasi polinomial\n";
	cout << "Tekan 1 untuk input polinomial secara random, dan 2 untuk input secara manual\n";
	cin >> ok;

	while(ok!=1 && ok!=2){
		cout << "Masukan tidak valid, coba lagi: ";
		cin >> ok;
	}

	if(ok==1){
		inputPolinomialRandom(&P1);
		inputPolinomialRandom(&P2);
	} else {
		inputPolinomialManual(&P1);
		inputPolinomialManual(&P2);
	}

	cout << P1 << P2;

	ti = clock();
	Product1 = bf_mul(P1,P2,&sum1,&mul1);
	tf = clock();
  double waktu_eksekusi_bf = (double)(tf-ti);
  cout << Product1;
  cout << "Banyaknya penjumlahan adalah: " << sum1 << "\n";
  cout << "Banyaknya perkalian adalah: " << mul1 << "\n";
  cout << "Waktu eksekusi algoritma brute force adalah: ";
  cout << fixed << setprecision(4) << waktu_eksekusi_bf << " mikrosekon\n";

  ti = clock();
	Product2 = dnc_mul(P1,P2,&sum2,&mul2);
	tf = clock();
  double waktu_eksekusi_dnc = (double)(tf-ti);
  cout << Product2;
  cout << "Banyaknya penjumlahan adalah: " << sum2 << "\n";
  cout << "Banyaknya perkalian adalah: " << mul2 << "\n";
  cout << "Waktu eksekusi algoritma divide and conquer adalah: ";
  cout << fixed << setprecision(4) << waktu_eksekusi_dnc << " mikrosekon\n";


}