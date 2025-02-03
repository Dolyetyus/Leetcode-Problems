int longestMonotonicSubarray(int* nums, int numsSize) {
    int inc = 1;
    int dec = 1;
    int maxInc = 1;
    int maxDec = 1;

    for (int i = 0; i<numsSize-1; i++){
        if (nums[i]<=nums[i+1]){
            if (inc>maxInc) maxInc = inc;
            inc = 0;
        }
        if (nums[i]>=nums[i+1]){
            if (dec>maxDec) maxDec = dec;
            dec = 0;
        }
        inc++;
        dec++;
    }

    if (inc>maxInc) maxInc = inc;
    if (dec>maxDec) maxDec = dec;

    if (maxInc>maxDec) return maxInc;
    return maxDec;
}
