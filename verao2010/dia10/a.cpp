/****************** 
 * Problema:
 * Fonte:
 * Palavra-chave:
 *****************/

#include <set>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

#define all(x) x.begin(), x.end()
#define rep(i, N) for(int i=0;i<N;++i)
#define repd(i, N) for(int i=N-1;i>=0;--i)
#define rep3(i, j, N) for(int i=(j);i<(N);++i)
#define repd3(i, j, N) for(int i=(N)-1;i>=(j);--i)
#define foreach(it, cont) for(__typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); ++it)
#define size(x) (int((x).size()))

using namespace std;

typedef long long ll;

template <class T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
    stream << size(v) << endl;
    rep(i, size(v)) {
        stream << v[i] << endl;
    }
    return stream;
}

template <class T>
istream& operator>>(istream& stream, vector<T>& v) {
    int N;
    stream >> N;
    v.resize(N);
    rep(i, size(v)) {
        stream >> v[i];
    }
    return stream;
}

istream& operator>>(istream& stream, vector<string>& v) {
    string tmp;
    int N;
    cin >> N;
    getline(stream, tmp);
    v.resize(N);
    rep(i, N) {
        getline(stream, v[i]);
    }
    return stream;
}

string doc;

struct node_t {
    string inicio, fim;
    vector<node_t*> filhos;
};

node_t buffer[100000];
int buffer_pos;

vector<string> resp;

node_t* parse(int& pos) {
    if(pos >= size(doc) or (doc[pos] == '<' and doc[pos+1] == '/')) {
        return 0;
    }
    node_t* ret = buffer+(buffer_pos++);
    ret->filhos.clear();
    ret->inicio  = ret->fim = "";
    if(doc[pos] == '<') {
        while(doc[pos] != '>') {
            ret->inicio += doc[pos++];
        }
        ret->inicio += doc[pos++];
        while(42) {

            node_t* tmp = parse(pos);
            if(tmp) {
                ret->filhos.push_back(tmp);
            } else {
                break;
            }
        }
        while(doc[pos] != '>') {
            ret->fim += doc[pos++];
        }
        ret->fim += doc[pos++];
    } else {
        while(doc[pos] != '<') {
            ret->inicio += doc[pos++];
        }
    }
    return ret;
}

void print(node_t* node, int ident) {
    string linha;
    rep(i, ident) linha += ' ';
    if(size(node->fim) == 0) {
        linha += node->inicio;
        resp.push_back(linha);
    } else if(size(node->filhos) == 0) {
        linha += node->inicio;
        linha += node->fim;
        resp.push_back(linha);
    } else if(size(node->filhos) == 1 and size(node->filhos[0]->fim) == 0) {
        linha += node->inicio;
        linha += node->filhos[0]->inicio;
        linha += node->fim;
        resp.push_back(linha);
    } else {
        resp.push_back(linha + node->inicio);
        rep(i, size(node->filhos)) {
            print(node->filhos[i], ident+3);
        }
        resp.push_back(linha + node->fim);
    }
}

int main(void) {
    int T;
    cin >> T;
    rep(t, T) {
        vector<string> v;
        cin >> v;
        doc = "";
        resp.clear();
        foreach(it, v) doc += *it;
        buffer_pos = 0;
        int pos = 0;
        while(pos < size(doc)) {
            node_t* n = parse(pos);
            print(n, 0);
        }
        cout << resp;
    }
    return 0;
}
