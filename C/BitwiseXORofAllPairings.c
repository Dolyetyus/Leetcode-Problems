int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int xorNums1 = 0, xorNums2 = 0;

    for (int i = 0; i < nums1Size; i++) {
        xorNums1 ^= nums1[i];
    }

    for (int i = 0; i < nums2Size; i++) {
        xorNums2 ^= nums2[i];
    }

    int result = 0;

    if (nums2Size % 2 == 1) {
        result ^= xorNums1;
    }

    if (nums1Size % 2 == 1) {
        result ^= xorNums2;
    }

    return result;
}
