class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        const int n = arr.size();
        unordered_set<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.insert(arr[i]);
            for (int j = i-1; j >= 0 && (arr[i] | arr[j]) != arr[j]; --j) {
                arr[j] |= arr[i];
                ans.insert(arr[j]);
            }
        }
        return ans.size();
    }
};
