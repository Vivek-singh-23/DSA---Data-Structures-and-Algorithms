#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
// recurssion
int solve(long long nstairs, int i){
    if(i == nstairs){
        return 1;
    }

    if(i > nstairs){
        return 0;
    }

    return solve(nstairs, i+1) + solve(nstairs, i+2)%MOD ;
}

// real question is now that each of the stair has it own weight
int solve1(vector<int>&cost, int n){
    if(n == 0){
        return cost[0];
    }

    if(n == 1){
        return cost[1];
    }

    int ans = cost[n] + min(solve1(cost, n-1), solve1(cost, n-2));
}


int solve2(vector<int>&cost, int n, vector<int>&dp){
    if(n == 0){
        return cost[0];
    }

    if(n == 1){
        return cost[1];
    }

    if(dp[n] != -1){
        return dp[n];
    } 

    dp[n] = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
    return dp[n];
}

int solve3(vector<int>&cost, int n){
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[0] = 0;

    for(int i=2; i<n; i++){
        dp[i] = cost[i] + min (dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);

}

int solve4(vector<int>&cost, int n){
    
    int prev1 = 1;
    int prev2 = 0;

    for(int i=2; i<n; i++){
        int curr = min(prev1, prev2) + cost[i];
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);

}

int minClimbingWeight(vector<int>&cost){
    
    // solve1
    // int n = cost.size();
    // int ans = min(solve1(cost, n-1) , solve1(cost, n-2));
    // return ans;


    // memoization and solve2
    // int n = cost.size();
    // vector<int> dp(n+1, -1);
    // int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
    // return ans;


    // tabulation and solve3
    int n = cost.size();
    return solve3(cost, n);

}






int main(){


}