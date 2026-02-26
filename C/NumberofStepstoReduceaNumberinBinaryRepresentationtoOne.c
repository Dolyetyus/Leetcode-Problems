int numSteps(char* s) {
    int ret = 0;
    int carry = false;
    int n = strlen(s);

    for (int i = n-1; i>=1; i--) {
        int bit = (s[i]-'0') + carry;

        if (bit == 1) {
            ret += 2;
            carry = 1;
        } 
        else ret += 1;
    }

    return ret + carry;
}
