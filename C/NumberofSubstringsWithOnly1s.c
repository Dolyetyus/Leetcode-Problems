int numSub(char* s) {
    int left = 0;
    int right = 0;
    long long ret = 0;

    while (s[left] != '\0') {
        while (s[left] != '\0' && s[left] == '0') left++;
        right = left;
        while (s[right] != '\0' && s[right] == '1') right++;

        long long n = right-left;
        ret += (n*(n+1)) / 2;

        left = right;
    }

    return ret%1000000007;
}
