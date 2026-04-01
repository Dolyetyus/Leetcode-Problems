class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        for (int i = 0; i<n; i++) idx[i] = i;
        
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        vector<int> currHealth = healths;
        stack<int> stk;
        
        for (int i = 0; i < n; i++) {
            int robot = idx[i]; 
            
            if (directions[robot] == 'R') stk.push(i);
            else {
                while (!stk.empty() && directions[idx[stk.top()]] == 'R' && currHealth[robot]>0) {
                    int topSorted = stk.top();
                    int topOrig = idx[topSorted];
                    
                    if (currHealth[topOrig] < currHealth[robot]) {
                        stk.pop();
                        currHealth[robot]--;
                    } 
                    else if (currHealth[topOrig] > currHealth[robot]) {
                        currHealth[topOrig]--;
                        currHealth[robot] = 0;
                        break;
                    } 
                    else {
                        stk.pop();
                        currHealth[robot] = 0;
                        break;
                    }
                }
                if (currHealth[robot] > 0) stk.push(i);
            }
        }
        
        vector<pair<int, int>> survivors;
        while (!stk.empty()) {
            int sortedIdx = stk.top();
            stk.pop();
            int orig = idx[sortedIdx];
            survivors.push_back({orig, currHealth[orig]});
        }
        
        sort(survivors.begin(), survivors.end());
        
        vector<int> ret;
        for (auto& p: survivors) ret.push_back(p.second);
        
        return ret;
    }
};
