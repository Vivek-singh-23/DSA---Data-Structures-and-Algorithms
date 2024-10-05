#include<bits/stdc++.h>
using namespace std;

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

int longestPlaindromicSubsequence(string s){
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    return spaceO(s, revStr);
}

int main(){

}