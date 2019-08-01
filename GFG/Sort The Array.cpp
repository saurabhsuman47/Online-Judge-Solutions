using namespace std;

int partition(int a[], int l, int r){
	  //for(int i = l; i <= r; i++){
	  //      cout<<a[i]<<" ";
	  //  }
	  //  cout<<endl;
    if(l == r)return l;
    int pivot = a[r];
    int i = l, j = r - 1;
    while(i <= j){
        if(a[i] <= pivot){
            i++;
        }
        else{
            swap(a[i], a[j]);
            j--;
        }
    }
    swap(a[j+1], a[r]);
    return j + 1;
}

void quicksort(int a[], int l, int r){
    if(l < r){
        int partition_index = partition(a, l, r);
        //cout<<partition_index<<endl;
        //cout<<"l "<<l<<" r "<<r<<endl;
        quicksort(a, l, partition_index - 1);
        quicksort(a, partition_index + 1, r);
    }
    return;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	    }
	    quicksort(a, 0, n-1);
	    for(int i = 0; i < n; i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
