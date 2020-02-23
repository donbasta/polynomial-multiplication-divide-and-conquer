#include <bits/stdc++.h>

using namespace std;

//Polinomial nol memiliki derajat -1
class Polinom {

private:
	int deg;
	vector<int> koef;


public:
	//ctor
	Polinom () {
		this->deg = 0;
	}

	//ctor custom
	Polinom (int deg) {
		this->deg = deg;
		this->koef.resize(deg+1);
	}

	//cctor
	Polinom (const Polinom& P){
		this->deg = P.deg;
		this->koef.resize(deg+1);
		for(int i=0; i<=this->deg; i++){
			this->koef[i] = P.koef[i];
		}
	}

	//dtor
	~Polinom () {
	}

	//getter
	int getDeg() const {
		return this->deg;
	}

	int operator[](int idx) const {
		return this->koef[idx];
	}

	//setter
	void setKoef(int idx, int val){
		this->koef[idx] = val;
	}

	void setDeg(int deg){
		this->deg = deg;
		this->koef.resize(deg+1);
	}

	Polinom& operator= (const Polinom& P){
		this->koef.resize(P.deg+1);
		this->deg = P.deg;
		for(int i=0; i<=this->deg; i++){
			this->koef[i] = P.koef[i];
		}
		return *this;
	}

	Polinom operator+ (const Polinom& P){
		Polinom prod = Polinom (max(this->deg, P.deg));
		for(int i=0; i<=min(this->deg, P.deg); i++){
			prod.koef[i] = this->koef[i] + P.koef[i];
		}
		for(int i=0; i<=prod.deg; i++){
			prod.koef[i] = (i<=this->deg ? this->koef[i] : 0) + (i<=P.deg ? P.koef[i] : 0);
		}
		return prod;
	}

	Polinom operator- (const Polinom& P){
		Polinom prod = Polinom (max(this->deg, P.deg));
		for(int i=0; i<=min(this->deg, P.deg); i++){
			prod.koef[i] = this->koef[i] - P.koef[i];
		}
		for(int i=0; i<=prod.deg; i++){
			prod.koef[i] = (i<=this->deg ? this->koef[i] : 0) - (i<=P.deg ? P.koef[i] : 0);
		}
		return prod;
	}

	// Algoritma perkalian polinom brute force, memiliki kompleksitas O(n^2)
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

	Polinom operator% (const Polinom& P){

		int n = this->deg;

		if(n==0){
			Polinom R = Polinom(0);
			R.setKoef(0, (this->koef[0])*P[0]);
			return R;
		}

		Polinom P1(n-(n+1)/2);
		for(int i=0; i<=P1.deg; i++){
			P1.setKoef(i,P[i+(n+1)/2]);
		}

		Polinom P0((n+1)/2-1);
		for(int i=0; i<=P0.deg; i++){
			P0.setKoef(i,P[i]);
		}

		Polinom Q1(n-(n+1)/2);
		for(int i=0; i<=Q1.deg; i++){
			Q1.setKoef(i,this->koef[i+(n+1)/2]);
		}

		Polinom Q0((n+1)/2-1);
		for(int i=0; i<=Q0.deg; i++){
			Q0.setKoef(i,this->koef[i]);
		}

		// Hanya ada tiga kali pemanggilan fungsi rekursif
		Polinom R0(P0 % Q0);
		Polinom R1(P1 % Q1);
		Polinom R2((P0+P1) % (Q0+Q1));

		return R0 + ((R2-R0-R1) << ((n+1)/2)) + (R1 << 2*((n+1)/2));
	}

	friend ostream& operator<< (ostream& out, Polinom P){
		bool first = false;
		out << "Derajat polinom adalah: " << P.getDeg() << '\n';
		out << "Polinomnya adalah: ";
		for(int i=0; i<=P.getDeg(); i++){
			if(P[i]!=0){
				if(P[i] > 0){ //handle juga pas koefisiennya 1
					if(!first) out << P[i] << "x^" << i << " ";
					else out << "+ " << P[i] << "x^" << i << " ";
				} else {
					out << "- " << -P[i] << "x^" << i << " ";
				}
				first = true;
			}
		}
		out << "\n";
		return out;
	}

};