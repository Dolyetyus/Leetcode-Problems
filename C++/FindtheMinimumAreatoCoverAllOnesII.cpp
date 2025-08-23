class Solution {
public:
    int minarea(vector<vector<int>>& grid,int st_i,int end_i,int st_j,int en_j){
        int i,j,found=0;
        int start_row=grid.size(),end_row=-1;
        int start_col=grid[0].size(),end_col=-1;

        for(i=st_i;i<=end_i;i++){
            for(j=st_j;j<=en_j;j++){
                if (grid[i][j]){
                    start_row=min(start_row,i);
                    end_row=max(end_row,i);
                    start_col=min(start_col,j);
                    end_col=max(end_col,j);
                    found=1;
                }
            }
        }

        return found ? (end_row-start_row+1)*(end_col-start_col+1):0;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int i,j;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 1e9,one,two,three;

        for(i=0;i<m;i++){
            one=minarea(grid,0,i,0,n-1);

            for(j=0;j<n;j++){
                two=minarea(grid,i+1,m-1,0,j);
                three=minarea(grid,i+1,m-1,j+1,n-1);
                ans=min(ans,one+two+three);
            }
        }

        for(j=0;j<n;j++){
            one=minarea(grid,0,m-1,0,j);

            for(i=0;i<m;i++){
                two=minarea(grid,0,i,j+1,n-1);
                three=minarea(grid,i+1,m-1,j+1,n-1);
                ans=min(ans,one+two+three);
            }
        }
        for(j=n-1;j>=0;j--){
            one=minarea(grid,0,m-1,j+1,n-1);

            for(i=0;i<m;i++){
                two=minarea(grid,0,i,0,j);
                three=minarea(grid,i+1,m-1,0,j);
                ans=min(ans,one+two+three);
            }
        }

        for(i=m-1;i>=0;i--){
            one=minarea(grid,i+1,m-1,0,n-1);

            for(j=0;j<n;j++){
                two=minarea(grid,0,i,0,j);
                three=minarea(grid,0,i,j+1,n-1);
                ans=min(ans,one+two+three);
            }
        }

        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                one = minarea(grid,0,i,0,n-1);
                two = minarea(grid,i+1,j,0,n-1);
                three = minarea(grid,j+1,m-1,0,n-1);
                ans = min(ans,one+two+three);
            }
        }

         for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                one = minarea(grid,0,m-1,0,i);
                two = minarea(grid,0,m-1,i+1,j);
                three = minarea(grid,0,m-1,j+1,n-1);
                ans = min(ans,one+two+three);
            }
        }

        return ans;
    }
};
