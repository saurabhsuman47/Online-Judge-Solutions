#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int ull;


int main() {
    int t;
    cin>>t;
    ull a[64];
    a[0]=1;
    for(int i=1;i<=63;i++){
        a[i]=2*a[i-1];
    }
    while(t--){
        ull n;
        cin>>n;
        int count=0;
        while(n!=1){
            int idx=63;
            for(int i=0;i<=63;i++){
                if(a[i]>=n)break;
                idx=i;
            }
            n-=a[idx];
            count++;
            //cout<<n<<endl;
        }
        if(count%2)cout<<"Louise"<<endl;
        else cout<<"Richard"<<endl;
    }
    
}

