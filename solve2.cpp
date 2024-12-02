#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define VecPrint(v) cout<<#v<<" = ";for (auto &c : v) cout<<c<<' '; cout<<endl;
using namespace std;


bool check(int a, int b) {
    if (a+1 <= b && b <= a+3)
        return true;
    return false;
}

int main() {
    string line;
    int cnt = 0;
    while( getline( cin, line) )
    {
        std::istringstream iss(line); // Create a string stream for the line
        std::vector<int> row; // Temporary vector for the current row
        int num;
        while (iss >> num) { // Extract integers from the line
            row.push_back(num);
            /* cout << num; */
        }

        if (row[0] > row[row.size()-1]) {
            std::reverse(row.begin(), row.end());
        }

        bool safe = true;
        bool found = false;
        for (int t = 0; t < row.size(); ++t) {
            safe = true;
            vector<int> vec = row;
            vec.erase(vec.begin() + t);
            /* VecPrint(vec); */
            for (int i = 1; i < vec.size(); ++i) {
                if (!check(vec[i-1], vec[i])) {
                    safe = false;
                    break;
                }
            }
            /* cout << safe << endl; */
            if (safe) {
                found = true;
                break;
            }

        }
        if (found)
            cnt ++;
    }
    cout << cnt << endl;


    return 0;

}
