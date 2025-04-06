class Solution {
public:
    vector<int> dp, succ, ans;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        dp.resize(size(nums), 1), succ.resize(size(nums), INT_MAX);

        for(int i = 0; i < size(nums); i++)  solve(nums, i);
		
        for(int i = distance(begin(dp), max_element(begin(dp), end(dp))); i < size(nums); i = succ[i]) 
            ans.push_back(nums[i]);

        return ans;
    }

    int solve(vector<int>& nums, int start) {
        if(start >= size(nums)) return 0;
        if(dp[start] != 1) return dp[start];

        for(int next = start+1; next < size(nums); next++) {
            if(nums[next] % nums[start]) continue;
            int size = solve(nums, next);

            if(dp[start] < size + 1) {  
                dp[start] = size + 1;   
                succ[start] = next;
            }
        }

        return dp[start];
    }
};
