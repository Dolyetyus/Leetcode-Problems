class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ret = 0;
        int left = 0;
        deque<int> maxDeque, minDeque;

        for (int right = 0; right < nums.size(); right++) {
            while (!maxDeque.empty() && nums[maxDeque.back()] < nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            while (!minDeque.empty() && nums[minDeque.back()] > nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                left++;
                if (maxDeque.front() < left) maxDeque.pop_front();
                if (minDeque.front() < left) minDeque.pop_front();
            }

            ret += (right-left+1);
        }

        return ret;
    }
};
