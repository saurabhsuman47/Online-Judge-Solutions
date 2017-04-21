#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll a[100005];

bool check(ll val){
    for(int i = 1;i <= n; i++){
        if(a[i] >= val){
            val -= (a[i] - val);
        }
        else{
            val += (val - a[i]);
        }
        if(val < 0){
            return false;
        }
        if(val > 100000){
            return true;
        }
    }
    return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    cin>>n;    
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    ll start = 0;
    ll end = 100000;
    ll res = 0;
    while(start <= end){
        ll mid = (start + end)/2;
        if(check(mid) == true){
            res = mid;
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }
    cout <<res<<endl;
    return 0;
}

