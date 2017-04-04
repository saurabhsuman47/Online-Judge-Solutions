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
        int sol=0;
        int t1;
        for(int i=0;i<n;i++){
            cin>>t1;
            sol^=t1;
        }
        //cout<<sol<<endl;
        if(sol==0)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}

