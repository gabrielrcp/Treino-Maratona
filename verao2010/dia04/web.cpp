// PKU: 2050

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
#include <algorithm>
#include <functional>

#define rep(i, N) for(int i=0;i<(N);++i)
#define repd(i, N) for(int i=(N)-1;i>=0;--i)
#define rep3(i, j, N) for(int i=(j);i<(N);++i)
#define repd3(i, j, N) for(int i=(N)-1;i>=(j);--i)

using namespace std;

vector<string> split(string str) {
    string tmp;
    vector<string> ret;
    str += ' ';
    int K = str.size();
    rep(i, K) {
        if(isalpha(str[i])) {
            tmp += tolower(str[i]);
        } else {
            if(tmp.size() > 0) {
                ret.push_back(tmp);
                tmp = "";
            }
        }
    }
    return ret;
}

template <class T> vector<T>& operator+=(vector<T>& v1, vector<T>& v2) {
    int N = v2.size();
    rep(i, N) {
        v1.push_back(v2[i]);
    }
    return v1;
}

int main(void) {

    int N;

    vector<vector<string> > docs;

    map<string, vector<pair<int, int> > > dict;

    vector<set<string> > palavras;

    scanf("%d ", &N);
    docs.resize(N);
    palavras.resize(N);

    rep(i, N) {
        char str[1000];
        int linha = 0;
        while(gets(str) and strcmp(str, "**********") != 0) {
            vector<string> tmp = split(str);
            docs[i].push_back(str);
            rep(j, int(tmp.size())) {
                dict[tmp[j]].push_back(make_pair(i, linha));
                palavras[i].insert(tmp[j]);
            }
            ++linha;
        }
    
    }

    int M;
    scanf("%d ", &M);

    rep(i, M) {
        char str[1000];
        gets(str);
        vector<string> tmp = split(str);
        vector<pair<int, int> > resp;
        if(tmp.size() == 1) {
            resp = dict[tmp[0]];
            sort(resp.begin(), resp.end());
            resp.erase(unique(resp.begin(), resp.end()), resp.end());
        } else if(tmp.size() == 3 and tmp[1] == "or") {
            resp = dict[tmp[0]];
            resp += dict[tmp[2]];

            sort(resp.begin(), resp.end());
            resp.erase(unique(resp.begin(), resp.end()), resp.end());
        } else if(tmp.size() == 3 and tmp[1] == "and") {
            vector<pair<int, int> > resp1(dict[tmp[0]]);
            vector<pair<int, int> > resp2(dict[tmp[2]]);
            vector<pair<int, int> > resp3 = resp1;

            resp3 += resp2;
            sort(resp3.begin(), resp3.end());
            resp3.erase(unique(resp3.begin(), resp3.end()), resp3.end());

            vector<int> s1, s2;
            set<int> s3;

            rep(k, int(resp1.size())) s1.push_back(resp1[k].first);
            rep(k, int(resp2.size())) s2.push_back(resp2[k].first);

            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            s1.erase(unique(s1.begin(), s1.end()), s1.end());
            s2.erase(unique(s2.begin(), s2.end()), s2.end());

            for(int x = 0, y = 0; x < int(s1.size()) and y < int(s2.size()); ) {
                if(s1[x] == s2[y]) {
                    s3.insert(s1[x]);
                    ++x; ++y;
                } else if(s1[x] < s2[y]) {
                    x++;
                } else {
                    y++;
                }
            }

            rep(k, int(resp3.size())) {
                if(s3.count(resp3[k].first)) {
                    resp.push_back(resp3[k]);
                }
            }
        }
        
        if(tmp.size() != 2) {
            if(resp.size() > 0) {
                int last = resp[0].first;
                rep(k, int(resp.size())) {
                    if(last != resp[k].first) {
                        printf("----------\n");
                        last = resp[k].first;
                    }
                    printf("%s\n", docs[resp[k].first][resp[k].second].c_str());
                }
            } else {
                printf("Sorry, I found nothing.\n");
            }
        } else {
            int foi = 0;
            rep(i, N) {
                if(palavras[i].count(tmp[1]) == 0) {
                    if(foi == 1) {
                        printf("----------\n");
                    }
                    foi = 1;
                    rep(k, int(docs[i].size())) {
                        printf("%s\n", docs[i][k].c_str());
                    }
                }
            }
            if(foi == 0) {
                printf("Sorry, I found nothing.\n");
            }
        }
        printf("==========\n");
    }
    return 0;
}
