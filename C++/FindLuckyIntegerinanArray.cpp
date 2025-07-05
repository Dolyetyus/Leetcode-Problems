class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(500);

        for (int num: arr) freq.at(num-1)++;

        for (int i = 499; i>=0; i--){
            if (i+1==freq.at(i)) return i+1;
        }
        
        return -1;
    }
};
