long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
        long long zeroes1 = 0;
        long long zeroes2 = 0;
        long long sum1 = 0;
        long long sum2 = 0;

        for (int i = 0; i<nums1Size; i++) {
            if (nums1[i]==0) zeroes1++;
            sum1 += nums1[i];
        }

        for (int i = 0; i<nums2Size; i++) {
            if (nums2[i]==0) zeroes2++;
            sum2 += nums2[i];
        }

        long long total1 = sum1+zeroes1;
        long long total2 = sum2+zeroes2;

        if (total1==total2) return total1;
        if (total1>total2 && zeroes2==0) return -1;
        else if (total2>total1 && zeroes1==0) return -1;

        if (total1>total2) return total1;
        else return total2;
}
