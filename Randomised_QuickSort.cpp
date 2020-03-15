#include<iostream>
#include<cstdlib>
using namespace std;
int Partition(int *A,int p,int r){
	int pivot = A[r];
	int i = p - 1;
	for(int j = p;j < r;j++){
		if(A[j] <= pivot){
			i++;
			//swapping the element A[j] and A[i]
			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	//set pivot to it's position by swapping:
	int t = A[i+1];
	A[i+1] = A[r];// <<pivot
	A[r] = t;
	return i+1;// << position of pivot
}
int RandomPartition(int *A,int p,int r){
	//taking any random integer in range p to r:
	int i = rand() % r + p;
	//now to set it as pivot,swap it with random number:
	int t = A[r];
	A[r] = A[i];
	A[i] = t;
	//call Partition:
	Partition(A,p,r);
}
void RandomisedQsort(int *A,int p,int r){
	if(p < r){
		int q = RandomPartition(A,p,r);
  		RandomisedQsort(A,p,q-1);
		RandomisedQsort(A,q+1,r);
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
	RandomisedQsort(A,0,n-1);
	cout << "sorted array:";
	for(int i = 0;i < n;i++)
		cout << A[i] << " ";
	return 0;
}



	
