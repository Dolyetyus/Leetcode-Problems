class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        int ret = INT_MAX;

        for (int i = 0; i<n; i++) mp[nums[i]].push_back(i);

        for (auto &it: mp) {
            auto &indices = it.second;

            if (indices.size() < 3) continue;

            for (int i = 0; i+2 < indices.size(); i++) {
                int dist = 2 * (indices[i+2] - indices[i]);
                ret = min(ret, dist);
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }
};
