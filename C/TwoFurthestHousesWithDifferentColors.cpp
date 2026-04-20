int maxDistance(int* colors, int colorsSize) { 
    int max = 0;
    int ptr = colorsSize-1;

    while (ptr >= 0 && colors[0] == colors[ptr]) ptr--;
    max = ptr;

    ptr = 0;
    while (ptr < colorsSize && colors[colorsSize - 1] == colors[ptr]) ptr++;
    max = fmax(max, (colorsSize-1-ptr));

    return max;
}
