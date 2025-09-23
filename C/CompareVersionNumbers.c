int compareVersion(char* version1, char* version2) {
    int first = 0, second = 0;

    while (version1[first] != '\0' || version2[second] != '\0') {
        int num1 = 0, num2 = 0;

        while (version1[first] != '\0' && version1[first] != '.') {
            num1 = num1 * 10 + (version1[first] - '0');
            first++;
        }
        if (version1[first] == '.') first++; 

        while (version2[second] != '\0' && version2[second] != '.') {
            num2 = num2 * 10 + (version2[second] - '0');
            second++;
        }
        if (version2[second] == '.') second++; 

        if (num1 > num2) return 1;
        if (num1 < num2) return -1;
    }

    return 0;
}

/* 87/89 TLE lol
int compareVersion(char* version1, char* version2) {
    int first = 0;
    int second = 0;

    while (version1[first] !='\0' || version2[second] !='\0') {
        int i = 0;
        int num1 = 0;
        int num2 = 0;

        if (version1[i]!='\0') {
            for (i = first; (version1[i]!='\0' && version1[i]!='.'); i++) {}
            char* version1_num = malloc(i-first+1);
            strncpy(version1_num, version1+first, i-first);
            version1_num[i-first] = '\0';
            if (version1[i]=='\0') first = i;
            else first = i+1;
            num1 = atoi(version1_num);
        }

        if (version2[i]!='\0') {
            for (i = second; (version2[i]!='\0' && version2[i]!='.'); i++) {}
            char* version2_num = malloc(i-second+1);
            strncpy(version2_num, version2+second, i-second);
            version2_num[i-second] = '\0';
            num2 = atoi(version2_num);
            if (version2[i]=='\0') second = i;
            else second = i+1;
        }
        
        if (num1>num2) return 1;
        else if (num1<num2) return -1;
    }

    return 0;
}
*/
