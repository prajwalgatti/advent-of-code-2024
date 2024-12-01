#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define VecPrint(v) cout<<#v<<" = ";for (auto &c : v) cout<<c<<' '; cout<<endl;
using namespace std;

/* int par1() { */
/*     long long best = 0x3f3f3f3f; */
/*     for (int i = 0; i < n; ++i) { */
/*         long long sum = 0; */
/*         for (int j = 0; j < n; ++j) { */
/*             int d = std::abs(a[j]-b[(i+j)%n]); */
/*             sum += d; */
/*         } */
/*         /1* DBG(sum); *1/ */
/*         best = std::min(sum, best); */
/*     } */
/*     cout << best << endl; */
/* } */

int main() {
    vector<int> a, b;
    int t1, t2;
    map<int, int> B;
    
    while (cin >> t1 >> t2) {
        a.push_back(t1);
        b.push_back(t2);
        B[t2] += 1;
    }
    int n = a.size();
    long long sum = 0;
    for (auto &c : a) {
        if (!B.count(c))
            continue;
        sum += c * B[c];
    }
    cout << sum << endl;
    /* sort(a.begin(), a.end()); */
    /* sort(b.begin(), b.end()); */
    /* VecPrint(a); */
    /* VecPrint(b); */

    return 0;

}
