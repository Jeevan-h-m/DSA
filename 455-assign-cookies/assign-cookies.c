int partition(int *arr, int low, int high)
{
    int pivot = arr[low + (high - low) / 2];
    int left = low - 1;
    int right = high + 1;

    while (1)
    {
        do
        {
            left++;
        } while (arr[left] < pivot);

        do
        {
            right--;
        } while (arr[right] > pivot);

        if (left >= right)
            return right;

        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partitionindex = partition(arr, low, high);

        quicksort(arr, low, partitionindex);
        quicksort(arr, partitionindex + 1, high);
    }
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    quicksort(g, 0, gSize - 1);
    quicksort(s, 0, sSize - 1);

    int ans = 0;
    int ptr1 = 0, ptr2 = 0;

    while (ptr1 < gSize && ptr2 < sSize)
    {
        if (g[ptr1] <= s[ptr2])
        {
            ans++;
            ptr1++;
            ptr2++;
        }
        else
        {
            ptr2++;
        }
    }

    return ans;
}