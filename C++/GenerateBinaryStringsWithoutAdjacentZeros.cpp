class Solution {
public:
    void solve(int n, int i, string t, vector<string>& ans){
        if(i >= n){
            ans.push_back(t);
            return;
        }
        if(!t.size() || t.back() == '1') solve(n, i + 1, t + '0', ans);
        solve(n, i + 1, t + '1', ans);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string t = "";
        solve(n, 0, t, ans);
        return ans;
    }
};
