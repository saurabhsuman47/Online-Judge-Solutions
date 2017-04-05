#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    scanf("%d",&t);
    while(t--)
        {
        int n,k;
        scanf("%d",&n);
        scanf("%d",&k);
        int count=0,t1;
        for(int i=0;i<n;i++)
        {
          scanf("%d",&t1);
            if(t1<=0)count++;
            
        }
        if(count>=k)printf("%s\n","NO");
        else printf("%s\n","YES");
            
        
    }
        
    return 0;
}

