class Solution {
public:
    bool canReach(string s, int mini, int maxi) {
        int n = s.size();
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;
        int far = 0;
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == n-1) return true;
            int start = max(node+mini, far+1);
            int end = min(node+maxi, n-1);

            for (int i = start; i<=end; i++) {
                if (s[i] == '0' && !vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }

            far = end;
        }

        return false;
    }
};
