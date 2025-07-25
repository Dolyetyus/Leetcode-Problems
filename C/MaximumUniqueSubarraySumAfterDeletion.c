int maxSum(int* nums, int numsSize) {
    int* hmap = calloc(201, sizeof(int));
    int ret = 0;

    for (int i = 0; i < numsSize; i++){
        hmap[nums[i]+100]++;
    }

    int i = 200;
    for (; i>100; i--){
        if (hmap[i]!=0) ret+=i-100;
    }

    if (ret==0 && hmap[100]==0){
        while (hmap[i]==0) i--;
        return i-100;
    }
    
    return ret;
}
