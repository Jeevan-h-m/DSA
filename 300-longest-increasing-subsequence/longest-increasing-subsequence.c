int lengthOfLIS(int* nums, int numsSize) {
int* tails = (int*)malloc(numsSize * sizeof(int)); int size = 0;
for (int i = 0; i < numsSize; i++) { int left = 0, right = size; while (left != right) {
int mid = left + (right - left) / 2;
if (tails[mid] < nums[i]) left = mid + 1; else right = mid;
}
tails[left] = nums[i]; if (left == size) size++;
}
free(tails); return size;
 
}
