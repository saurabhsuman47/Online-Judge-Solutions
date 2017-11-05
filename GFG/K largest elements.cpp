#include<iostream>
#include<queue>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int temp;
	    priority_queue<int> pq;
	    for(int i = 0; i < n; i++){
	        cin>>temp;
	        pq.push(temp);
	    }
	    for(int i = 0; i < k; i++){
	        cout<<pq.top()<<" ";
	        pq.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
