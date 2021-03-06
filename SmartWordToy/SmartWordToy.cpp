#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int ft[26][26][26][26];
int vt[26][26][26][26];

#define MAX 26*26*26*26

class SmartWordToy {
public:
    int minPresses(string start, string finish, vector <string> forbid) {
        for (int ai = 0; ai < 26; ++ai) {
            for (int bi = 0; bi < 26; ++bi) {
                for (int ci = 0; ci < 26; ++ci) {
                    for (int di = 0; di < 26; ++di) {
                        ft[ai][bi][ci][di] = 1;
                    }
                }
            }
        }

        for (int ai = 0; ai < 26; ++ai) {
            for (int bi = 0; bi < 26; ++bi) {
                for (int ci = 0; ci < 26; ++ci) {
                    for (int di = 0; di < 26; ++di) {
                        vt[ai][bi][ci][di] = MAX;
                    }
                }
            }
        }

        for (int i = 0; i < (int)forbid.size(); ++i) {
            string a, b, c, d;
            istringstream is(forbid[i]);
            is >> a >> b >> c >> d;
            for (int ai = 0; ai < (int)a.size(); ++ai) {
                for (int bi = 0; bi < (int)b.size(); ++bi) {
                    for (int ci = 0; ci < (int)c.size(); ++ci) {
                        for (int di = 0; di < (int)d.size(); ++di) {
                            ft[a[ai]-'a'][b[bi]-'a'][c[ci]-'a'][d[di]-'a'] = 0;
                        }
                    }
                }
            }
        }

        vt[start[0]-'a'][start[1]-'a'][start[2]-'a'][start[3]-'a'] = 0;
        queue<string> qs;
        qs.push(start);
        while (!qs.empty()) {
            string node = qs.front();
            qs.pop();
            if (node == finish) return vt[node[0]-'a'][node[1]-'a'][node[2]-'a'][node[3]-'a'];
            for (int i = 0; i < 4; ++i) {
                for (int j = -1; j <= 1; j+=2) {
                    string tmp = node;
                    tmp[i] += j;
                    if (tmp[i] == 'a'-1) tmp[i] = 'z';
                    if (tmp[i] == 'z'+1) tmp[i] = 'a';
                    if (ft[tmp[0]-'a'][tmp[1]-'a'][tmp[2]-'a'][tmp[3]-'a'] == 1 && vt[tmp[0]-'a'][tmp[1]-'a'][tmp[2]-'a'][tmp[3]-'a'] == MAX) {
                        vt[tmp[0]-'a'][tmp[1]-'a'][tmp[2]-'a'][tmp[3]-'a'] = vt[node[0]-'a'][node[1]-'a'][node[2]-'a'][node[3]-'a']+1;
                        qs.push(tmp);
                    }
                }
            }
        }
        return -1;
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, string p1, vector <string> p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"" << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p2[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    SmartWordToy *obj;
    int answer;
    obj = new SmartWordToy();
    clock_t startTime = clock();
    answer = obj->minPresses(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 20) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    string p0;
    string p1;
    vector <string> p2;
    int p3;

    {
        // ----- test 0 -----
        p0 = "aaaa";
        p1 = "zzzz";
        string t2[] = {"a a a z","a a z a","a z a a","z a a a","a z z z","z a z z","z z a z","z z z a"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 8;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = "aaaa";
        p1 = "bbbb";
        p2.clear() /*{}*/;
        p3 = 4;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = "aaaa";
        p1 = "mmnn";
        p2.clear() /*{}*/;
        p3 = 50;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = "aaaa";
        p1 = "zzzz";
        string t2[] = {"bz a a a","a bz a a","a a bz a","a a a bz"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = -1;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = "aaaa";
        p1 = "zzzz";
        string t2[] = {"cdefghijklmnopqrstuvwxyz a a a","a cdefghijklmnopqrstuvwxyz a a","a a cdefghijklmnopqrstuvwxyz a","a a a cdefghijklmnopqrstuvwxyz"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 6;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        p0 = "aaaa";
        p1 = "bbbb";
        string t2[] = {"b b b b"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = -1;
        all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 6 -----
        p0 = "zzzz";
        p1 = "aaaa";
        string t2[] = {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefg"
            "hijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl a"
            "bcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk","abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = -1;
        all_right = KawigiEdit_RunTest(6, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
