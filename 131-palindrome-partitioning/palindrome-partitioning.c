bool isPalin(char* s, int l, int r)
{
    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }

    return true;
}

char*** res;
int* colSizes;
int resZ;

char** cur;
int curZ;

void bt(char* s, int n, int start)
{
    if (start == n)
    {
        res[resZ] =
            (char**)malloc(curZ * sizeof(char*));

        colSizes[resZ] = curZ;

        for (int i = 0; i < curZ; i++)
        {
            res[resZ][i] = strdup(cur[i]);
        }

        resZ++;
        return;
    }

    for (int end = start; end < n; end++)
    {
        if (!isPalin(s, start, end))
            continue;

        cur[curZ++] =
            strndup(s + start,
                    end - start + 1);

        bt(s, n, end + 1);

        free(cur[--curZ]);
    }
}

char*** partition(char* s,
                  int* returnSize,
                  int** returnColumnSizes)
{
    int n = strlen(s);

    res =
        (char***)malloc(50000 * sizeof(char**));

    colSizes =
        (int*)malloc(50000 * sizeof(int));

    cur =
        (char**)malloc(n * sizeof(char*));

    resZ = 0;
    curZ = 0;

    bt(s, n, 0);

    *returnSize = resZ;
    *returnColumnSizes = colSizes;

    return res;
}