class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size() > b.size()){
            a.swap(b);
        }
        int m = a.size();
        int n = b.size();
        int is = 0;
        int ie = m;
        while(is <= ie){
            int i = (is + ie)/2;
            int j = (m + n + 1 - 2*i) / 2;
            if((i == 0 || j ==n || a[i-1] <= b[j]) && (j == 0 || i == m || b[j-1] <= a[i])){
                if((m + n) % 2 == 1){
                    int t1 = (i != 0) ? a[i - 1] : b[j - 1];
                    int t2 = (j != 0) ? b[j - 1] : a[i - 1];
                    double sol = 1.0 * max(t1, t2);
                    return sol;
                }
                else{
                    int t1 = (i != 0) ? a[i - 1] : b[j - 1];
                    int t2 = (j != 0) ? b[j - 1] : a[i - 1];
                    int t3 = (i != m) ? a[i] : b[j];
                    int t4 = (j != n) ? b[j] : a[i];
                    double sol =  1.0 * (max(t1, t2) + min(t3, t4));
                    sol /= 2.0;
                    return sol;
                }
                
            }
            else if(i != 0 && j != n && a[i-1] > b[j]){
                ie = i - 1;
            }
            else{
                is = i + 1;
            }
        }
    }
};
