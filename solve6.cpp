#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define VecPrint(v) cout<<#v<<" = ";for (auto &c : v) cout<<c<<' '; cout<<endl;
#define GET(i, j) lines[(i)][(j)]

using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;

int dirs[] = {-1, 0, 1, 0, -1};
vector<string> lines;
int si;
int sj;
int N;

int check_loop() {
    /* map<int, int> vi; */
    map<int, int> cache;
    int d = 0;
    int key = si * N*4 + sj * 4 + d;
    bool exit = false;
    for (; !cache.count(key);) {
        cache[key] = 1;
        /* vi[si*N*4 + sj*4] = 1; */
        int ni = si + dirs[d];
        int nj = sj + dirs[d+1];
        if (ni >= N || nj >= N || ni < 0 || nj < 0) {
            exit = true;
            break;
        }
        else if (GET(ni, nj) == '#') {
            d = (d + 1) % 4;
        } else {
            si = ni;
            sj = nj;
        }
        key = si * N*4 + sj*4 + d;
    }
    if (exit)
        return 0;
    else
        return 1;
}

int main() {
    string line;
    while (getline(cin, line)) {
        lines.push_back(line);
    }
    N = lines.size();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (GET(i, j) == '^') {
                si = i, sj = j;
                break;
            }

    int ri = si, rj = sj;
    /* DBG(vi.size()); */
    /* lines[8][1] = '#'; */
    /* auto loop = check_loop(); */
    /* DBG(loop); */

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        DBG(i);
        for (int j = 0; j < N; ++j) {
            if (GET(i, j) == '#')
                continue;
            if (GET(i, j) == '^')
                continue;
            lines[i][j] = '#';
            si = ri, sj = rj;
            int inc = check_loop();
            /* cout << i << " " << j << " " << inc << endl; */
            ans += inc;
            lines[i][j] = '.';
        }
    }
    DBG(ans);

    /* DBG(si); */
    /* DBG(sj); */
    return 0;

}
