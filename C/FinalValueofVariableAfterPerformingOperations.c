int finalValueAfterOperations(char** operations, int operationsSize) {
    int ret = 0;

    for (int i = 0; i<operationsSize; i++) {
        if (operations[i][1]=='+') ret++;
        else ret--;
    }

    return ret;
}
