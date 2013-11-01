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

double memo[4096];

class TableSeating {
public:
    double getExpected(int n, vector <int> probs) {
        vector<vector<int> > cs(n, vector<int>());
        for (int i = 0; i < n; i++) {
            int a = (1<<(i+1))-1;
            int s = n-i;
            while (s > 0) {
                cs[i].push_back(a);
                a <<= 1;
                s--;
            }
        }

        vector<vector<int> > ss(n+1, vector<int>());
        int N = (1<<n);
        for (int i = 0; i < N; i++)
            ss[count(i)].push_back(i);

        for (int i = 0; i < N; i++)
            memo[i] = 0.0;
        memo[0] = 1.0;
        for (int i = 0; i < n; i++) {
            //cout << i << ": ";
            for (int j = 0; j < (int)ss[i].size(); j++) {
                double p = memo[ss[i][j]];
                //cout << bitset<4>(ss[i][j]) << ":" << p << " ";
                if (p == 0.0) continue;
                for (int k = 0; k < (int)probs.size() && k < n; k++) {
                    if (probs[k] == 0) continue;
                    //cout << "k" << k << " ";
                    vector<int> ns;
                    for (int l = 0; l < (int)cs[k].size(); l++) {
                        //cout << bitset<4>(cs[k][l]) << " ";
                        if ((cs[k][l]&ss[i][j]) == 0)
                            ns.push_back(cs[k][l]|ss[i][j]);
                    }

                    int L = ns.size();
                    double np = p*probs[k]/100.0/L;
                    //cout << "np" << np << " ";
                    for (int l = 0; l < (int)ns.size(); l++)
                        memo[ns[l]] += np, memo[ss[i][j]] -= np;
                }
            }
            //cout << endl;
        }

        double res = 0.0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < (int)ss[i].size(); j++)
                res += i*memo[ss[i][j]];
        return res;
    }

    int count(int n) {
        int res = 0;
        while (n) {
            n &= (n-1);
            res++;
        }
        return res;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, double p2) {
    cout << "Test " << testNum << ": [" << p0 << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}";
    cout << "]" << endl;
    TableSeating *obj;
    double answer;
    obj = new TableSeating();
    clock_t startTime = clock();
    answer = obj->getExpected(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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

    int p0;
    vector <int> p1;
    double p2;

    {
        // ----- test 0 -----
        p0 = 4;
        int t1[] = {100};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 4.0;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
    // ----- test 1 -----
    p0 = 4;
    int t1[] = {0,100};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 3.3333333333333335;
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
    }

    {
    // ----- test 2 -----
    p0 = 5;
    int t1[] = {0,0,0,0,0,50,50};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 0.0;
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
    }

    {
    // ----- test 3 -----
    p0 = 12;
    int t1[] = {9,9,9,9,9,9,9,9,9,9,10};
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 7.871087929710551;
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 12;
        int t1[] = {50,50};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 10.481925778559631;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
