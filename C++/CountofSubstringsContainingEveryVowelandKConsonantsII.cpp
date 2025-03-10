class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_set<char> vowels = {'a','e','i','o','u'};
        unordered_map<char, int> vowelCount;
        int cons = 0, left = 0, count = 0;
        long long substr = 0;
        auto minus = [&](char c){
            if (vowels.count(c)){
                if (--vowelCount[c] == 0){
                    vowelCount.erase(c);
                }
            } else {
                cons--;
            }
        };
        for (char c : word){
            if (vowels.count(c)){
                vowelCount[c]++;
            } else {
                cons++;
                count = 0;
            }
            while (cons > k){
                minus(word[left]);
                left++;
            }
            while (cons == k && vowelCount.size() == 5){
                count++;
                minus(word[left]);
                left++;
            }
            substr += count;
        }
        return substr;
    }
};
