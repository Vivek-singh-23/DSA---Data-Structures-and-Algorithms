#include<bits/stdc++.h>
using namespace std;

bool solve(int index, int arr[], int n, int target){
    if(index >= n){
        return 0;
    }
    if(target<0){
        return 0;
    }
    if(target == 0){
        return 1;
    }

    bool incl = solve(index+1, arr, n, target - arr[index]);
    bool excl = solve(index+1, arr, n, target);

    return incl || excl;
}

bool solveMem(int index, int arr[], int n, int target, vector<vector<int>>& dp) {
    
    if (target == 0) {
        return true;  
    }
    
    if (index >= n || target < 0) {
        return false; 
    }

    if (dp[index][target] != -1) {
        return dp[index][target];
    }

    bool incl = solveMem(index + 1, arr, n, target - arr[index], dp);  
    bool excl = solveMem(index + 1, arr, n, target, dp);  

    
    return dp[index][target] = incl || excl;
}

bool solveTab(int n, int arr[], int total){
    vector<vector<int>>dp(n+1, vector<int>(total+1, 0));
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int index=n-1; index>=0; index++){
        for(int target=0; target<=total/2; target++){
            bool incl = 0;
            if(target - arr[index] >=0){
                incl = dp[index + 1][target - arr[index]]; 
            }
            bool excl = dp[index + 1][target];  

    
            return dp[index][target] = incl || excl;
        }
    }
    return dp[0][total/2];
}

bool spaceO(int n, int arr[], int total){
    
    vector<int>curr(total+1, 0);
    vector<int>next(total+1, 0);
    
    
    curr[0] = 1;
    next[0] = 1;

    for(int index=n-1; index>=0; index++){
        for(int target=0; target<=total/2; target++){
            bool incl = 0;
            if(target - arr[index] >=0){
                incl = next[target - arr[index]]; 
            }
            bool excl = next[target];  

    
            return curr[target] = incl || excl;
        }
        next = curr;
    }
    return next[total/2];
}



int equalPartition(int n, int arr[]){
    int total = 0;
    for(int i=0; i<n; i++){
        total += arr[i];
    }

    if(total&1){
        return 0;
    }

    int target = total/2;

    vector<vector<int>>dp(n, vector<int>(target+1, -1));
    return solve(0, arr, n, target);
}

int main(){

}