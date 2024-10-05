#include<bits/stdc++.h>
using namespace std;


int minDays(int S, int N, int M){
    int sunday = S/7;
    int buying = S - sunday;

    int totalFood =S*M;
    int ans = 0;

    if(totalFood % N == 0){
        ans = totalFood/N;
    }else{
        ans = totalFood/N + 1;
    }


    if(ans<= buying){
        return ans;
    }else{
        return -1;
    }
}