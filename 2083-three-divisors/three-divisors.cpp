class Solution {
public:
    vector<int>ls;
    bool isThree(int n) {
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                ls.push_back(i);
                if((n/i)!=i){
                    ls.push_back(n/i);
                }
            }
        }
        int size=ls.size();
        return (size==3)? true : false;
    }
};