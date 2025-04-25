class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        const int n=nums.size();
        int mp[100001]={1};
        long long ans=0;
        int prefix=0;
        for(int i=0; i<n; i++){
            prefix+=((nums[i]%modulo)==k);
            if (prefix<k){
                mp[prefix]++;
                continue;
            }
            ans+=mp[(prefix-k)%modulo];
            mp[prefix%modulo]++;
        }
        return ans;
    }
};
