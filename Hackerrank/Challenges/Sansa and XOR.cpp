#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int result=0;
        for(int i=1;i<=n;i++){
            int t1;
            cin>>t1;
            long long int t2=(long long int)(i)*(n-i+1);
            //cout<<t2<<" ";
            if(t2%2)result^=t1;
        }
        //cout<<endl;
        cout<<result<<endl;
    }
}

