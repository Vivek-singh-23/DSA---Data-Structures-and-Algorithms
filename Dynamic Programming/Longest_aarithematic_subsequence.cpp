#include<bits/stdc++.h>
using namespace std;

int solve(int index, int diff, int A[]){
    // backward check
    if(index < 0){
        return 0;
    }

    int ans = 0;
    for(int j=index-1; j>=0; j--){
        if(A[index] - A[j] == diff){
            ans = max(ans, 1+solve(j, diff,A));
        }
    }

    return ans;
}


int solveMem(int index, int diff, int A[], unordered_map<int, int>dp[]){
    // backward check
    if(index < 0){
        return 0;
    }

    if(dp[index].count(diff)){
        return dp[index][diff];
    }
    int ans = 0;
    for(int j=index-1; j>=0; j--){
        if(A[index] - A[j] == diff){
            ans = max(ans, 1+solveMem(j, diff, A, dp));
        }
    }
    return dp[index][diff] = ans;
}



// for above two solutions


// int lengthOfLongetsAP(int A[], int n){
//     if(n<= 2){
//         return n;
//     }

//     unordered_map<int, int>dp[n+1];
//     int ans = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             ans = max(ans, 2 + solveMem(i, A[j] - A[i], A, dp));
//         }
//     }
//     return ans;
// }



int lengthOfLongestAP(int A[], int n){
    if(n<=2){
        return n;
    }
    int ans = 0;

    unordered_map<int, int>dp[n+1];

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            int diff = A[i] - A[j];
            int cnt = 1;
            
            if(dp[j].count(diff));{
                cnt = dp[j][diff];
            }

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

int main(){

}