int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0;
    int j = 0;
    int ret = 0;

    while (i<nums1Size && j<nums2Size){
        if (nums1[i] <= nums2[j]){
            ret = fmax(ret, j-i);
            j++;
        }
        else {
            i++;
            if (i > j) j = i;
        }
    }

    return ret;
}
