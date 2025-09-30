int longestMountain(int* arr, int arrSize) {
    if (arrSize < 3) return 0;
    int ret = 0, i = 1;

    while (i < arrSize - 1) {
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            int left = i, right = i;

            while (left > 0 && arr[left-1] < arr[left]) left--;
            while (right < arrSize-1 && arr[right] > arr[right+1]) right++;

            int length = right - left + 1;
            if (length > ret) ret = length;

            i = right; 
        } 
        else i++;
    }
    return ret;
}
