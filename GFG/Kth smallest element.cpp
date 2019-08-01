using namespace std;

int partition(int a[], int l, int r){
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
    return j+1;
}



int findkthsmallest(int a[], int l, int r, int k){
    int partition_index = partition(a, l, r);
    //cout<<partition_index<<endl;
    if(partition_index == k - 1){
        return a[partition_index];
    }
    else if(partition_index > k - 1){
        return findkthsmallest(a, l, partition_index - 1, k);
    }
    else{
        return findkthsmallest(a, partition_index + 1, r, k);
    }
    
    
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
	    int k;
	    cin>>k;
	    cout<<findkthsmallest(a, 0, n-1, k)<<endl;
	    //for(int i = 0; i < n; i++){
	    //    cout<<a[i]<<" ";
	    //}
	    //cout<<endl;
	}
	return 0;
}
