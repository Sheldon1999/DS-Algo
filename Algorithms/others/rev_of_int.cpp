#include<iostream>
using namespace std;
int main (){
int n = 0,j;
cin >> j;
while(1){
            if(j == 0)
                break;
            else{
                n = (n + (j % 10)) * 10;
                if(j /10 == 0)
                n = n / 10; 
                j = j / 10;
            }
        }
cout << n;
}
