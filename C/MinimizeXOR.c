int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int minimizeXor(int num1, int num2) {
    int setBitsNum2 = countSetBits(num2);
    int result = 0;

    for (unsigned int i = 31; i < 32 && setBitsNum2 > 0; --i) {
        if (num1 & (1U << i)) {
            result |= (1U << i);
            setBitsNum2--;
        }
    }

    for (unsigned int i = 0; i < 32 && setBitsNum2 > 0; ++i) {
        if (!(result & (1U << i))) {
            result |= (1U << i);
            setBitsNum2--;
        }
    }

    return result;
}
