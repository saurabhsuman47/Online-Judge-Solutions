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
        ll a,b;
        cin>>a>>b;
        ll sol=0;
        ll idx=32;
        while(idx>=0){
            ll mask=((ll)1<<idx);
            ll t1=mask&a;
            if(t1==0){
                ll t2=mask|sol;
                if(t2<=b){
                    break;
                }
            }
            else{
                sol+=mask;
            }
            idx--;
        }
        cout<<sol<<endl;
    }
}

