class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> hmap;

        for (int i = 0; i<arr.size(); i++) {
            hmap[arr.at(i)] = i;
        }

        for (int i = 0; i<arr.size(); i++) {
            int num = arr.at(i)*2;
            if (hmap.count(num) && hmap[num] != i) return true;
        }

        return false;
    }
};
