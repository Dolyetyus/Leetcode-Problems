int minimumRecolors(char* blocks, int k) {
    int left = 0;
    int right = 0;
    int ret = 999999;
    int curr = 0;

    while (blocks[right] != '\0'){
        if (blocks[right] != '\0'){
            if (blocks[right]=='W') curr++;
            right++;
        }

        if (curr<ret && right-left==k) ret = curr;

        if (right-left>=k){
            if (blocks[left]=='W') curr--;
            left++;
        }
    }

    return ret;
}
