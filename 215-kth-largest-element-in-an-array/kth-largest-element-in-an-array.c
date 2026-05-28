int findKthLargest(int* nums, int numsSize, int k) {

    int* heap = (int*)malloc(sizeof(int) * k);

    // Copy first k elements
    for (int i = 0; i < k; i++) {
        heap[i] = nums[i];
    }

    // Build min heap
    for (int i = k / 2 - 1; i >= 0; i--) {

        int parent = i;

        while (1) {
            int smallest = parent;
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;

            if (left < k && heap[left] < heap[smallest])
                smallest = left;

            if (right < k && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == parent)
                break;

            int temp = heap[parent];
            heap[parent] = heap[smallest];
            heap[smallest] = temp;

            parent = smallest;
        }
    }

    // Process remaining elements
    for (int i = k; i < numsSize; i++) {

        if (nums[i] > heap[0]) {

            heap[0] = nums[i];

            int parent = 0;

            while (1) {
                int smallest = parent;
                int left = 2 * parent + 1;
                int right = 2 * parent + 2;

                if (left < k && heap[left] < heap[smallest])
                    smallest = left;

                if (right < k && heap[right] < heap[smallest])
                    smallest = right;

                if (smallest == parent)
                    break;

                int temp = heap[parent];
                heap[parent] = heap[smallest];
                heap[smallest] = temp;

                parent = smallest;
            }
        }
    }

    int ans = heap[0];
    free(heap);

    return ans;
}