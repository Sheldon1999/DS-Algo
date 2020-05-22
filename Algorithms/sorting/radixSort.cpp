#include<iostream>
#include<cmath>
using namespace std;
int getDigitFromEnd(int n,int i){
	int p = pow(10,i - 1);
	return ((n/p) % 10);
}
void countSort(int *A,int n,int j){
	int C[10] = {0};
	int B[n];
	for(int i = 0;i < n;i++)
		B[i] = A[i];
	for(int i = 0;i < n;i++)
		C[getDigitFromEnd(B[i],j)]++;
	for(int i = 1;i <= 9;i++)
		C[i] = C[i] + C[i - 1];
	for(int i = n - 1;i >= 0;i--){
		A[C[getDigitFromEnd(B[i],j)] - 1] = B[i];
		C[getDigitFromEnd(B[i],j)]--;
	}
}
void radixSort(int *A,int n,int d){
	for(int i = 1;i <= d;i++)
		countSort(A,n,i);
}
int main(){
	int n;
	cout << "enter size:";
	cin >> n;
	int A[n];
	cout << "enter array:";
	int max = 0;	
	for(int i = 0;i < n;i++){
		cin >> A[i];
		if(A[i] > max)
			max = A[i];
	}
	int d = 0;
	for(int i = max;i != 0;i /= 10)
		d++;
	cout << "d" << d;
	radixSort(A,n,d);
	cout << "sorted array:";
	for(int i = 0;i < n;i++)
		cout << A[i] << " ";
	return 0;
}
