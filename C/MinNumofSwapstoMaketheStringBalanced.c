int minSwaps(char* s) {
    int count = 0;
    
    for (int i = 0; s[i]!='\0'; i++){
        if (s[i]=='[') count++;
        else if (count>0) count--;
    }

    return (count+1)/2;
}
