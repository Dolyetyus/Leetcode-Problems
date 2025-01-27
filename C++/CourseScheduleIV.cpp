class Solution {
public:
    bool func (int i, int j, vector<vector<int>>&edge, vector<int>&vis){
        if (i==j) return true;
        vis[i] = 1;
        
        for (auto ele: edge[i]){
            if(!vis[ele]){
                if(func(ele,j,edge,vis)) return true;
            }
        }
        
        return false;
    }
    
    vector<bool> checkIfPrerequisite (int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> edge(numCourses);
        
        for(int i = 0; i<prerequisites.size(); i++){
            edge[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<bool> ans;
        
        for(auto ele: queries){
            vector<int> vis(numCourses);
            bool t = func(ele[0], ele[1], edge, vis);
            ans.push_back(t);
        }
        
        return ans;
    }
};
