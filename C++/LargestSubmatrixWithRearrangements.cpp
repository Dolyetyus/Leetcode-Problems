class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ret = 0;

        for (int i = 1; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (matrix[i][j] == 1) matrix[i][j] += matrix[i-1][j];
            }
        }

        for (int i = 0; i<m; i++) {
            vector<int> arr = matrix[i];
            sort(arr.begin(), arr.end());

            for (int j = 0; j<n; j++) {
                int height = arr[j];
                int width = n-j;
                ret = max(ret, height*width);
            }
        }

        return ret;
    }
};
