class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        
        for (int i = 0; i<sentences.size(); i++){
            int n = count(sentences.at(i).begin(), sentences.at(i).end(), ' ');
            if (n>max) max = n;
        }

        return max+1;
    }
};
