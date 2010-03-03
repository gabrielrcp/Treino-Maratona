void kmp_pre(int* table, char* needle) {
    table[0] = -1;

    for(int i = 1; needle[i]; ++i) {
        int p = table[i-1];
        while(p >= 0 and needle[i] != needle[p+1]) {
            p = table[p];
        }
        if(needle[i] == needle[p+1]) {
            table[i] = p + 1;
        }
        else table[i] = -1;
    }
}

void kmp(char* haystack, char* needle, int* table) {

    int p = -1;
    for(int i = 0; haystack[i]; ++i) {
        while(p >= 0 and needle[p+1] != haystack[i]) {
            p = table[p];
        }
        if(needle[p+1] == haystack[i]) {
            ++p;
        }
        if(needle[p+1] == 0) {
            printf("%d\n", i - p);
        }
    }
}
