#include<bits/stdc++.h>
using namespace std;

bool solve(string str, string pattern, int i, int j){
    if(i<0 && j<0){
        return true;
    }

    if(i>=0 && j<0){
        return false;
    }

    if(i<0 && j>=0){
        for(int k=0; k<=j; k++){
            if(pattern[k] != '*'){
                return false;
            }
        }return true;
    }

    // match
    if(str[i] == pattern[i] || pattern[j] == '?'){
        return solve(str, pattern, i-1, j-1);
    }else if(pattern[j] == '*'){
        return solve(str, pattern, i-1, j) || solve(str, pattern, i, j-1);
    }else{
        return false;
    }
}


bool solveMem(string str, string pattern, int i, int j, vector<vector<int>>&dp){
    if(i<0 && j<0){
        return true;
    }

    if(i>=0 && j<0){
        return false;
    }

    if(i<0 && j>=0){
        for(int k=0; k<=j; k++){
            if(pattern[k] != '*'){
                return false;
            }
        }return true;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // match
    if(str[i] == pattern[i] || pattern[j] == '?'){
        return dp[i][j] = solveMem(str, pattern, i-1, j-1, dp);
    }else if(pattern[j] == '*'){
        return dp[i][j] = solveMem(str, pattern, i-1, j, dp) || solveMem(str, pattern, i, j-1, dp);
    }else{
        return false;
    }
}



bool isMatch(string s, string p){
    return solve(s, p, s.length()-1, p.length()-1);
}


int main(){

}