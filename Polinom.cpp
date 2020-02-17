#include <bits/stdc++.h>

using namespace std;

//Polinomial nol memiliki derajat -1
class Polinom {

private:
	int deg;
	int* koef;


public:
	//ctor
	Polinom () {
		this->deg = 0;
		this->koef = new int[1];
	}

	//ctor custom
	Polinom (int deg) {
		this->deg = deg;
		this->koef = new int[deg+1];
	}

	//cctor
	Polinom (const Polinom& P){
		this->deg = P.deg;
		this->koef = new int[deg+1];
		for(int i=0; i<=this->deg; i++){
			this->koef[i] = P.koef[i];
		}
	}

	//dtor
	~Polinom () {
		delete this->koef;
	}

	//getter
	int getDeg() {
		return this->deg;
	}

	int getKoef(int idx){
		return this->koef[idx];
	}

	//setter
	void setKoef(int idx, int val){
		this->koef[idx] = val;
	}

	void setDeg(int deg){
		//resize ukuran dynamic arraynya
		this->deg = deg;
		this->koef = new int[deg+1];
		this->koef = (int*) realloc (this->koef, (deg+1) * sizeof(int));
	}

	Polinom& operator= (const Polinom& P){
		//resize this->koef jadi sama kayak P ukurannya
		this->deg = P.deg;
		for(int i=0; i<=this->deg; i++){
			this->koef[i] = P.koef[i];
		}
		return *this;
	}

	Polinom operator+ (const Polinom& P){
		Polinom prod = Polinom (max(this->deg, P.deg));
		for(int i=0; i<=prod.deg; i++){
			prod.koef[i] = (i<=this->deg ? this->koef[i] : 0) + (i<=P.deg ? P.koef[i] : 0);
		}
		for(int i=prod.deg; i>=0; i--){
			if(prod.koef[i]==0) {prod.deg--;}
			if(prod.koef[i]!=0) {break;}
		}
		// (prod.koef resize jadi prod.size)
		return prod;
	}

	Polinom operator- (const Polinom& P){
		Polinom prod = Polinom (max(this->deg, P.deg));
		for(int i=0; i<=P.deg; i++){
			prod.koef[i] = (i<=this->deg ? this->koef[i] : 0) - (i<=P.deg ? P.koef[i] : 0);
		}
		for(int i=prod.deg; i>=0; i--){
			if(prod.koef[i]==0) {prod.deg--;}
			if(prod.koef[i]!=0) {break;}
		}
		// (prod.koef resize jadi prod.size)
		return prod;
	}

	// // Algoritma perkalian polinom brute force, memiliki kompleksitas O(n^2)
	Polinom operator* (const Polinom& P){ 
		if(P.deg < 0) {return P;}
		Polinom prod = Polinom (this->deg + P.deg);
		for(int i=0; i<=this->deg; i++){
			for(int j=0; j<=P.deg; j++){
				prod.koef[i+j] += this->koef[i] * P.koef[j];
			}
		}
		return prod;
	}

	// // Mengalikan polinom dengan x^n, memiliki kompleksitas O(n)
	Polinom operator<< (int n){
		if(this->deg < 0) {return *this;}
		Polinom prod = Polinom (this->deg + n);
		for(int i=prod.deg; i>=n; i--){
			prod.koef[i] = this->koef[i-n];
		}
		return prod;
	}

	// // Membagi polinom dengan x^n, pembulatan ke bawah
	Polinom operator>> (int n){
		// if(this->deg < n) {return }
		Polinom prod = Polinom (max(this->deg - n, 0));
		if(this->deg >= n){
			for(int i=prod.deg; i>=0; i--){
				prod.koef[i] = this->koef[i+n];
			}
		} else {
			prod.deg = -1;
		}
		return prod;
	}

	friend ostream& operator<< (ostream& output, Polinom P){
		bool first = false;
		output << "Derajat polinom adalah: " << P.getDeg() << '\n';
		output << "Polinomnya adalah: ";
		for(int i=0; i<=P.getDeg(); i++){
			if(P.getKoef(i)!=0){
				if(P.getKoef(i) > 0){ //handle juga pas koefisiennya 1
					if(!first) output << P.getKoef(i) << "x^" << i << " ";
					else output << "+ " << P.getKoef(i) << "x^" << i << " ";
				} else {
					output << "- " << -P.getKoef(i) << "x^" << i << " ";
				}
				first = true;
			}
		}
		output << "\n";
		return output;
	}

};

// Prekondisi : derajat P dan derajat Q sama besar
inline Polinom fast_mul(Polinom P, Polinom Q){

	int n = P.getDeg();

	if(n==0){
		Polinom R = Polinom(0);
		R.setKoef(0,P.getKoef(0) * Q.getKoef(0));
		return R;
	}

	Polinom P1 = P >> ((n+1)/2);
	Polinom P0 = P - (P1 << ((n+1)/2)); //perlu diganti lagi ukuran P0 nya
	Polinom Q1 = Q >> ((n+1)/2);
	Polinom Q0 = Q - (Q1 << ((n+1)/2));

	// Hanya ada tiga kali pemanggilan fungsi rekursif
	Polinom R0 = fast_mul(P0,Q0);
	Polinom R1 = fast_mul(P1,Q1);
	Polinom R2 = fast_mul(P0+P1,Q0+Q1);

	return R0 + (R2 << ((n+1)/2)) + (R1 << n) - (R0 << ((n+1)/2)) - (R1 << ((n+1)/2));

}