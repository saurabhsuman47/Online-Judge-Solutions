#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[1005][1005];
int vis[1005];
int d[1005];

void bfs(int s, int n, int val){	
	vis[s]=val;
	queue<int> myqueue;
	myqueue.push(s);
	while(!myqueue.empty()){
		int t1=myqueue.front();		
		for(int u = 1; u <= n; u++){
			if(a[t1][u] == 1 && vis[u]==0){
				myqueue.push(u);
				vis[u]=val;
			}
		}
		myqueue.pop();
	}
}
void dfs(int s, int n, int val){
	vis[s] = val;
	for(int u = 1; u <= n; u++){
		if(a[s][u] == 1 && s ){
			if(vis[u]==0){
				dfs(u, n, val);
			}
			// else{
			// 	a[s][u] = 0;
			// 	a[u][s] = 0;
			// }
		}
	}

}
void bfs1(int s, int n, int val){
	for(int i=1;i<=n;i++){
		if(vis[i] == val)vis[i] = 0;
		d[i]=0;
	}
	vis[s]=val;
	d[s] = 1;
	queue<int> myqueue;
	myqueue.push(s);
	while(!myqueue.empty()){
		int t1=myqueue.front();		
		for(int u = 1; u <= n; u++){
			if(a[t1][u] == 1 && vis[u]==0){
				myqueue.push(u);
				vis[u]=val;
				d[u] = d[t1] + 1;
			}
		}
		myqueue.pop();
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for(int z = 1; z <= t; z++){
		
		int n;
		cin>>n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				a[i][j] = 0;
				a[j][i] = 0;
			}
			vis[i] = 0;
			
		}
		for(int i = 1; i <= n; i++){
			int t1;
			cin>>t1;
			a[i][t1] = 1;
			a[t1][i] = 1;
		}
		int val = 1;
		int globalmax = -1;
		for(int j = 1; j <= n; j++){
			if(vis[j] == 0){
				dfs(j, n, val);
				bfs1(j, n, val);
				int maxdist=-1;
				int imaxdist=0;
				for(int i=1;i<=n;i++)
				{
					cout<<d[i]<<" ";
					if(vis[i] == val && d[i]>maxdist){maxdist=d[i];imaxdist=i;}
				}
				cout<<endl;
				cout<<maxdist<<" | "<<imaxdist<<endl;
				bfs1(imaxdist, n, val);
				maxdist=-1;
				for(int i=1;i<=n;i++)
				{
					if(vis[i] == val && d[i]>maxdist)maxdist=d[i];
				}
				if(maxdist > globalmax){
					globalmax = maxdist;
				}
				val++;
			}
		}
		for(int i = 1; i <= n; i++){
			cout<<i<<" "<<vis[i]<<endl;
		}





		cout<<"Case #"<<z<<": "<<globalmax<<endl;
	}
	


}

