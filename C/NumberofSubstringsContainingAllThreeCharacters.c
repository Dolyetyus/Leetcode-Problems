int numberOfSubstrings(char* s) {
    int count[3] = {0};
    int left = 0, right = 0, res = 0;
    int n = strlen(s);
    
    while (right < n) {
        count[s[right]-'a']++;
        
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            res += (n - right);
            count[s[left]-'a']--;
            left++;
        }
        
        right++;
    }
    
    return res;
}
