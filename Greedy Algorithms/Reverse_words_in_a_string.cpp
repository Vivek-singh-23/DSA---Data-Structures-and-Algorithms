#include<bits/stdc++.h>
using namespace std;

string reverseWord(string s){
    string ans = "";
    string temp = "";

    for(int i=s.length()-1; i>=0; i--){
        if(s[i] == '.'){
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans.push_back('.');
            temp="";
        }else{
            temp.push_back(s[i]);
        }
    }

    reverse(temp.begin(), temp.end());
    ans += temp;
    temp="";

    return ans;
}