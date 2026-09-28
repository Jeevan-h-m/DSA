class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       
        int n=nums.size();
        vector<int>temp(n);
        k=k%n;
        //int j=0;
        for(int i=n-k;i<n;i++){
            temp[(i+k)%n]=nums[i];
        }
        for(int i=n-k-1;i>=0;i--){
            nums[(i+k)%n]=nums[i];
        }
        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
};