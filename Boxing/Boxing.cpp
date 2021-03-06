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

class Boxing {
public:
    int maxCredit(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> e) {
        int ai = 0, bi = 0, ci = 0, di = 0, ei = 0, res = 0;
        for (int t = 0; t <= 180000; t++) {
            vector<int> best(5, INT_MAX);
            best[0] = go(a, ai, t);
            best[1] = go(b, bi, t);
            best[2] = go(c, ci, t);
            best[3] = go(d, di, t);
            best[4] = go(e, ei, t);
            sort(best.begin(), best.end(), greater<int>());
            if (best[2] == INT_MAX) break;
            if (best[2] <= t+1000) {
                t = best[2];
                res++;
            }
        }

        return res;
    }

    int go(vector<int> & v, int & i, int t) {
        while (i < (int)v.size()) {
            if (v[i] >= t)
                return v[i];
            i++;
        }

        return INT_MAX;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, vector <int> p4, bool hasAnswer, int p5) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p3.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p3[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p4.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p4[i];
    }
    cout << "}";
    cout << "]" << endl;
    Boxing *obj;
    int answer;
    obj = new Boxing();
    clock_t startTime = clock();
    answer = obj->maxCredit(p0, p1, p2, p3, p4);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p5 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p5;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
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

    vector <int> p0;
    vector <int> p1;
    vector <int> p2;
    vector <int> p3;
    vector <int> p4;
    int p5;

    {
        // ----- test 0 -----
        int t0[] = {1,2,3,4,5,6};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1,2,3,4,5,6,7};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1,2,3,4,5,6};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {0,1,2};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {1,2,3,4,5,6,7,8};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        p5 = 6;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {100,200,300,1200,6000};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1.clear() /*{}*/;
        int t2[] = {900,902,1200,4000,5000,6001};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {0,2000,6002};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {1,2,3,4,5,6,7,8};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        p5 = 3;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {5000,6500};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {6000};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {6500};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {6000};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        int t4[] = {0,5800,6000};
        p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
        p5 = 1;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
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
