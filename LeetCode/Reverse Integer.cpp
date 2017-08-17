class Solution {
public:
    int reverse(int x) {
        if(x == 0)return 0;
        int flag = 1;
        if(x < 0) {
            flag = -1;
            x *= -1;
        }
        vector<int> v;
        while(x > 0){
            v.push_back(x%10);
            x /= 10;
        }
        long long y = 0;
        for(int i = 0; i < v.size(); i++){
            y *= 10;
            y += v[i];
        }
        y *= flag;
        if(y > (long long)INT_MAX || y < (long long)INT_MIN){
            return 0;
        }
        else{
            return (int)y;
        }
    }
};
