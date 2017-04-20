#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        if(n % 3 == 0){
            for(int i = 0; i < n ;i++){
                cout<<'5';
            }            
        }
        else if(n % 3 == 1 && n >= 10){
            for(int i = 0; i < n-10 ;i++){
                cout<<'5';
            }
            for(int i = 0; i < 10; i++){
                cout<<'3';
            }
        }
        else if(n % 3 == 2 && n >= 5){
            for(int i = 0; i< n - 5; i++){
                cout<<'5';
            }
            for(int i = 0; i < 5; i++){
                cout<<'3';
            }
        }
        else cout<<"-1";
        cout<<endl;
    }
    return 0;
}

