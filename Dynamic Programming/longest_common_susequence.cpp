#include<bits/stdc++.h>
using namespace std;

int solve(string &a, string&b, int i, int j){
    if(i == a.length()){
        return 0;
    }

    if(j == b.length()){
        return 0;
    }

    int ans = 0;
    if(a[i] == b[j]){
        return 1 + solve(a, b, i+1, j+1);
    }else{
        ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
    }

    return ans;
}


int solveMem(string &a, string&b, int i, int j, vector<vector<int>>&dp){
    if(i == a.length()){
        return 0;
    }

    if(j == b.length()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(a[i] == b[j]){
        return 1 + solve(a, b, i+1, j+1);
    }else{
        ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
    }

    return dp[i][j] = ans;
}

int solveTab(string&a, string&b){
    vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 0));

    for(int i=a.length()-1; i>=0; i--){
        for(int j=b.length()-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j]){
                return 1 + dp[i+1][j+1];
            }else{
                ans = max(dp[i+1][j], dp[i][j+1]);
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}


int spaceO(string&a, string&b){
    vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 0));

    vector<int>curr(b.length()+1, 0);
    vector<int>next(b.length()+1, 0);


    for(int i=a.length()-1; i>=0; i--){
        for(int j=b.length()-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j]){
                return 1 + next[j+1];
            }else{
                ans = max(next[j], curr[j+1]);
            }

            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int longestCommonSubsequence(string text1, string text2){
    vector<vector<int>>dp(text1.length(), vector<int>(text2.length(), -1));
    return solveMem(text1, text2, 0, 0, dp);
}

int main(){

}