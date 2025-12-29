class Solution {
public:
    map<string, vector<string>> hashings;
    map<string, bool> dp;

    bool dfs (int ind, string newlayer, string oldlayer, int n){
        if (n==1) return true;
        
        if (ind == n-1) {
            if (dp.count(newlayer)) return dp[newlayer];
            return dp[newlayer] = dfs(0, "", newlayer, n-1);
        }

        string tmp = oldlayer.substr(ind, 2);
        if (!hashings.count(tmp)) return false;

        for (string x: hashings[tmp]) {
            if (dfs(ind+1, newlayer+x, oldlayer, n)) return true;
        }

        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();

        for (string str: allowed) hashings[str.substr(0,2)].push_back(str.substr(2));

        return dfs(0, "" , bottom, n);
    }
};
