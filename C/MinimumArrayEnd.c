#include <stdint.h>

const uint64_t pdepu64(uint64_t v, uint64_t mask) {
    uint64_t c = 0, m = 1;
    while (mask) {
        const uint64_t b = mask & -mask;
        if (v & m)
            c |= b;
        mask -= b;
        m <<= 1;
    }
    return c;
}

long long minEnd(int n, int x) {
    return x | pdepu64((uint64_t)(n - 1), ~(uint64_t)x);
}
