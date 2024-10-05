#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    string ans = "";
		    
		    vector<int>count(26, 0);
		    
		    queue<char>q;
		    
		    for(int i=0; i<A.length(); i++){
		        char ch = A[i];
		        
		        count[ch - 'a']++;
		        
		        q.push(ch);
		        while(!q.empty()){
		            if(count[q.front() - 'a'] > 1){
		                q.pop();
		            }else{
		                ans += q.front();
		                break;
		            }
		        }
		        
		        if(q.empty()){
		            ans += '#';
		        }
		    }
		    
		    return ans;
		}

};
