#include<iostream>
#include<stack>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int b[n];
	    stack<int> s;
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
            while(!s.empty() && a[s.top()] < a[i]){
                b[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
	    while(!s.empty()){
            b[s.top()] = -1;
            s.pop();
        }
        for(int i = 0; i < n; i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}
