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

class BridgeCrossing {
public:
	int minTime(vector<int> times) {
		int N = times.size();
        if (N == 1) return times[0];
        if (N == 2) return max(times[0], times[1]);
        sort(times.begin(), times.end());
        int res = 100000;
        vector<bool> right(N, false);
        minTimeHelper(times, right, 0, res);
        return res;
	}

    void minTimeHelper(vector<int> & times, vector<bool> right, int sol, int & res) {
        int N = times.size();
        for (int i = 0; i < N-1; ++i) {
            for (int j = i+1; j < N; j++) {
                vector<bool> copy(right);
                int tmp = sol;
                if (!copy[i] && !copy[j]) {
                    copy[i] = copy[j] = true;
                    tmp += max(times[i], times[j]);
                    //cout << "->" << i << "," << j << ":" << tmp << endl;
                    int k;
                    for (k = 0; k < N; ++k)
                        if (!copy[k])
                            break;
                    if (k == N) {
                        res = min(res, tmp);
                        return;
                    }
                    for (k = 0; k < N; ++k)
                        if (copy[k])
                            break;
                    copy[k] = false;
                    tmp += times[k];
                    //cout << "<-" << k << ":" << tmp << endl;
                    minTimeHelper(times, copy, tmp, res);
                }
            }
        }
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    BridgeCrossing *obj;
    int answer;
    obj = new BridgeCrossing();
    clock_t startTime = clock();
    answer = obj->minTime(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p1;
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
    int p1;

    {
        // ----- test 0 -----
        int t0[] = {1,2,5,10};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 17;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
    // ----- test 1 -----
    int t0[] = {1,2,3,4,5};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 16;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
    }

    {
    // ----- test 2 -----
    int t0[] = {100};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 100;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
    }

    {
    // ----- test 3 -----
    int t0[] = {1,2,3,50,99,100};
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 162;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
