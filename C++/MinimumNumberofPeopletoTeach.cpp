class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langSet(m+1);
        
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                langSet[i+1].insert(lang);
            }
        }
        
        unordered_set<int> needTeaching;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            
            for (int lang : langSet[u]) {
                if (langSet[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            
            if (!canCommunicate) {
                needTeaching.insert(u);
                needTeaching.insert(v);
            }
        }
        
        if (needTeaching.empty()) return 0;
        
        vector<int> count(n+1, 0);
        for (int user : needTeaching) {
            for (int lang : langSet[user]) {
                count[lang]++;
            }
        }
        
        int maxKnow = 0;
        for (int lang = 1; lang <= n; lang++) {
            maxKnow = max(maxKnow, count[lang]);
        }
        
        return needTeaching.size() - maxKnow;
    }
};
