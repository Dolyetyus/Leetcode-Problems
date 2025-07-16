int max(int a, int b) {
    return (a>b) ? a : b;
}

int maximumLength(int* nums, int numsSize) {
    int count_even = 0, count_odd = 0;
    int alt_even_odd = 0, alt_odd_even = 0;
    int last_parity;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) count_even++;
        else count_odd++;
    }

    last_parity = -1; 
    for (int i = 0; i < numsSize; i++) {
        if (alt_even_odd == 0) {
            if (nums[i] % 2 == 0) {
                last_parity = 0;
                alt_even_odd = 1;
            }
        } 
        else if ((nums[i] % 2) != last_parity) {
            alt_even_odd++;
            last_parity = nums[i] % 2;
        }
    }

    last_parity = -1; 
    for (int i = 0; i < numsSize; i++) {
        if (alt_odd_even == 0) {
            if (nums[i] % 2 == 1) {
                last_parity = 1;
                alt_odd_even = 1;
            }
        } 
        else if ((nums[i] % 2) != last_parity) {
            alt_odd_even++;
            last_parity = nums[i] % 2;
        }
    }

    return max(max(count_even, count_odd), max(alt_even_odd, alt_odd_even));
}
