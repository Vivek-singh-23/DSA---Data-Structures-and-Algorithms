#include<bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n){
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }

    long long cost = 0;
    while(pq.size()>1){
        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        int mergedLength = first+second;
        cost += mergedLength;

        pq.push(mergedLength);
    }
    return cost;
}