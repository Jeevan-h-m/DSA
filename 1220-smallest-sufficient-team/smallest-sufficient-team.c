/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestSufficientTeam(char** req,
                            int reqSz,
                            char*** people,
                            int pepSz,
                            int* pepColSz,
                            int* retSz)
{
    int n = reqSz;

    int full = (1 << n) - 1;

    long long dp[1 << n];

    int par[1 << n];
    int prev[1 << n];

    memset(dp, 0x3f, sizeof(dp));

    dp[0] = 0;
    par[0] = -1;

    int skills[pepSz];

    for (int i = 0; i < pepSz; i++)
    {
        skills[i] = 0;

        for (int j = 0; j < pepColSz[i]; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (!strcmp(people[i][j], req[k]))
                {
                    skills[i] |= (1 << k);
                }
            }
        }
    }

    memset(prev, -1, sizeof(prev));

    for (int mask = 0; mask <= full; mask++)
    {
        if (dp[mask] ==
            0x3f3f3f3f3f3f3f3fLL)
            continue;

        for (int i = 0; i < pepSz; i++)
        {
            int nm = mask | skills[i];

            if (dp[mask] + 1 < dp[nm])
            {
                dp[nm] = dp[mask] + 1;

                prev[nm] = mask;

                par[nm] = i;
            }
        }
    }

    int* ans =
        (int*)malloc(dp[full] * sizeof(int));

    *retSz = dp[full];

    int cur = full;

    int idx = dp[full] - 1;

    while (cur)
    {
        ans[idx--] = par[cur];

        cur = prev[cur];
    }

    return ans;
}