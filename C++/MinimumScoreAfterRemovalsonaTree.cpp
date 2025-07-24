class Solution {
public:
    int vis[1001];
    int ans;
    int n,x;
    vector<vector<int>> adj;

    int dfs2 (int node,int par,int x1,vector<int> &nums){
        int y=nums[node];

        for (auto it: adj[node]) {
            if(vis[it] || it == par) continue;

            int x2=dfs2(it,node,x1,nums);
            int x3=x^x1^x2;
            int t=max({x1,x2,x3})-min({x1,x2,x3});
            ans=min(ans,t);
            y=y^x2;
        }

        return y;
    }

    int dfs1(int node,int par,vector<int>& nums){
        int y=nums[node];

        for (auto it:adj[node]) {
            if (it == par) continue;

            int x1=dfs1(it,node,nums);
            vis[it]=1;
            dfs2(node,-1,x1,nums);
            y=y^x1;
            vis[it]=0;
        }

        return y;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n=nums.size();
        adj.resize(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        x=0;

        for (auto it:nums) x = x^it;

        ans = INT_MAX;
        memset(vis,0,sizeof(vis));
        dfs1(0,-1,nums);

        return ans;
        
    }
};
