int maxArea(int* height, int heightSize) {
    int ret = 0;
    int left = 0;
    int right = heightSize-1;

    while (left<right) {
        if (height[left]>height[right]) {
            int area = height[right]*(abs(left-right));
            if (area>ret) ret = area;
            right--;
        }
        else {
            int area = height[left]*(abs(left-right));
            if (area>ret) ret = area;
            left++;
        }
    }

    return ret;
}
