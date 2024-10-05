#include<bits/stdc++.h>
using namespace std;


#define MOD 1000000007
int Dearrangement(int n){
    if(n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    int ans = ((n-1)%MOD)*((Dearrangement(n-1)%MOD) + ((Dearrangement(n-2))%MOD));

    return ans;
} 

int solveMem(int n, vector<int>&dp){
    if(n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = ((n-1)%MOD) * ((solveMem(n-1, dp)%MOD) + (solveMem(n-2, dp)%MOD));
    return dp[n];
}

int solveTab(int n){
    vector<int>dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = (i-1) * (((dp[i-1])%MOD ) + ((dp[i-1])%MOD))%MOD;
    }
}


int spaceO(int n){
    int prev2 = 0; 
    int prev1 = 1;

    for(int i=3; i<=n; i++){
        int ans = (i-1) * (((prev1)%MOD ) + ((prev2)%MOD))%MOD;
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;

}


int main(){

}