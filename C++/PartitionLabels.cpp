class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> hmap;

        for (int i = 0; i<s.size(); i++) hmap[s[i]] = i;

        vector<int> partitions;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, hmap[s[i]]);
            if (i == end) {
                partitions.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return partitions;
    }
};
