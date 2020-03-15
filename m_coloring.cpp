#include<iostream>
#define n 6
using namespace std;

bool fillColor(int graph[n][n],int *color,int i,int m){
    for(int j = 0;j < 7;j++){
        if(j >= m)
        return false;
        else{
            int sw = 0;
            if(i > 0){
                for(int k = 0;k < n;k++){
                    if(graph[i][k] == 1){
                        if(graph[k][k] == color[j])
                            sw = 1;
                    }
                }
            }
            if(sw == 0){
                graph[i][i] = color[j];
                if(i == 5)
                return true;
                if(fillColor(graph,color,i+1,m) == true)
                    return true;
            }
        }
    }
}

int main(){
    int graph[n][n],m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> graph[i][j];
        }
    }
    cin >> m;
    int colors[] = {2,3,4,5,6,7,8};
    if(fillColor(graph,colors,0,m) == true){
        cout << "resultant matrix:\n";
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
                cout << graph[i][j] << " ";
            cout << "\n";
        }
    }
    else
        cout << "can't be colored!!!!";
}