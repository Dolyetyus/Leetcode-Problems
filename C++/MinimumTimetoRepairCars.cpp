class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = (long long) *min_element(ranks.begin(), ranks.end()) * (long long) cars * cars;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            long long repaired = 0;
            for (int rank : ranks) {
                repaired += (long long) sqrt(mid / rank);
                if (repaired >= cars) break;
            }

            if (repaired >= cars) {
                ans = mid;
                right = mid - 1; 
            } 
            else left = mid + 1; 
        }

        return ans;
    }
};
