#include<bits/stdc++.h>
using namespace std;


int main(){
    // creation
    unordered_map<string, int> m;

    // insertion

    // 1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // 2
    pair<string, int> pair2("love", 4);
    m.insert(pair2);

    // 3
    m["mera"] = 4;

    cout<<m["mera"]<<endl;
    cout<<m.at("mera")<<endl;
    cout<<m.count("mera")<<endl; // type binary function
    cout<<m.erase("love")<<endl;
    cout<<m.size()<<endl;

    // method 1 for iteration
    for(auto i:m){
        cout<<i.first <<" "<<i.second<<endl;
    }


    // method 2 for iteration
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first <<" "<<it->second<<endl;
        it++;
    }

    // Hash function conponents;
    // 1)Hash code - converts anything to integer
    // 2)compression function - adjusts integers of hash code to range


    // collision handling types
    // 1)  Open Hashing or seprate chaining
    // 2)  closed Addressing -> H(i) = h(i) + f(i);
    //  2.1)Linear Probing f(i) = i;
    //  2.2)Quadratic Probing f(i) = i*i;
}