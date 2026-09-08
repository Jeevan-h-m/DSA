class Solution {
public:
    bool isPalindrome(int x) { 
        if(x<0){
            return false;
        }
       int a=x;
       unsigned int revno=0;
       while(a!=0){
            
            revno=(revno*10)+a%10;
            a=a/10;
       }
       return revno == x ? true : false ;   
    }
};