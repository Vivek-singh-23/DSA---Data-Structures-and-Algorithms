#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    dp[1] = nums[1];

    for(int i=2; i<nums.size(); i++) {
        int inc = dp[i-2] + nums[i];
        int exc = dp[i-1];

        dp[i] = max(inc, exc);
    }

    return dp[nums.size() - 1];
}

int maxAmount(vector<int>v){
    int n = v.size();
    if(n == 1){
        return v[n];
    }

    vector<int> first, second;
    for(int i=0; i<n; i++){
        if(i != n-1){
            first.push_back(v[i]);
        }

        if(i != 0){
            second.push_back(v[i]);
        }
    }

    return max(solve(first), solve(second));

}