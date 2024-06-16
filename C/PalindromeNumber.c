bool isPalindrome(int x) {
    /*int length = snprintf(NULL, 0, "%d", x );
    char* num = malloc(length + 1);
    snprintf(num, length + 1, "%d", x);

    for (int i = 0; i<length/2; i++){
        if (num[i]!=num[length-1-i]) return false;
    }

    return true;*/

    if (x<0) return false;

    if (x >= 0 && x < 10) return true;

    int original = x;
    long reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}
