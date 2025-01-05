char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int size = strlen(s);
    int* shift_arr = calloc(size+1, sizeof(int));

    for (int i = 0; i<shiftsSize; i++){
        int increment = (shifts[i][2] == 1) ? 1 : -1;
        shift_arr[shifts[i][0]] += increment; 
        shift_arr[shifts[i][1]+1] -= increment;
    }

    for (int i = 1; i<size+1; i++){
        shift_arr[i] += shift_arr[i-1];
    }

    for (int i = 0; i<size; i++){
        int shift = ((shift_arr[i] % 26) + 26) % 26;
        s[i] = 'a' + (s[i] - 'a' + shift) % 26;
    }

    free(shift_arr);

    return s;
}
