#include<iostream>
using namespace std;

int main(){
	int n,c,i,p = 2,mul = 0,j;
	cin >> n;
	int A[160] = {0};
	A[0] = 1;
	for(i = 2;i <= n;i++){
		c = 0;
		j = 0;
		mul = (i * A[j]) + c;
		A[j] = mul % 10;
		c = mul / 10;
		j++;		
		if((c > 0)&&(j >= p))
			p++;		
		while(j < p){
			mul = (i * A[j]) + c;
			A[j] = mul % 10;
			c = mul / 10;
			j++;
			if((c > 0)&&(j >= p))
				p++;
		}
	}
	if(n < 4)
		cout << A[0];
	else{
		for(i = p-1;i >= 0;i--)
			cout << A[i];
	}	
}
