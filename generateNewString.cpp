void generateNewArray(char* s){
    int i = 0; int j = 1;
    while (j != strlen(s) - 1) {
        if (isdigit(s[i]) && isalpha(s[j])) {
            i = j;
            j += 1;
        }
        else swapChar(&s[i], &s[j]);
    }
    for (int k = 0; k < strlen(s); k++) {
        cout << s[k];
    }
}
