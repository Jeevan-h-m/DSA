void reverse(int* arr,int n){
    int *temp=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        temp[i]=arr[n-i-1];
    }
    for(int j=0;j<n;j++){
        arr[j]=temp[j];
    }
}
void rotate(int* nums, int numsSize, int k) {
    int *temp=(int *)malloc(numsSize*sizeof(int));
    int i;
    k=k%numsSize;
    reverse(nums,numsSize);
    for(i=0;i<k;i++){
        temp[i]=nums[i];
    }
    for(i=k;i<numsSize;i++){
        nums[i-k]=nums[i];
    }
    for(i=numsSize-k;i<numsSize;i++){
        nums[i]=temp[i-(numsSize-k)];
    }
    reverse(nums,numsSize); 
}
