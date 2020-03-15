#include<iostream>
#include<cmath>
using namespace std;
void merge(int *A,int p,int q,int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1 + 1];
	int R[n2 + 1];
	int i,j;
	for(i = 0;i < n1;i++)
		L[i] = A[p + i];
	for(j = 0;j < n2;j++)
		R[j] = A[q + j + 1];
	//put a large value(sentinal card) at end of arrays L[] and R[]	
	L[n1] = 99999;
	R[n2] = 99999;
	i = 0;
	j = 0;
	for(int k = p;k <= r;k++){
		if(L[i] <= R[j]){
			A[k] = L[i]; 
			i++;
		}
		else if(L[i] > R[j]){
			A[k] = R[j];
			j++;
		}
	}
}
void mergeSort(int *A,int p,int r){
	if(p < r){  //<< base condition
		int q = floor((p + r)/2);
		//dividing array :
		mergeSort(A,p,q);
		mergeSort(A,q + 1,r);
		//merging divided arrays:
		merge(A,p,q,r);
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
	mergeSort(A,0,n - 1);
	cout << "sorted array:";
	for(int i = 0;i < n;i++)
		cout << A[i] << " ";
	return 0;
}









 
