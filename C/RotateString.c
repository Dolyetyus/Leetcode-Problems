bool rotateString(char* s, char* goal) {
    int sn = strlen(s);
    int goaln = strlen(goal);
    if (sn!=goaln) return false;

    char doubledGoal[2*goaln+1];
    strcpy(doubledGoal, goal);
    strcat(doubledGoal, goal);

    return strstr(doubledGoal, s) != NULL;
}
