int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int p1 = 0;
    int p2 = 0;

    while (p1 < nums1Size || p2 < nums2Size) {
        if (nums1[p1] == nums2[p2]) return nums1[p1];

        if (nums1[p1] < nums2[p2]) {
            if (p1 == nums1Size-1) return -1;
            p1++;
            continue;
        }

        if (nums1[p1] > nums2[p2]) {
            if (p2 == nums2Size-1) return -1;
            p2++;
            continue;
        }
    }

    return -1;
}
