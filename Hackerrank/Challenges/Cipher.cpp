#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int n,k;
    cin>>n>>k;
    int bit[n];
    string s;
    cin>>s;    
    int t1=0;
    
    for(int i=0;i<n;i++){
        bit[i]=(s[i]-'0')^t1;
        t1^=bit[i];
        if(i>=(k-1))t1^=bit[i-k+1];
    }
    
     for(int i=0;i<n;i++){
        cout<<bit[i]<" ";
    }
   
    
}

