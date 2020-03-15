#include <iostream>
using namespace std;

int main(){
        int R,C,r,c;
	cout << "enter dimensions of field matix:";
        cin >> R >> C;
        char A[R][C];
	cout << "enter field matrix:";
        for(int i = 0;i < R;i++){
            for(int j = 0;j < C;j++)
                cin >> A[i][j];
        }
	cout << "enter dimensions of matrix to be searched:";
        cin >> r >> c;
        char B[r][c];
	cout << "enter matrix to be searched:";
        for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++)
            cin >> B[i][j];
        }
        int sw1;
       for (int i = 0; i <= (R-r); i++) {
            for (int j = 0; j <= (C-c); j++){
sw1 = 0;
                for (int k = i; k < (i+r); k++) {
                    for (int l = j; l < (j+c); l++){
if(A[k][l] != B[k-i][l-j]){
sw1 = 1;
break;
}
                    }
if(sw1 == 1)
break;
             }
		if(sw1 == 0)
		break;
            }
		if(sw1 == 0)
		break;
        }
        if(sw1 == 0)
            cout << "YES!!,it's present";
        else
            cout << "Nope,better luck next time☺️";
    }
