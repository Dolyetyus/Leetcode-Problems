class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        if (n<10) return false;

        int base = 2;

        while (base <= n-2){
            long num = n;
            long numNewBase = 0;

            while (num != 0){
                numNewBase *= 10;
                numNewBase += num % base;
                num /= base;
            }

            string strNum = to_string(numNewBase);
            for (int i = 0; i<strNum.size()/2; i++){
                if (strNum[i] != strNum[strNum.size()-i-1]) return false;
            }
            
            base++;
        }

        return true;
    }
};
