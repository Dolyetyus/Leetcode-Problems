bool isStrictlyIncreasing(int* nums, int start, int k, int n) {
    if (start + k > n) return false;
    for (int i = start; i < start + k - 1; i++) {
        if (nums[i] >= nums[i + 1]) return false;
    }
    return true;
}

bool hasIncreasingSubarrays(int* nums, int n, int k) {
    for (int a = 0; a+2*k <= n; a++) {
        int b = a + k;
        if (isStrictlyIncreasing(nums, a, k, n) && 
            isStrictlyIncreasing(nums, b, k, n)) {
            return true;
        }
    }
    return false;
}

/* Gave up with this approach lol I should have read the description better
bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    bool ret = false;
    int* arr = malloc((numsSize-1)*sizeof(int));
    int id = 0;

    for (int i = 0; i<numsSize-1; i++) {
        if (nums[i]<nums[i+1]) arr[id] = 1;
        else if (nums[i]==nums[i+1]) arr[id] = 0;
        else arr[id] = -1;
        id++;
    }

    int left = 0; int right = 0; int non = 0;
    while (right<numsSize-1 && left<=right) { 
        while (right<numsSize-1 && !(arr[right]==0 || arr[right]==-1)) {
            right++;
        }
        if (right<numsSize-1) non++;
        
        int size = right-left+1;
        if (non == 0 && size>=(2*k)-1) {
            return true;
        } 

        right++;
        if (nums[left]!=1) non--;
        left++;
    }

    k--;
    int n = numsSize-1;
    int i = 0;
    while (i < n) {
        int leftCount = 0;
        while (i < n && arr[i] == 1) {
            leftCount++;
            i++;
        }

        if (leftCount < k) {
            i++;
            continue;
        }

        int midCount = 0;
        if (i < n && (arr[i] == 0 || arr[i] == -1)) {
            midCount = 1;
            i++;
        }

        int rightCount = 0;
        while (i < n && arr[i] == 1) {
            rightCount++;
            i++;
        }

        if (rightCount >= k) return true;

        i = i - rightCount;
    }

    return ret;
}
*/
