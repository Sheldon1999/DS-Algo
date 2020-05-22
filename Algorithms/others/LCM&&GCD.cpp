#include<iostream>
using namespace std;

//function using Euclid algorithm:
int GCD(int a,int b){
	if(a < b){
		int t1 = a;
		a = b;
		b = t1;
	}
	int r = a % b;
	if(r == 0)
		return b;
	else
		GCD(b,r);
}

int main(){
	int a,b;
	cout << "enter numbers:";
	cin >> a >> b;
	int gcd = GCD(a,b);
	cout << "LCM:" << (a*b)/gcd << endl;
	cout << "GCD:" << gcd;	
	return 0;
}

