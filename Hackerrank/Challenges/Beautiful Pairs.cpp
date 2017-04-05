#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int aa[1001];
int bb[1001];

int main() {
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        aa[a[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        bb[b[i]]++;
    }
    int flag=0;
    int sol=0;
    for(int i=0;i<=1000;i++){
        if(aa[i]!=bb[i])flag=1;
        sol+=min(aa[i],bb[i]);
    }
    if(flag==0)sol-=1;
    else sol+=1;
    cout<<sol<<endl;
    
    return 0;
}

