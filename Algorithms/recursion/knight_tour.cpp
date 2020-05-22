#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#define n 8
using namespace std;
bool isSafe(int x,int y,int board[n][n]){
	if((x >= 0)&&(x < n)&&(y >= 0)&&(y < n)&&(board[x][y] == -1))
		return true;
	else
		return false;
}

bool findPath(int x,int y,int moveI,int board[n][n],int xMove[n],int yMove[n]){
	int next_x,next_y;
	if(moveI == n*n)
		return true;
	for(int i = 0;i < 8;i++){
		next_x = x + xMove[i];
		next_y = y + yMove[i];
		if(isSafe(next_x,next_y,board)){
			board[next_x][next_y] = moveI;
			if(findPath(next_x,next_y,moveI+1,board,xMove,yMove) == true)
				return true;
			else
				board[next_x][next_y] = -1;
		}
	}
	return false;
}

int main(){
	int board[n][n];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++)
			board[i][j] = -1;
	}
	board[0][0] = 0;
	int xMove[] = {2,1,-1,-2,-2,-1,1,2};
	int yMove[] = {1,2,2,1,-1,-2,-2,-1};
	if(findPath(0,0,1,board,xMove,yMove) == true){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
	}
	else
		cout << "solution is not exist!!";
}








