#include<iostream>
#include<vector>
#define n 8
using namespace std;
int xPos[n*n];
int yPos[n*n];
int top = -1;

void pushStack(int x,int y){
    top++;
    xPos[top] = x;
    yPos[top] = y;
}

void popStack(){
    top--;
}

bool isSafe(int x,int y,int sol[n][n]){
    int sw = 0;
    for(int i = top;i >= 0;i--){
        if((x == xPos[i])||(y == yPos[i])||(x+y == (xPos[i]+yPos[i]))||(x-y == (xPos[i]-yPos[i]))){
            sw = 1;
            break;
        }
    }
    if((top == -1)&&(x >= 0)&&(x < n)&&(y >= 0)&&(y < n)&&(sol[x][y] == 0))
        return true;
    else if((sw == 0)&&(x >= 0)&&(x < n)&&(y >= 0)&&(y < n)&&(sol[x][y] == 0))
        return true;
    else
        return false;
}

bool putQueen(int row,int column,int sol[n][n],int QueenNo){
    for(int i = 0;i < n;i++){
        if(isSafe(row,i,sol) == true){
            sol[row][i] = QueenNo;
            pushStack(row,i);
		if(QueenNo == n)
			return true;
            if(putQueen(row+1,i,sol,QueenNo+1) == true){
                return true;
            }
            else{
                sol[row][i] = 0;
                popStack();
            }
        }
    }
    return false;
}

int main(){
    int A[n][n] = {0};
    if(putQueen(0,0,A,1) == true){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
                cout << A[i][j] << " ";
            cout << "\n";
        }
    }
    else
        cout << "somthing is wrong!!!";
}
