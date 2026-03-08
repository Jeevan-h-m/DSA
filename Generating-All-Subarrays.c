#include<stdio.h>
void generatesubarray(int *nums, int numsize){
    for(int i=0;i<numsize;i++){
        for(int j=i;j<numsize;j++){
            for(int k=i;k<=j;k++){
                printf("%d",nums[k]);
            }
            printf("\n");
        }
    }
}
int main(){
    int nums[100], n;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    generatesubarray(nums, n);
}