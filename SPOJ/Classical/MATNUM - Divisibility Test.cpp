    #include <iostream>
    using namespace std;
    #include <stdio.h>
     
     
    #define sc(x) scanf("%d",&(x))
    #define scl(x) scanf("%lld",&(x))
    #define fori(n) for(int i=0;i<n;i++)
    #define forj(n) for(int j=0;j<n;j++)
    #define fork(n) for(int k=0;k<n;k++)
     
    typedef long long ll;
     
    int result[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    int temp[3][3];
     
    void mat_exp(ll n,int mod){
    	fori(3){
    		forj(3){
    			if(i==j)result[i][j]=1;
    			else result[i][j]=0;
    		}
    	}
        // fori(3){
        //             forj(3){
        //                cout<<result[i][j]<<" ";
        //             }
        //             cout<<endl;
        //         }
     
    	int a[3][3]={{10,4,1},{0,4,1},{0,1,0}};
    	
     
    	while(n!=0){
    		if(n%2==1){			
    			fori(3){
    				forj(3){
    					temp[i][j]=0;
    					fork(3){
    						temp[i][j]+=(result[i][k]*a[k][j]);
    					}
    				}
    			}
    			fori(3){
    				forj(3){
    					result[i][j]=temp[i][j]%mod;
    				}
    			}
    		}
    		fori(3){
    			forj(3){
    				temp[i][j]=0;
    				fork(3){
    					temp[i][j]+=(a[i][k]*a[k][j]);
    				}
    			}
    		}
    		fori(3){
    			forj(3){
    				a[i][j]=temp[i][j]%mod;
    			}
    		}
    		n/=2;
    	}
    }
     
     
    int main() 
    {	//freopen("input.txt","r",stdin);
    	
    	int t;
    	sc(t);
    	while(t--){
    		int p0,p1,q;ll n;
    		sc(p0);sc(p1);sc(q);scl(n);

    		int flag=0;
    		int init_matrix[3][1]={p0*10+p1,p1,p0};
    		
     
    		if(n==1){
    			if(p0%q==0)flag=1;
    		}
    		else{
    			int t1=0;
    			mat_exp(n-2,q);
                // fori(3){
                //     forj(3){
                //        cout<<result[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
    			fork(3){
    				t1+=(result[0][k]*init_matrix[k][0]);
    			}
                //cout<<t1<<endl;
    			if(t1%q==0)flag=1;
     
    		}
    		if(flag==1)printf("%s\n","YES");
    		else printf("%s\n","NO");
     
    	}
     
    }  