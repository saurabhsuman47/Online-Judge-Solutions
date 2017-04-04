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
        int n,m;
        cin>>n>>m;
        if(n%2==0){
            cout<<"2"<<endl;
        }
        else{
            if(m>1){
                cout<<"1"<<endl;
            }
            else{
                cout<<"2"<<endl;
            }
        }
    }
    return 0;
}

