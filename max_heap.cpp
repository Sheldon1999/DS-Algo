#include<iostream>
#include<cmath>
using namespace std;
void MaxHeapify(int *A,int i,int n);
void BuildMaxHeap(int *A,int n){
	for(int i = floor(n/2);i >= 0;i--)
		MaxHeapify(A,i,n);
}
void MaxHeapify(int *A,int i,int n){
	int l = 2*i,r = (2*i)+1,larg;
	if((l < n)&&(A[l] > A[i]))
		larg = l;
	else
		larg = i;
	if((r < n)&&(A[r] > A[larg]))
		larg = r;
	if(larg != i){
		int t = A[larg];
		A[larg] = A[i];
		A[i] = t;
		MaxHeapify(A,larg,n);
	}
}
void DeleteHeap(int no,int *A,int n){
	int p;
	for(int i = 0;i < n;i++){
		if(A[i] == no){
			p = i;
			break;
		}
	}
	int t = A[p];
	A[p] = A[n-1];
	A[n-1] = t;
	MaxHeapify(A,p,n-1);
}
void insertHeap(int no,int *A,int n){
	A[n-1] = no;
	BuildMaxHeap(A,n);
}
	
int main(){
	int n,no;
	cin >> n;
	int A[n];
	for(int i = 0;i < n;i++)
		cin >> A[i];
	BuildMaxHeap(A,n);
	cout << "element to be deleted:";
	cin >> no;
	DeleteHeap(no,A,n);
	cout << "after deletion:";
	for(int i = 0;i < n-1;i++)
		cout << A[i] << " ";
	cout << "element to be inserted:";
	cin >> no;
	insertHeap(no,A,n);
	cout << "after insertion:";
	for(int i = 0;i < n;i++)
		cout << A[i] << " ";
}
