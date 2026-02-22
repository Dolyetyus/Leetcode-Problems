int binaryGap(int n) {
    int ret = 0;
    int lastPos = -1;
    int pos = 0;

    while (n > 0) {
        if (n & 1) {
            if (lastPos != -1) {
                int dist = pos-lastPos;
                if (dist > ret) ret = dist;
            }
            lastPos = pos;
        }
        n >>= 1;
        pos++;
    }

    return ret;
}
