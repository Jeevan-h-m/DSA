class Solution {
public:
    int reverse(int x) {
        if(x > (pow(2,31)-1)|| x < -(pow(2,31)-1)){
            return 0;
        }
        int sign = (x>0)? 1:-1;
        long long rev=0;
        x=abs(x);
        while(x>0){
            rev=rev*10+x%10;
            x/=10;
        }
        if(rev > INT_MAX|| rev < INT_MIN){
            return 0;
        }
        else
            return rev*sign;
    }
};