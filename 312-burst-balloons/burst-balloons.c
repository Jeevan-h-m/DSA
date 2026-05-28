int maxCoins(int* nums, int numsSize)
{
    int n = numsSize + 2;

    int arr[n];

    arr[0] = 1;
    arr[n - 1] = 1;

    for (int i = 0; i < numsSize; ++i)
    {
        arr[i + 1] = nums[i];
    }

    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int len = 2; len < n; ++len)
    {
        for (int left = 0; left + len < n; ++left)
        {
            int right = left + len;
            int best = 0;

            int baseMul = arr[left] * arr[right];

            for (int k = left + 1; k < right; ++k)
            {
                int val = dp[left][k] +
                          dp[k][right] +
                          baseMul * arr[k];

                if (val > best)
                    best = val;
            }

            dp[left][right] = best;
        }
    }

    return dp[0][n - 1];
}