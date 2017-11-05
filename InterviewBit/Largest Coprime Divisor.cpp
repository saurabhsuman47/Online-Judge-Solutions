int gcd(int x, int y){
    if(x > y)swap(x, y);
    int temp = y % x;
    if(temp == 0)return x;
    y = x;
    x = temp;
    return gcd(x, y);
}
int Solution::cpFact(int A, int B) {
   while(gcd(A,B) != 1){
       A /= gcd(A, B);
   }
   return A;
}
