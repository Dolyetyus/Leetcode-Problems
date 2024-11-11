#define MAX 1001

bool prime[MAX];

void sieve() {
    for (int i = 0; i < MAX; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

int search(int x, int y) {
    for (int i = x + 1; i < y; i++) {
        if (prime[i]) {
            return i;
        }
    }
    return -1;
}

bool primeSubOperation(int* nums, int numsSize) {
    sieve();
    
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i] <= nums[i - 1]) {
            int x = search(nums[i - 1] - nums[i], nums[i - 1]);
            if (x == -1) {
                return false;
            }
            nums[i - 1] -= x;
        }
    }
    return true;
}

/* Fails one edge case lol
int findPrimes(int* primes, int n) {
    if (n < 2) {
        return 0;
    }

    bool* isPrime = (bool*)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }
    
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes[count] = i;
            count++;
        }
    }
    
    free(isPrime);
    return count;
}

int findSub(int lowLimit, int number, int* primes, int count) {
    int left = 0;
    int right = count-1;
    int mid;

    while (left<=right){
        mid = left + (right - left) / 2;
        if (primes[mid] < number && number - primes[mid] > lowLimit)
            left = mid + 1; 
        else
            right = mid - 1;
    }

    if (right >= 0 && number - primes[right] > lowLimit) {
        printf("%d ", primes[right]);
        return primes[right];
    }

    return -1;
}

bool primeSubOperation(int* nums, int numsSize) {
    int n = 1000;
    int* primes = (int*)malloc(n * sizeof(int));
    int count = findPrimes(primes, n);

    nums[0] = nums[0] - findSub(0, nums[0], primes, count);
    for (int i = 1; i<numsSize; i++){
        int subtract = findSub(nums[i-1], nums[i], primes, count);
        if (subtract == -1) {
            free(primes);
            return false;    
        }
        nums[i] = nums[i]-subtract;
    }

    free(primes);
    return true;
}
*/
