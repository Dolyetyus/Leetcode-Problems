class FindSumPairs {
public:
    vector<int> num1;
    vector<int> num2;
    unordered_map<int, int> freq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1 = nums1;
        num2 = nums2;
        for (int n: nums2) {
            freq[n]++;
        }
    }
    
    void add(int index, int val) {
        int oldVal = num2.at(index);
        freq[oldVal]--;
        if (freq[oldVal] == 0) freq.erase(oldVal);

        num2.at(index) += val;
        freq[num2.at(index)]++;
    }
    
    int count(int tot) {
        int result = 0;
        for (int n1: num1) {
            int complement = tot-n1;
            if (freq.count(complement)) {
                result += freq[complement];
            }
        }
        return result;
    }
};
