#include <bits/stdc++.h>
using namespace std;

void fillDp(vector<vector<int>> &dp,vector<pair<int,int>> &items);
vector<int> picked(vector<vector<int>> &dp,vector<pair<int,int>> &items);

int main(){
    int size;
    cout << "enter size of knapsack:";
    cin >> size;
    int nuOfItems;
    cout << "enter no of items:";
    cin >> nuOfItems;
    //taking items in vector:
    vector<pair<int,int>> items;
    cout << "enter weights and values of items :\n";
    int weight,value;
    for(int i = 1;i <= nuOfItems;++i){
        cout << "weight and value of item-" << i << ":->";
        cin >> weight >> value;
        items.push_back(make_pair(weight,value));
    }
    //making a 2d vector for applying dynamic approach:
    vector<vector<int>> dp;
    //here no of rows = no of items
    dp.resize(nuOfItems);
    //and no of columns = size of knapsack + 1(for weight 0)
    for(int i = 0;i < dp.size();++i){
        dp[i].resize(size+1);
    }
    //now filling the Dp array:
    fillDp(dp,items);
    cout << "max value which we can get is => " << dp[dp.size()-1][dp[0].size()-1] << "\n";
    //now if you want to get items that you have picked:
    
    vector<int> pickedItems = picked(dp,items);
    cout << "index of the item picked:";
    for(int i = pickedItems.size()-1;i >= 0;--i)
        cout << pickedItems[i] << " ";
    
    return 0;
}

void fillDp(vector<vector<int>> &dp,vector<pair<int,int>> &items){
    //storing no of rows and columns:
    int rows = dp.size(),columns = dp[0].size();
    //filling first column as zero:
    for(int i = 0;i < rows;++i)
        dp[i][0] = 0;
    //now filling the dp array:
    for(int i = 0;i < rows;++i){
        for(int j = 1;j < columns;++j){
            //for first row if weight is less than the weight of first item set it zero
            //else set it to the value of first item:
            if(i == 0){
                if(j < items[0].first)
                    dp[0][j] = 0;
                else
                    dp[0][j] = items[0].second;
            }
            else{
                //if weight is less than the weight of item than do not add it
                //hence same as previous value:
                if(j < items[i].first)
                    dp[i][j] = dp[i-1][j];
                else{
                    //here we are going to pick maximum of two values:
                    //first is if we are not picking the item hence previous value:
                    int f = dp[i-1][j];
                    //second we pick the item hence total is sum of weight of this value
                    //and best value that we have till now for remaining weight:
                    int s = items[i].second + dp[i-1][j-items[i].first];
                    //now store the maximum value:
                    dp[i][j] = max(f,s);
                }
            }
        }
    }
    //just for debugging purpose
    /*
    for(int i = 0;i < rows;++i){
        for(int j = 0;j < columns;++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    */
}

vector<int> picked(vector<vector<int>> &dp,vector<pair<int,int>> &items){
    //array to store picked items:
    vector<int> pickedItems;
    //start from the bottom right most value:
    int startRow = dp.size()-1,startCol = dp[0].size()-1;
    //make a loop until we are in dp array:
    while(startRow >= 0 and startCol > 0){
        //if this value has come from previous than jump to previous:
        while(startRow > 0 and dp[startRow][startCol] == dp[startRow-1][startCol])
            --startRow;
        //else pick this item:
        pickedItems.push_back(startRow);
        //space in knapsack is reduced by the picked weight:
        startCol -= items[startRow].first;
        //go to the previous item:
        --startRow;
    }
    return pickedItems;
}
