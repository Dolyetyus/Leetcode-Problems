class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visit(n,false);
        queue<int> q;
        
        q.push(start);
        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0) return true;

            visit[i] = true;

            if (arr[i]+i < n && !visit[arr[i]+i]) q.push(arr[i]+i);
            if (i-arr[i] >= 0 && !visit[i-arr[i]]) q.push(i-arr[i]);
        }

        return false;
    }
};
