#define MAX_ELEMENTS 256

int sets[MAX_ELEMENTS];
int set_count;

void init(int element_count) {
    set_count = element_count;
    for(int i = 0; i < element_count; ++i) {
        sets[i] = i;
    }
}

int find(int a) { return (sets[a]==a)?(a):(sets[a]=find(sets[a])); }

bool merge(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        -- set_count;
        sets[a] = b;
    }
    return a != b;
}

