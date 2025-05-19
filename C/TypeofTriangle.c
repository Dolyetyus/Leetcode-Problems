char* triangleType(int* nums, int numsSize) {
    if (nums[0]+nums[1]<=nums[2] || nums[0]+nums[2]<=nums[1] || nums[1]+nums[2]<=nums[0]){
        return "none";
    }
    if (nums[0]==nums[1] && nums[1]==nums[2]) return "equilateral";
    else if ((nums[0]==nums[1] && nums[1]!=nums[2]) || (nums[0]==nums[2] && nums[1]!=nums[2]) || (nums[1]==nums[2] && nums[0]!=nums[2])) return "isosceles";
    return "scalene";
}
