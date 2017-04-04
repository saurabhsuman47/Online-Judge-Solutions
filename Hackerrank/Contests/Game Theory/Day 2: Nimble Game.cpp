#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;


int main() {
   int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sol=0;
        ll t1;
        for(ll i=0;i<n;i++){
            cin>>t1;
            if(i==0)continue;
            if(t1%2){
                sol^=i;
            }
            
        }
        //cout<<sol<<endl;
        if(sol==0){
            cout<<"Second"<<endl;
        }
        else{
            cout<<"First"<<endl;
        }
    }
}

