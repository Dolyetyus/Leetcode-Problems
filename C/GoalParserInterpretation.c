char* interpret(char* command){
    int i = 0;
    int insert = 0;
    char* ret = malloc(1);

    while (command[i]!='\0'){
        ret = realloc(ret, insert+1);
        if (command[i]=='G'){
            ret[insert] = 'G';
            i++;
        }
        else if (command[i]=='(' && command[i+1]==')'){
            ret[insert] = 'o';
            i+=2;
        }
        else{
            ret[insert] = 'a';
            insert++;
            ret = realloc(ret, insert+1);
            ret[insert] = 'l';
            i+=4;
        }
        insert++;
    }

    ret = realloc(ret, insert+1);
    ret[insert] = '\0';
    return ret;
}
