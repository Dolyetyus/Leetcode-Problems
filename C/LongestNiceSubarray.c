int longestNiceSubarray(int* nums, int numsSize) {
    int usedBits=0;
    int start=0;
    int end=0;
    int maxLen=0;

    for (int end=0; end<numsSize; end++){
        while((usedBits & nums[end]) != 0){
            usedBits = usedBits^nums[start];
            start++;
        }

        usedBits|=nums[end];
        if (maxLen<end-start+1) maxLen = end-start+1;
    }
    
    return maxLen;
}
