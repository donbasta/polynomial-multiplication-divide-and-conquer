#include <bits/stdc++.h>

using namespace std;


class Polinom {

	int size;
	int* koef;

	//ctor
	Polinom () {
		this->size = 0;
		this->koef = new int(0);
	}

	//ctor custom
	Polinom (int sz) {
		this->size = sz;
		this->koef = new int(sz);
	}

	//cctor
	Polinom (const Polinom& P){
		this->size = P.size;
		this->koef = new int(size);
		for(int i=0; i<=size){
			this->koef[i] = P.koef[i];
		}
	}

	Polinom& operator= (const Polinom& P){
		//resize this->koef jadi sama kayak P ukurannya
		this->size = P.size;
		for(int i=0; i<=this->size; i++){
			this->koef[i] = P.koef[i];
		}
		return *this;
	}

	Polinom operator+ (const Polinom& P){
		Polinom prod = Polinom (max(this->size, P.size));
		for(int i=0; i<=P.size; i++){
			prod.koef[i] = (i<=this->size : this->koef[i] : 0) + (i<=P.size : P.koef[i] : 0);
		}
		return prod;
	}

	Polinom operator- (const Polinom& P){
		Polinom prod = Polinom (max(this->size, P.size));
		for(int i=0; i<=P.size; i++){
			prod.koef[i] = (i<=this->size : this->koef[i] : 0) - (i<=P.size : P.koef[i] : 0);
		}
		for(int i=prod.size; i>=0; i--){
			if(prod.koef[i]==0) {prod.size--;}
		}
		// (prod.koef resize jadi prod.size)
		return prod;
	}

	// Algoritma perkalian polinom brute force, memiliki kompleksitas O(n^2)
	Polinom operator* (const Polinom& P){ 
		Polinom prod = Polinom (this->size + P.size);
		for(int i=0; i<=this->size; i++){
			for(int j=0; j<=P.size; j++){
				prod.koef[i+j] += this->koef[i] * P.koef[j];
			}
		}
		return prod;
	}

	// Mengalikan polinom dengan x^n, memiliki kompleksitas O(n)
	Polinom operator<< (int n){
		Polinom prod = Polinom (this->size + n);
		for(int i=prod.size; i>=n; i--){
			prod.koef[i] = this->koef[i-n];
		}
		return prod;
	}

	// Membagi polinom dengan x^n, pembulatan ke bawah
	Polinom operator>> (int n){
		Polinom prod = Polinom (max(this->size - n, 0));
		if(prod.size > 0){
			for(int i=prod.size; i>=0; i--){
				prod.koef[i] = this->koef[i+n];
			}
		}
		return prod;
	}

	ostream& operator<< (ostream& output){
		output << "Derajat polinom adalah: " << this->size;
		output << '\n';
		for(int i=0; i<=this->size; i++){
			output << "Koefisien x^" << i << " adalah: " << this->koef[i];
			output << '\n';
		}
		return output;
	}

};

// Prekondisi : derajat P dan derajat Q sama besar
void fast_mul(Polinom P, Polinom Q){

	int n = P.size;

	Polinom P1 = P >> (n/2);
	Polinom P0 = P - P1; //perlu diganti lagi ukuran P0 nya
	Polinom Q1 = Q >> (n/2);
	Polinom Q0 = Q - Q1;

	// Hanya ada tiga kali pemanggilan fungsi rekursif
	Polinom R0 = fast_mul(P0,Q0);
	Polinom R1 = fast_mul(P1,Q1);
	Polinom R2 = fast_mul(P0+P1,Q0+Q1);

	return R0 + (R2 << (n/2)) + (R1 << n) - (R0 << (n/2)) - (R1 << (n/2));

}