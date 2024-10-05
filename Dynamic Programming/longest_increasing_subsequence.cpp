#include<bits/stdc++.h>
using namespace std;

int solve(int n, int a[], int curr, int prev){
    if(curr == n){
        return 0;
    }

    int take = 0;
    if(prev == -1 || a[curr] > a[prev]){
        take =  1 + solve(n, a, curr + 1, curr);
    }

    int notake = 0 + solve(n, a, curr + 1, prev);

    return max(take, notake);
}

int solveMem(int n, int a[], int curr, int prev, vector<vector<int>>&dp){
    if(curr == n){
        return 0;
    }

    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }

    int take = 0;
    if(prev == -1 || a[curr] > a[prev]){
        take =  1 + solveMem(n, a, curr + 1, curr, dp);
    }

    int notake = 0 + solveMem(n, a, curr + 1, prev, dp);

    dp[curr][prev+1] = max(take, notake);
    return dp[curr][prev+1];
}


int solveTab(int n, int a[]){
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    for(int curr=n-1; curr>=0; curr--){
        for(int prev=curr-1; prev>=-1; prev--){
            int take = 0;
            if(prev == -1 || a[curr] > a[prev]){
                take =  1 + dp[curr + 1][curr + 1];
            }

            int notake = 0 + dp[curr + 1][prev+1];

            dp[curr][prev+1] = max(take, notake);
        }
    }
    return dp[0][0];
}


int spaceO(int n, int a[]){
    vector<int>currRow(n+1, 0);
    vector<int>nextRow(n+1, 0);
    for(int curr=n-1; curr>=0; curr--){
        for(int prev=curr-1; prev>=-1; prev--){
            int take = 0;
            if(prev == -1 || a[curr] > a[prev]){
                take =  1 + nextRow[curr + 1];
            }

            int notake = 0 + nextRow[prev+1];

            currRow[prev+1] = max(take, notake);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}


int solveOptimal(int n, int a[]){
    if(n == 0){
        return 0;
    }

    vector<int>ans;
    ans.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(a[i] > ans.back()){
            ans.push_back(a[i]);
        }else{
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i]; 
        } 
    }

    return ans.size();
}




int longestsubsequenceLength(int n, int a[]){
    vector<vector<int>>dp(n, vector<int>(n+1, -1));
    return solve(n, a, 0, -1);
}

int main(){

}