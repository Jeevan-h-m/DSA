/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* nums, int numsSize, int* used,
int* path, int depth,
int** result, int* returnSize) {

if (depth == numsSize) {
result[*returnSize] = (int*)malloc(numsSize * sizeof(int)); memcpy(result[*returnSize], path, numsSize * sizeof(int)); (*returnSize)++;
return;
}
 
for (int i = 0; i < numsSize; i++) { if (used[i]) continue;
used[i] = 1; path[depth] = nums[i];
backtrack(nums, numsSize, used, path, depth + 1, result, returnSize);

used[i] = 0; // backtrack
}
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
int total = 1;
for (int i = 2; i <= numsSize; i++) total *= i;
int** result = (int**)malloc(total * sizeof(int*));
*returnColumnSizes = (int*)malloc(total * sizeof(int));
*returnSize = 0;
int used[10] = {0}; int path[10];
backtrack(nums, numsSize, used, path, 0, result, returnSize);

for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = numsSize;
return result;
}
