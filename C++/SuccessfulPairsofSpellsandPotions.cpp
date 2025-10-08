class Solution {
public:
    int findIndex(long long target, const vector<int>& potions) {
        int left = 0;
        int right = potions.size();
        int result = -1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (potions.at(mid) >= target) {
                result = mid;
                right = mid;
            } 
            else left = mid + 1;
        }

        return result;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ret(spells.size());
        sort(potions.begin(), potions.end());

        for (int i = 0; i<spells.size(); i++){
            long long target = ((long long)success+spells.at(i)-1) / (long long)spells.at(i);
            int res = findIndex(target, potions);
            if (res>-1) ret.at(i) = potions.size()-res;
            else ret.at(i) = 0;
        }

        return ret;
    }
};
