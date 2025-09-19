typedef struct {
    int** arr;
} Spreadsheet;


Spreadsheet* spreadsheetCreate(int rows) {
    Spreadsheet* sheet = malloc(sizeof(Spreadsheet));
    sheet->arr = calloc(26, sizeof *sheet->arr); 
    for (int i = 0; i < 26; i++) sheet->arr[i] = calloc(rows, sizeof *sheet->arr[i]);
    return sheet;
}

void spreadsheetSetCell(Spreadsheet* obj, char* cell, int value) {
    int letter = cell[0]-'A'; cell++;
    int num = atoi(cell);
    obj->arr[letter][num-1] = value;
}

void spreadsheetResetCell(Spreadsheet* obj, char* cell) {
    int letter = cell[0]-'A'; cell++;
    int num = atoi(cell);
    obj->arr[letter][num-1] = 0;
}

int spreadsheetGetValue(Spreadsheet* obj, char* formula) {
    formula++;
    int first = 0;
    int second = 0;

    char* formul = malloc((strlen(formula)+1)*sizeof(char));
    strcpy(formul, formula);

    char* token = strtok(formula, "+");
    if (token[0]>='A') {
        int letter = token[0]-'A'; token++;
        int num = atoi(token);
        first = obj->arr[letter][num-1];
    }
    else first = atoi(token);

    while (formul[0]!='+') formul++; formul++;
    if (formul[0]>='A') {
        int letter = formul[0]-'A'; formul++;
        int num = atoi(formul);
        second = obj->arr[letter][num-1];
    }
    else second = atoi(formul);

    return first+second;
}

void spreadsheetFree(Spreadsheet* obj) {
    for (int i = 0; i<26; i++) free(obj->arr[i]);
    free(obj->arr);
    free(obj);
}
