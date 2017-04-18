#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    for(int z = 1; z <= t; z++){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n - 2; i++){
            int ii = i+1;
            int idx = 0;
            for(int j = 0; j < n; j++){
                if(a[j] == ii){
                    idx = j;
                    break;
                }
            }
            while(idx > i){
                if(idx >= i+2){
                    int temp = a[idx -2];
                    a[idx - 2] = a[idx];
                    a[idx] = a[idx - 1];
                    a[idx - 1] = temp;
                    idx -= 2;
                }
                else{
                    int temp = a[idx - 1];
                    a[idx - 1] = a[idx];
                    a[idx] = a[idx +1];
                    a[idx + 1] = temp;
                    idx -= 1;
                }
            }
        }
        if(a[n-2] < a[n-1])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

