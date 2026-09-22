class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]*nums[i]);
        }
        for(int i=0;i<=n-2;i++){
            int min=i;
            for(int j=i;j<=n-1;j++){
                if(temp[j]<temp[min]){
                    min=j;
                }
            }
            int a=temp[min];
            temp[min]=temp[i];
            temp[i]=a;
        }

        return temp;
    }
};