class Solution {
public:
	vector<long long> distance(vector<int>& nums) {
		unordered_map<long long, vector<long long>> map;
        vector<long long> ret(nums.size(), 0);

		for (long long i = 0; i < nums.size(); i++)
			map[nums[i]].push_back(i);

        for (auto& v: map) {
            long long t = 0;
            for (long long i = 1; i<v.second.size(); i++) {
                long long diff = v.second[i] - v.second[i-1];
                ret[v.second[i]] += i*diff+t;
                t += i*diff;
            }
        }

        for (auto& v: map) {
            long long t = 0;
            long long c = 1;
            for (long long i = (long long)v.second.size()-2; i>=0; i--) {
                long long diff = v.second[i+1] - v.second[i];
                ret[v.second[i]] += c*diff+t;
                t += c*diff;
                c++;
            }
        }

        return ret;
    }
};
