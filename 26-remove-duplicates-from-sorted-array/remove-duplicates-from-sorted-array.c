int removeDuplicates(int* nums, int numsSize) {
    int i,j,k=1;
    for(i=1;i<numsSize;i++){
        if(nums[i]!=nums[i-1]){
            nums[k++]=nums[i];
        
        }
    }
    return k;
}