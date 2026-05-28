char* map[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void backtrack(char* digits, int index, char* path,
               char** result, int* returnSize)
{
    if (digits[index] == '\0')
    {
        result[*returnSize] =
            (char*)malloc(strlen(path) + 1);

        strcpy(result[*returnSize], path);

        (*returnSize)++;
        return;
    }

    char* letters = map[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++)
    {
        path[index] = letters[i];
        path[index + 1] = '\0';

        backtrack(digits, index + 1,
                  path, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    *returnSize = 0;

    if (digits[0] == '\0')
        return NULL;

    char** result =
        (char**)malloc(10000 * sizeof(char*));

    char path[10];

    backtrack(digits, 0, path, result, returnSize);

    return result;
}