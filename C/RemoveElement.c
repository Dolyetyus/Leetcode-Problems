int removeElement(int* nums, int numsSize, int val) {
    int id = 0;
    for (int i = 0; i<numsSize; i++){
        if (nums[i] != val) {
            nums[id] = nums[i];
            id++;
        }
    }
    return id;
}
