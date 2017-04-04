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
        int flag=0;
        for(int i=0;i<n;i++){
            cin>>t1;
            sol^=t1;
            if(t1>1)flag=1;
        }
        if(flag==1){
             if(sol==0)cout<<"Second"<<endl;
            else cout<<"First"<<endl;
        }
        else{
            if(sol==1)cout<<"Second"<<endl;
            else cout<<"First"<<endl;
        }
       
    }
}

