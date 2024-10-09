int minAddToMakeValid(char* s) {
    int n = strlen(s);
    int open = 0;
    int closed = 0;

    for (int i = 0; i<n; i++){
        if (s[i] == '(')
            open++;
        else if (s[i] == ')' && open>0) 
            open--;
        else
            closed++;
    }

    return open+closed;
}
