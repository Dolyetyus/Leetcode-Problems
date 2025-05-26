int numJewelsInStones(char* jewels, char* stones) {
    int ret = 0;
    for (int i = 0; stones[i]!='\0'; i++){
        for (int ii = 0; jewels[ii]!='\0'; ii++){
            if (stones[i]==jewels[ii]) {
                ret++;
                break;
            }
        }
    }

    return ret;
}
