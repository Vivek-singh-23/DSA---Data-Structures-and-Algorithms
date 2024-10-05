#include<bits/stdc++.h>
using namespace std;

int SpaceO(vector<int>&prices, int fee){
    int n = prices.size();

    vector<int>curr(2, 0);
    vector<int>next(2, 0);

    for(int index = n-1; index>=0; index--){
        for(int buy=0; buy<=1; buy++){
            int profit = 0;
            if(buy == 1){
                profit = max((-prices[index] + next[0]) , next[1]); 
            }else{
                profit = max((prices[index] + next[1] - fee), next[0]);
            }

            curr[buy] = profit;
        }
        next = curr;
    }

    return next[1];
}



int main(){

}