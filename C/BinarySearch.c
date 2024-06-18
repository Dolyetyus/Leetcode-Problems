int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize-1, mid = 0;
    while (left<=right){
        mid = (left+right+1)/2;
        if (nums[mid]==target){
            return mid;
        }
        else if (nums[mid]>target){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return left;
}
