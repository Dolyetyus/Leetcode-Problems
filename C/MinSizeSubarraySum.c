int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, sum = 0, shortest = numsSize + 1;

    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];
        while (sum >= target) {
            shortest = (right-left+1 < shortest) ? (right-left+1) : shortest;
            sum -= nums[left];
            left++;
        }
    }

    return (shortest == numsSize + 1) ? 0 : shortest;
}

/* Time Limit Exceeded lmao
int minSubArrayLen(int target, int* nums, int numsSize) {
    int shortest = 999999;
    for (int i = 0; i<numsSize; i++){
        int sum = 0;
        int pointer = i;

        while (sum<target){
            if (pointer==numsSize) {
                if (shortest==999999) return 0;
                return shortest;
            }
            sum += nums[pointer];
            pointer++;
        }

        if (pointer-i<shortest) shortest = pointer-i;
    }

    return shortest;
}*/
