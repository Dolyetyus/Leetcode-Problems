bool isValid(int num) {
    bool changed = false;

    while (num > 0) {
        int mod = num % 10;
        if (mod == 3 || mod == 4 || mod == 7) return false;
        if (mod == 2 || mod == 5 || mod == 6 || mod == 9)  changed = true;
        num /= 10;
    }

    return changed;
}

int rotatedDigits(int n) {
    int ret = 0;

    for (int i = 1; i<=n; i++) {
        if (isValid(i)) ret++;
    }

    return ret;
}
