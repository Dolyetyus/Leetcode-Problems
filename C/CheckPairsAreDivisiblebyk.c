/* Not dealing with negative integers
bool canArrange(int* arr, int arrSize, int k) {
    for (int i = 0; i<arrSize; i++){
        if (arr[i] >= 0){
            bool found = false;
            for (int ii = 0; ii<arrSize; ii++){
                if (i==ii) continue;
                if ((arr[i]+arr[ii])%k==0) found = true;
            }
            if (!found) return false;
        }
    }

    return true;
}*/

bool canArrange(int* arr, int arrSize, int k) {
    int remainderCount[k];
    for (int i = 0; i < k; i++) {
        remainderCount[i] = 0;
    }

    for (int i = 0; i < arrSize; i++) {
        int remainder = ((arr[i] % k) + k) % k;
        remainderCount[remainder]++;
    }

    if (remainderCount[0] % 2 != 0) return false;

    for (int i = 1; i <= k / 2; i++) {
        if (remainderCount[i] != remainderCount[k - i]) return false;
    }

    return true;
}
