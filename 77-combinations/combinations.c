/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
long long nCr(int n, int r) { long long res = 1;
for (int i = 1; i <= r; i++) { res = res * (n - i + 1) / i;
}
return res;
}

void backtrack(int n, int k, int start,
int* path, int depth,
int** result, int* returnSize, int* returnColumnSizes) {
if (depth == k) {
result[*returnSize] = (int*)malloc(k * sizeof(int)); memcpy(result[*returnSize], path, k * sizeof(int)); returnColumnSizes[*returnSize] = k; (*returnSize)++;
return;
}

for (int i = start; i <= n; i++) { path[depth] = i;
backtrack(n, k, i + 1, path, depth + 1,
result, returnSize, returnColumnSizes);
}
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) { int total = (int)nCr(n, k);

int** result = (int**)malloc(total * sizeof(int*));
*returnColumnSizes = (int*)malloc(total * sizeof(int));
*returnSize = 0; int path[20];
backtrack(n, k, 1, path, 0, result, returnSize, *returnColumnSizes);

return result;
}
