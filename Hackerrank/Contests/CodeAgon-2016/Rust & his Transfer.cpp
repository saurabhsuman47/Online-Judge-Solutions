#include <bits/stdc++.h> 
using namespace std;

const int N=3005;
const int inf=100000009;

#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)
#define sc(x) scanf("%d",&(x))


int a[N][N][2];
int vis[N][2];
int cost[N][2];
typedef pair<int, int> pii;
priority_queue< pii, vector<pii >,greater< pii > > mypq;

void dijkstra(int S,int n,int D){
	mypq = priority_queue< pii, vector<pii >,greater< pii > > ();
	fori(n+1){
		cost[i][0]=5*inf;
		cost[i][1]=5*inf;
	}
	cost[S][0]=0;cost[S][1]=0;
	pii mypair;
	mypair.first=cost[S][0];
	mypair.second=S;
	mypq.push(mypair);
	
	while(!mypq.empty()){
		mypair=mypq.top();
		mypq.pop();
		int val=mypair.first;
		int node=mypair.second;
		vis[node][0]=1;
		fori(n+1){
			if(a[node][i][0]!=inf && vis[i][0]==0){
				if(cost[node][0]+a[node][i][0]<cost[i][0]){
					cost[i][0]=cost[node][0]+a[node][i][0];
					mypair.first=cost[i][0];
					mypair.second=i;
					mypq.push(mypair);
				}
				
			}
		}
	}
	if(vis[D][0]==0){
		cout<<"-1"<<endl;
	}
	else{

		mypq = priority_queue< pii, vector<pii >,greater< pii > > ();
		mypair.first=cost[S][1];
		mypair.second=S;
		mypq.push(mypair);
		while(!mypq.empty()){
			mypair=mypq.top();
			mypq.pop();
			int val=mypair.first;
			int node=mypair.second;
			if(vis[node][1]==1)continue;
			vis[node][1]=1;
			fori(n+1){
				if(a[node][i][1]!=inf && vis[i][1]==0){
					int t1=cost[node][0]+a[node][i][1];
					int t2=cost[node][1]+a[node][i][0];
					//if(node==S)t2=t1;
					int t3=min(t1,t2);
					if(t3<cost[i][1]){
						cost[i][1]=t3;
						mypair.first=cost[i][1];
						mypair.second=i;
						mypq.push(mypair);
					}
					
				}
			}
		}

		cout<<min(cost[D][0],cost[D][1])<<endl;
		
	}

}
void init(){
	fori(N){
		forj(N){
			a[i][j][0]=inf;
			a[i][j][1]=inf;
		}
		forj(2){
			vis[i][j]=0;
			cost[i][j]=0;
		}
	}

}


////************
int main()
{	
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	sc(t);
	while(t--){
		init();
		int n,m;
		sc(n);sc(m);
		fori(m){
			int x,y,r,t;
			sc(x);sc(y);
			sc(r);sc(t);
			a[x][y][0]=min(a[x][y][0],r);
			a[x][y][1]=min(a[x][y][1],t);
			a[y][x][0]=min(a[y][x][0],r);
			a[y][x][1]=min(a[y][x][1],t);
		}
		int S,D;
		sc(S);
		sc(D);
		dijkstra(S,n,D);
	}
	
}