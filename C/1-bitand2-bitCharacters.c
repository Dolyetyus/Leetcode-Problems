bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    for (; i<bitsSize-1;) {
        if (bits[i] == 1) i++;
        i++;
    }

    return i!=bitsSize;
}
