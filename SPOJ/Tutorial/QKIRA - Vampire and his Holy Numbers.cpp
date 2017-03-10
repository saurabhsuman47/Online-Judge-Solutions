
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const ll N=100003;



#define fori(n) for(ll i=0;i<n;i++)
#define forj(n) for(ll j=0;j<n;j++)
#define fork(n) for(ll k=0;k<n;k++)
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))

int a[N];
int tree[4*N];

int gcd(int a,int b){
	if(a>b)swap(a,b);
	while(a!=0){
		int temp=a;
		a=b%a;
		b=temp;
	}
	return b;
}

void init(int node,int start,int end){
	if(start==end){
		tree[node]=a[start];
		return;
	}
	int mid=(start+end)/2;
	init(node*2+1,start,mid);
	init(node*2+2,mid+1,end);
	tree[node]=gcd(tree[node*2+1],tree[node*2+2]);
	return;
}

int query(int node,int l,int r,int start,int end){
	if(start>=l && end<=r){
		return tree[node];
	}
	if(start>r || end<l){
		return 0;
	}
	int mid=(start+end)/2;
	int t1=query(node*2+1,l,r,start,mid);
	int t2=query(node*2+2,l,r,mid+1,end);
	return gcd(t1,t2);
}



////************
int main()
{	
	//freopen("input.txt","r",stdin);
	int n,q;
	sc(n);sc(q);
	fori(n){
		sc(a[i]);
	}
	init(0,0,n-1);
	fori(q){
		int l,r;
		sc(l);sc(r);
		l--;r--;
		printf("%d\n",query(0,l,r,0,n-1));
	}



	
}