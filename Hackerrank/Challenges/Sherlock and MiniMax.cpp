#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int p,q;
    cin>>p>>q;
    sort(a, a + n);
    int tmin = -1;
    int m = 0;
    for(int i = 0; i < n-1; i++){
        int mid = (a[i] + a[i + 1]) / 2;
        if(mid >= p && mid <= q){
            if(mid - a[i] > tmin){
                m = mid;
                tmin = mid - a[i];
            }
		}
		else if(mid < p && a[i + 1] >= p){
			if(a[i + 1] - p > tmin){
				m = p;
				tmin = abs(p - a[i+1]);
			}
		}
		else if(mid > q && a[i] <= q){
			if(q - a[i] > tmin){
				m = q;
				tmin = abs(q - a[i]);
			}
		}
        
    }
    if(p < a[0]){
        if(a[0] - p >= tmin){
            m = p;
            tmin = abs(p - a[0]);
        }
    }
    if(q > a[n-1]){
        if(q - a[n-1] > tmin){
            m = q;
            tmin = abs(q - a[n-1]);
        }
    }
    cout<<m<<endl;
    return 0;
}

