class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq_arr(A.size()+1);
        vector<int> ret;

        int total = 0;
        for (int i = 0; i<A.size(); i++){
            freq_arr[A[i]]++;
            freq_arr[B[i]]++;

            if (freq_arr[A[i]]>1){
                total++;
                freq_arr[A[i]]--;
            }
            if (freq_arr[B[i]]>1){
                total++;
                freq_arr[B[i]]--;
            }

            ret.push_back(total);
        }

        return ret;
    }
};
