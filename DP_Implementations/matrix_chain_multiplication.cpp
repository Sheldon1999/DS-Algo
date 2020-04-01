#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

string orderMul(vector<pair<int,int>> &matDim);

int main(){
    cout << "enter no of matrices:";
    int noOfMat;
    cin >> noOfMat;
    //store dimensions of matrices:
    vector<pair<int,int>> matDim;
    int row,col;
    for(int i = 1;i <= noOfMat;++i){
        cout << "enter the dimensions of matrix-" << i << ":";
        cin >> row >> col;
        matDim.push_back(make_pair(row,col));
    }
    //string to store order of multiplication:
    string orMul = orderMul(matDim);
    cout << "order of multiplication with minimum cost is : " << orMul;

    return 0;
}

string orderMul(vector<pair<int,int>> &matDim){
    //making an array for DP and other one to store the order:
    vector<vector<int>> dp;
    vector<vector<string>> order;
    //storing no of matrices:
    int noOfMat = matDim.size();
    //its size must be equal to the no of matrices:
    dp.resize(noOfMat);
    order.resize(noOfMat);
    for(int i = 0;i < noOfMat;++i){
        dp[i].resize(noOfMat);
        order[i].resize(noOfMat);
    }
    //now starting from length 1 and after than increase it:
    for(int len = 1;len <= noOfMat;++len){
        //for every len we need to fill the dp array
        //diagonally rightside upwards:
        int startRow = 0,startCol = len-1;
        while(startRow < noOfMat and startCol < noOfMat){
            //for len = 1 there is no cost:
            if(len == 1){
                dp[startRow][startCol] = 0;
                order[startRow][startCol].push_back(char(startRow+1+'0'));
            }
            else{
                //find the minimum between all combinations:
                //variable to store maximum and order:
                int mx = INT_MAX,pos;
                string ord,itord;
                //make a loop to go through all the possible positions
                //through which multiplication can be done:
                for(int k = 1;k < len;++k){
                    pos = startRow + k;
                    //now cost is sum of whole multipliction of left and right of this position
                    //and than the whole through this position:
                    int cost = dp[startRow][pos-1] + dp[pos][startCol] + matDim[startRow].first*matDim[pos].first*matDim[startCol].second;
                    itord = "(" + order[startRow][pos-1] + "," + order[pos][startCol] + ")";
                    if(cost < mx){
                        mx = cost;
                        ord = itord;
                    }
                }
                dp[startRow][startCol] = mx;
                order[startRow][startCol] = ord;
            }
            ++startRow;
            ++startCol;
        }
    }
    //just for debugging:
    /*
    for(int i = 0;i < dp.size();++i){
        for(int j = 0;j < dp[i].size();++j)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << endl;
    for(int i = 0;i < dp.size();++i){
        for(int j = 0;j < dp[i].size();++j)
            cout << order[i][j] << " ";
        cout << "\n";
    }
    */

    return order[0][order[0].size()-1];
}
