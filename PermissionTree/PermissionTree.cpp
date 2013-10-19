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


class PermissionTree {
public:
    vector <int> findHome(vector <string> folders, vector <string> users) {
        vector<int> ns;
        vector<vector<string> > us;
        tokenize(folders, ns, us);

        //for (int i = 0; i < (int)ns.size(); i++) {
        //    cout << ns[i] << ":";
        //    for (int j = 0; j < (int)us[i].size(); j++)
        //        cout << us[i][j] << ",";
        //    cout << endl;
        //}

        map<string, int> ms;
        for (int i = 0; i < (int)us.size(); i++) {
            for (int j = 0; j < (int)us[i].size(); j++) {
                string user = us[i][j];
                if (ms.find(user) == ms.end()) ms[user] = i;
                else ms[user] = intersect(ns, ms[user], i);
            }
        }

        vector<int> res;
        for (int i = 0; i < (int)users.size(); i++) {
            string user = users[i];
            if (ms.find(user) == ms.end()) res.push_back(-1);
            else res.push_back(ms[user]);
        }
        return res;
    }

    int intersect(vector<int> & ns, int last, int node) {
        vector<int> vs;
        while (last != 0) {
            vs.push_back(last);
            last = ns[last];
        }

        while (node != 0) {
            if (find(vs.begin(), vs.end(), node) != vs.end()) return node;
            node = ns[node];
        }

        return 0;
    }

    void tokenize(vector<string> & fs, vector<int> & ns, vector<vector<string> > & us) {
        for (int i = 0; i < (int)fs.size(); i++) {
            string f = fs[i];
            int p = f.find_first_of(' ');
            ns.push_back(atoi(f.substr(0, p).c_str()));
            vector<string> vs;
            for (int p1=p+1, p2; p1 < (int)f.size(); p1=p2+1) {
                p2 = f.find_first_of(',', p1);
                if (p2 == -1) p2 = f.size();
                if (p2 > p1) vs.push_back(f.substr(p1, p2-p1));
            }
            us.push_back(vs);
        }
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, vector <int> p2) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p1[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    PermissionTree *obj;
    vector <int> answer;
    obj = new PermissionTree();
    clock_t startTime = clock();
    answer = obj->findHome(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "{";
        for (int i = 0; int(p2.size()) > i; ++i) {
            if (i > 0) {
                cout << ",";
            }
            cout << p2[i];
        }
        cout << "}" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(answer.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << answer[i];
    }
    cout << "}" << endl;
    if (hasAnswer) {
        if (answer.size() != p2.size()) {
            res = false;
        } else {
            for (int i = 0; int(answer.size()) > i; ++i) {
                if (answer[i] != p2[i]) {
                    res = false;
                }
            }
        }
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

    vector <string> p0;
    vector <string> p1;
    vector <int> p2;

    {
        // ----- test 0 -----
        string t0[] = {"0 Admin","0 Joe,Phil","0 Joe"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"Admin","Joe","Phil"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {0,0,1};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"0 Admin"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"Peter","Paul","Mary"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {-1,-1,-1};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"0 Admin","2 John","0 Peter,John","0 Tim","1 John"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"John"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {2};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"0 Admin","0 Jeff","1 Mark,Tim","1 Tim,Jeff","0 Dan","4 Ed","4 Tom","4 Kyle,Ed","0 Ben","8 Rich","8 Sam","8 Tim"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"Jeff","Ed","Tim","Steve"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1,4,0,-1};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"0 Admin","0 Bob,Joe,Bob","0 Joe"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        string t1[] = {"Joe","Bob"};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {0,1};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
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
