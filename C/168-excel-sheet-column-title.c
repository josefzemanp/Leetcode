char* convertToTitle(int columnNumber) {
    char *res = malloc(8 * sizeof(*res));

    int i = 6;
    res[7] = '\0';

    while(columnNumber != 0){
        res[i] = 'A' + (columnNumber - 1) % 26;
        columnNumber = (columnNumber - 1) / 26;
        i--;
    }

    return &res[i+1];
}
