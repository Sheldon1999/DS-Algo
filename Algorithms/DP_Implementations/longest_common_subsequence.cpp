#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int lenComSub(string s1,string s2,vector<vector<int>> &dp);
vector<char> comSub(string s1,string s2,vector<vector<int>> &dp);

int main(){
    string s1,s2;
    cout << "enter the first string :";
    cin >> s1;
    cout << "enter the second string :";
    cin >> s2;
    //make a dp array:
    vector<vector<int>> dp;
    int lengthSub = lenComSub(s1,s2,dp);
    cout << "maximum length of common subsequence :" << lengthSub << endl;
    //array to store common Subsequence:
    vector<char> commSub = comSub(s1,s2,dp);
    cout << "hence the subsequence : ";
    for(int i = commSub.size()-1;i >= 0;--i)
        cout << commSub[i];
}

int lenComSub(string s1,string s2,vector<vector<int>> &dp){
    int len1 = s1.length(),len2 = s2.length();
    //number of rows = len of s1 + 1(for only zero):
    dp.resize(len1+1);
    for(int i = 0;i <= len1;++i){
        //number of columns = len of s2 + 1(for only zero):
        dp[i].resize(len2+1);
        //real operation begins at (1,1):
        if(i > 0){
            for(int j = 1;j <= len2;++j){
                //here 2 cases arise:
                //first case: if character are not equal
                if(s1[i-1] != s2[j-1]){
                    //hence we need not include it in subsequence
                    //hence we add boththe values above and previous of it;
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                //second case: if character are not equal
                else{
                    //hence we need toinclude it
                    //and now we add the value just before this index + 1
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
        }
    }
    //just for debugging:
    /*
    for(int i = 0;i <= len1;++i){
        for(int j = 0;j <= len2;++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    */
    //now return the last value which is the answer:
    return dp[dp.size()-1][dp[0].size()-1];
}

vector<char> comSub(string s1,string s2,vector<vector<int>> &dp){
    vector<char> commSub;
    //start from the last:
    int startRow = dp.size()-1,startCol = dp[0].size()-1;
    //iterate untill both pointers are inside string area:
    while(startRow >= 1 and startCol >= 1){
        //check if this value is equal to the above or the previous value:
        if(dp[startRow][startCol] == dp[startRow-1][startCol])
            --startRow;
        else if(dp[startRow][startCol] == dp[startRow][startCol-1])
            --startCol;
        //if its value is just one greater than the just before(diagonally upper left) value:
        else if(dp[startRow][startCol] == dp[startRow-1][startCol-1]+1){
            //than this value must be added in sequence:
            commSub.push_back(s1[startRow-1]);
            //iterate to the new position:
            --startRow;
            --startCol;
        }
    }
    return commSub;
}
