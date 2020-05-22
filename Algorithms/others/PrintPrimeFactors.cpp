#include<iostream>
#include<cmath>
using namespace std;

void PrintPrimeFactors(long int n){
	cout << "prime factors are:";
	while(n%2 == 0){
		cout << "2 ";
		n = n/2;
	}
	for(int i = 3;i <= sqrt(n);i = i+2){
		while(n%i == 0){
			cout << i << " ";
			n = n/i;
		}
	}
	if(n > 2)
		cout << n;
}

int main(){
	long int a;
	cout << "enter number:";
	cin >> a;
	PrintPrimeFactors(a);
	return 0;
}

