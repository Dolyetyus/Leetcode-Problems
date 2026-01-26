class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ret;
        set<int> st;
        int absMin = INT_MAX;

        sort(arr.begin(), arr.end());
        st.insert(arr[0]);
        for (int i = 1; i<arr.size(); i++) {
            absMin = fmin(absMin, abs(arr[i]-arr[i-1]));
            st.insert(arr[i]);
        }

        for (int num: arr) {
            if (st.contains(num+absMin)) ret.push_back({num, num+absMin});
        }

        return ret;
    }
};
