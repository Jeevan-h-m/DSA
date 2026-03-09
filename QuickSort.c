#include<stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void quicksort(int arr[], int low, int high){
    if(low<high){
        int p=partition(arr, low, high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}
int main(){
    int n,arr[100],i;
    printf("enter the number of elements:");
    scanf("%d",&n);
    printf("\nenter the elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nBefore sorting\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("\nAfter sorting\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}