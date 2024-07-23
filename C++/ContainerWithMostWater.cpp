class Solution {
public:
    int maxArea(vector<int>& height) {
        int maks = 0;
        int right = height.size()-1;
        int i = 0;

        while (i<right){
            int h = min(height.at(i), height.at(right));
            int width = right - i;
            int area = h*width;
            maks = max(maks, area);

            if (height.at(i) < height.at(right)) i++;
            else right--;
        }

        return maks;
    }
};
