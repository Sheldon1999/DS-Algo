#include<iostream>
using namespace std;
void countSort(int *A,int *B,int n,int k){//n = size of A[] and B[];k = max element of A[]😅
	//make an array ,having size = k + 1, to store correct position of elements of A[]:
	//set every element = 0
	int C[k + 1] = {0};
	//storing frequencies of elements of A[]:
	for(int i = 0;i < n;i++)
		C[A[i]]++;
	for(int i = 1;i <= k;i++)
		C[i] = C[i] + C[i - 1];
	//making sorted array = B[]:
	for(int i = n - 1;i >= 0;i--){
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}
int main(){
	int n;
	cout << "enter size:";
	cin >> n;
	int A[n],B[n];
	cout << "enter array:";
	int max = 0;
	for(int i = 0;i < n;i++){
		cin >> A[i];
		if(A[i] > max)
			max = A[i];
	}
	countSort(A,B,n,max);
	cout << "sorted array:";
	for(int i = 0;i < n;i++)
		cout << B[i] << " ";
	return 0;
}
	
	
