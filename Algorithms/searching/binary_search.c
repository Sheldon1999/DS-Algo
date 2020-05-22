#include<stdio.h>
int binarysearch(int *A,int l,int h,int x){
int mid = l + (h - l)/2;
if(l > h)
return -1;
if(x == A[mid])
return mid;
else if(x < A[mid])
binarysearch(A,l,mid - 1,x);
else if(x > A[mid])
binarysearch(A,mid + 1,h,x);
}
void bubSort(int *A,n){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n-i-1;j++){
			if(A[j] > A[j+1]){
				int t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
		}
	}
}
int main(){
int n,i,e;
printf("enter size:");
scanf("%d",&n);
int A[n];
printf("enter SORTED array:");
for(i = 0;i < n;i++)
scanf("%d",&A[i]);
bubSort(A,n);
printf("enter element to be searched:");
scanf("%d",&e);
int x;
x = binarysearch(A,0,n - 1,e);
if(x == -1)
printf("element is not found......!");
else
printf("element is at index %d.",x);
return 0;
}
