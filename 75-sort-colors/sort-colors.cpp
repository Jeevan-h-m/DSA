int fn(vector<int>& arr,int low,int high){
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        while(arr[i]<=pivot&&i<=high-1){
            i++;
        }
        while(arr[j]>pivot&&j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int>& nums,int low,int high){
        if(low<high){
            int partition=fn(nums,low,high);
            qs(nums,low, partition-1);
            qs(nums,partition+1,high);
        }
}
class Solution {
public:
    void sortColors(vector<int>& nums) {
        qs(nums,0,nums.size()-1);          
    }
};
