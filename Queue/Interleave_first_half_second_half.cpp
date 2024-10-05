#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        vector<int>ans;
        queue<int>newQ;
        
        for(int i=0; i<n/2; i++){
            int val = q.front();
            newQ.push(val);
            q.pop();
        }
        
        while(!newQ.empty()){
            int val1 = newQ.front();
            newQ.pop();
            ans.push_back(val1);
            
            int val2 = q.front();
            q.pop();
            ans.push_back(val2);
        }
        
        return ans;
        
    }
};