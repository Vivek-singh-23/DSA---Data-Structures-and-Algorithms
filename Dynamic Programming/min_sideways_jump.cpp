#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& obstacle, int currlane, int currpos) {
    // because size of obstacle is n+1;
    int n = obstacle.size() - 1;
    if (currpos == n) {
        return 0;
    }

    if (obstacle[currpos + 1] != currlane) {
        return solve(obstacle, currlane, currpos + 1);
    } else {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++) {
            if (currlane != i && obstacle[currpos] != i) {
                ans = min(ans, 1 + solve(obstacle, i, currpos));
            }
        }
        return ans;
    }
}


int solveMem(vector<int>& obstacle, int currlane, int currpos, vector<vector<int>>&dp) {
    // because size of obstacle is n+1;
    int n = obstacle.size() - 1;
    if (currpos == n) {
        return 0;
    }

    if(dp[currlane][currpos] != -1){
        return dp[currlane][currpos];
    }

    if (obstacle[currpos + 1] != currlane) {
        return solveMem(obstacle, currlane, currpos + 1, dp);
    } else {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++) {
            if (currlane != i && obstacle[currpos] != i) {
                ans = min(ans, 1 + solveMem(obstacle, i, currpos, dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}


int solveTab(vector<int>& obstacle) {
    int n = obstacle.size() - 1;
    vector<vector<int>>dp(4, vector<int>(obstacle.size(), 1e9));
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for(int currpos=n-1; currpos>=0; currpos++){
        for(int currlane=1; currlane<=3; currlane++){
            if (obstacle[currpos + 1] != currlane) {
               dp[currlane][currpos] =  dp[currlane][currpos + 1];
            } else {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++) {
                    if (currlane != i && obstacle[currpos] != i) {
                        ans = min(ans, 1 + dp[i][currpos+1]);
                    }
                }
                dp[currlane][currpos] = ans;
            }
        }
    }

    return min({dp[2][0], 1+dp[1][0], 1+dp[3][0]});
}

int spaceO(vector<int>& obstacle) {
    int n = obstacle.size() - 1;

    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for(int currpos=n-1; currpos>=0; currpos++){
        for(int currlane=1; currlane<=3; currlane++){
            if (obstacle[currpos + 1] != currlane) {
               curr[currlane] =  next[currlane];
            } else {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++) {
                    if (currlane != i && obstacle[currpos] != i) {
                        ans = min(ans, 1 + next[i]);
                    }
                }
                curr[currlane] = ans;
            }
        }
        curr = next;
    }

    return min({next[2], 1+next[1], 1+next[3]});
}






int minSideJumps(vector<int>&obstacle){
    vector<vector<int>>dp(4, vector<int>(obstacle.size() + 1));
    return solve(obstacle, 2, 0);
}


int main(){

}