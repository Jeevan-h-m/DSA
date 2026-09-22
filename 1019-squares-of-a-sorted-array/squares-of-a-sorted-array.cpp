class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>arr(nums.size());
        int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(abs(nums[l]) > abs(nums[r])){
                arr[i]=nums[l]*nums[l];
                l++;
            }
            else{
                arr[i]=nums[r]*nums[r];
                r--;
            }
        }
        return arr;

    }
};