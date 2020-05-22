#include<iostream>
using namespace std;
void inserSort(int *A,int n/*size of array*/){
	for(int i = 1;i < n;i++){
		int key = A[i];
		int j = i - 1;
		while((j >= 0)&&(A[j] > key)){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}
int main(){
	int n;
	cout << "enter size:";
	cin >> n;
	int A[n];
	cout << "enter array:";
	for(int i = 0;i < n;i++)
		cin >> A[i];
	inserSort(A,n);
	cout << "sorted Array:";		
	for(int i = 0;i < n;i++)
		cout << A[i] << " ";
	return 0;
}
