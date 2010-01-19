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

void read_lines(vector<string>& v) {
    string tmp;
    int N;
    cin >> N;
    getline(cin, tmp);
    v.resize(N);
    rep(i, N) {
        getline(cin, v[i]);
    }
}

int main(void) {
    int T;
    cin >> T;
    rep(t, T) {
        vector<string> v;
        read_lines(v);
        cout << v;
    }
    return 0;
}
