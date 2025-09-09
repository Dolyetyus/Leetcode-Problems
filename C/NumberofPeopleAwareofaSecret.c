#define MODULO 1000000007

int peopleAwareOfSecret(int n, int delay, int forget) {
    int total = 1;
    int* arr = calloc(forget, sizeof(int));

    n -= delay;

    arr[forget-delay] = 1;

    while (n > 0) {
        int sum = 0;
        total = 0;

        for (int i = 1; i < forget; i++) {
            if (i <= forget - delay) {
                sum += arr[i];
                if (sum >= MODULO) sum -= MODULO;
            }

            total += arr[i];
            if (total >= MODULO) total -= MODULO;

            arr[i - 1] = arr[i] % MODULO;
        }

        arr[forget - 1] = sum;
        total += arr[forget - 1];
        if (total >= MODULO) total -= MODULO;

        n--;
    }

    return total;
}
