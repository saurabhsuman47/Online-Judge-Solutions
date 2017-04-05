#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1000000007ll;

ll exp(int n){
    ll result=1;
    ll a=2;
    while(n!=0){
        if(n%2==1){
            result=(result*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return result;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        ll t1=0,t2;
        for(int i=0;i<n;i++){
            cin>>t2;
           t1|= t2;
        }
        t1=(t1*exp(n-1))%mod;
        cout<<t1<<endl;
    }
}

