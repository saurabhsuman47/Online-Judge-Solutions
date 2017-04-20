#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int b[100001];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, kk;
    cin>>n>>kk;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[a[i]] = i;
    }
    int k = 0;
    for(int i = n; i >= 1; i--){
        
        int loc1 = b[i];
        int loc2 = n - i + 1;
        if(loc1 != loc2) k++;
        b[i] = loc2;
        b[a[loc2]] = loc1;
        swap(a[loc1], a[loc2]);   
        if(k == kk)break;
    }
    for(int i = 1; i <= n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

