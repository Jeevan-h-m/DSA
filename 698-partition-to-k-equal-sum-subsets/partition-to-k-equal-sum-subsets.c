int compare(const void* a, const void* b)
{
    return (*(int*)b - *(int*)a);
}

bool backtrack(int* nums, int numsSize, bool* used,
               int k, int start,
               int target, int currentSum)
{
    if (k == 1)
        return true;

    if (currentSum == target)
    {
        return backtrack(nums, numsSize, used,
                         k - 1, 0,
                         target, 0);
    }

    for (int i = start; i < numsSize; i++)
    {
        if (used[i] ||
            currentSum + nums[i] > target)
            continue;

        used[i] = true;

        if (backtrack(nums, numsSize, used,
                      k, i + 1,
                      target,
                      currentSum + nums[i]))
        {
            return true;
        }

        used[i] = false;
    }

    return false;
}

bool canPartitionKSubsets(int* nums,
                          int numsSize,
                          int k)
{
    int sum = 0;
    int maxNum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];

        if (nums[i] > maxNum)
            maxNum = nums[i];
    }

    if (sum % k != 0 ||
        maxNum > sum / k)
        return false;

    int target = sum / k;

    bool* used =
        (bool*)calloc(numsSize, sizeof(bool));

    qsort(nums, numsSize,
          sizeof(int), compare);

    bool result =
        backtrack(nums, numsSize,
                  used, k, 0,
                  target, 0);

    free(used);

    return result;
}