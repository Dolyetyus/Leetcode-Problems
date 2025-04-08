class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> duplicates;
        vector<int> freqArr(101, 0);
        int index = 0;

        for (int num: nums) freqArr.at(num)++;
        for (int i = 0; i<100; i++) {
            if (freqArr.at(i)>1) {
                duplicates.push_back(i);
                index++;
            }
        }
        if (index==0) return 0;

        int i = 0;
        int numsIndex = 0;
        int ret = 0;
        while (freqArr.at(duplicates.at(index-1)) > 1){
            while (freqArr.at(duplicates.at(i)) > 1){
                ret++;
                for (int n = 0; n<3; n++) {
                    for (int num: duplicates){
                        cout<<num<<" "<<freqArr.at(num)<<endl;
                    }
                    freqArr.at(nums.at(numsIndex))--;
                    numsIndex++;
                    if (numsIndex >= nums.size()) return ret;
                }
            }
            i++;
        }

        return ret;
    }
};
