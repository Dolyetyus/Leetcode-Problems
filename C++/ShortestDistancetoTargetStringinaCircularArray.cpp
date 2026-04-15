class Solution {
public:
    int closestTarget(vector<string>& words, string target, int index) {
        for (int i = 0; i<words.size(); i++) {
            if (words[(index+i)%words.size()] == target || words[(index-i+words.size())%words.size()] == target) return i;
        }

        return -1;
    }
};
