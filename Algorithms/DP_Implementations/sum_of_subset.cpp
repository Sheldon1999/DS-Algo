#include<iostream>
using namespace std;

bool subSet(int *val,int *aux,int n,int i,int sum,int total,int K){
    if(sum == K)
        return true;
    if(sum > K)
        return false;
    if(sum+total < K)
        return false;
    if(i+1 < n){
        aux[i+1] = 1;
        if(subSet(val,aux,n,i+1,sum+val[i+1],total-val[i+1],K) == true)
            return true;
        else{
            aux[i+1] = 0;
            if(subSet(val,aux,n,i+1,sum,total,K) == true)
                return true;
        }
    }
    return false;
}

int main(){
    int n,K;
    cout << "enter the size of array:";
    cin >> n;
    int val[n],total = 0;
    cout << "enter the elements:";
    for(int i = 0;i < n;i++){
        cin >> val[i];
        total += val[i];
    }
    cout << "enter the desired sum:";
    cin >> K;
    //aux array to represent elements to be choosed:
    int aux[n] = {0};
    if(subSet(val,aux,n,-1,0,total,K) == true){
        cout << "elements are: ";
        for(int i = 0;i < n;i++){
            if(aux[i] == 1)
                cout << val[i] << " ";
        }
    }
    else{
        cout << "can't possible!!!";
    }
}