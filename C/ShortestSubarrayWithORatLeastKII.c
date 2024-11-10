/* Fails for too large inputs - Time limit exceeded
int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int ret = numsSize + 1;
    for (int i = 0; i < numsSize; i++) {
        int current_sum = nums[i];
        if (current_sum >= k) return 1;
        for (int ii = i + 1; ii < numsSize; ii++) {
            current_sum |= nums[ii];
            if (current_sum >= k) {
                if (ii - i + 1 < ret) ret = ii - i + 1;
                break;
            }
        }
    }

    if (ret == numsSize + 1) return -1;
    return ret;
}*/


void performOrOperation(int* bitCount, int* orVal, int n) {
    *orVal = (*orVal | n);
    for (int t = 0; t < 32; ++t) {
        bitCount[t] += (n & (1U << t)) ? 1 : 0;
    }
}

void nullifyOrOperation(int* bitCount, int* orVal, int n) {
    for (int t = 0; t < 32; ++t) {
        if (n & (1U << t)) bitCount[t] -= 1;
        if (bitCount[t] == 0) *orVal = *orVal & (~(1U << t));
    }
}

int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int orVal = 0, ans = INT_MAX;
    int bitCount[32] = {0};

    for (int i = 0, j = 0; i < numsSize; ++i) {
        performOrOperation(bitCount, &orVal, nums[i]);
        if (orVal < k) continue;

        while (j <= i && orVal >= k) {
            nullifyOrOperation(bitCount, &orVal, nums[j]);
            if (i - j + 1 < ans) ans = i - j + 1;
            j++;
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}
