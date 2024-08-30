# Note: This solution is O(n+m) instead of O(log((n, m))
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        i = 0
        for num in nums2:
            while i<len(nums1) and num >= nums1[i]:
                i+=1
            nums1.insert(i, num)
            i+=1

        if (len(nums1)%2==1):
            median = nums1[len(nums1)/2]
        else:
            median = ( nums1[len(nums1)/2] + nums1[len(nums1)/2-1] ) / 2.0

        return median
