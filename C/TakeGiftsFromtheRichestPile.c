long long pickGifts(int* gifts, int giftsSize, int k) {
    long long ret = 0;

    for (int i = 0; i<k; i++){
        int max_index;
        int max = -1;
        for (int n = 0; n<giftsSize; n++){
            if (gifts[n]>max){
                max_index = n;
                max = gifts[n];
            }
        }
        int temp = sqrt(max);
        gifts[max_index] = temp;
    }

    for (int n = 0; n<giftsSize; n++){
        ret+=gifts[n];
    }

    return ret;
}
