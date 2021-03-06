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
#include <climits>

using namespace std;


class RearrangeFurniture {
public:
	int lowestEffort(vector <int> ws, vector <int> fs) {
        int N = ws.size();
        vector<bool> u(N, false);
        vector<vector<int> > cs;
        int min = INT_MAX;
        for (int i = 0; i < N; i++)
            if (ws[i] < min) min = ws[i];

        for (int i = 0; i < N; i++) {
            if (u[i]) continue;
            vector<int> c;
            int t = i;
            do {
                c.push_back(ws[t]);
                u[t] = true;
                t = fs[t];
            }
            while (t != i);
            sort(c.begin(), c.end());
            cs.push_back(c);
        }
      
        //for (int i = 0; i < (int)cs.size(); i++) {
            //for (int j = 0; j < (int)cs[i].size(); j++)
                //cout << cs[i][j] << " ";
            //cout << endl;
        //}

        int res = 0;
        for (int i = 0; i < (int)cs.size(); i++) {
            int s1 = 0;
            for (int j = 1; j < (int)cs[i].size(); j++)
                s1 += cs[i][0]+cs[i][j];
            int s2 = 2*(cs[i][0]+min);
            for (int j = 1; j < (int)cs[i].size(); j++)
                s2 += min+cs[i][j];
            res += (s1<s2)?s1:s2;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
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
	cout << "}";
	cout << "]" << endl;
	RearrangeFurniture *obj;
	int answer;
	obj = new RearrangeFurniture();
	clock_t startTime = clock();
	answer = obj->lowestEffort(p0, p1);
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
		res = answer == p2;
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
	int p2;
	
	{
        // ----- test 0 -----
        int t0[] = {5,4,7,3,10};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1,2,0,4,3};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 33;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    //{
        //// ----- test 1 -----
        //int t0[] = {3,6,2,4,10,3};
        //p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        //int t1[] = {0,1,2,3,4,5};
        //p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        //p2 = 0;
        //all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        //// ------------------
    //}

    //{
        //// ----- test 2 -----
        //int t0[] = {10,3,123,498,12,13,14,45,32,67,111,234,543,2,12,1,56,67,78,89,12,90,23,77,345,543,242,560,121,232,980,10000,12,1,6,98,67,44,21,456,3231,456,23,14,678,65,45,23,99,23};
        //p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        //int t1[] = {49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
        //p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        //p2 = 20597;
        //all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        //// ------------------
    //}

    {
        // ----- test 3 -----
        int t0[] = {1, 10, 10, 10, 10};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0, 2, 3, 4, 1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 55;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }
    
    //{
        //// ----- test 4 -----
        //int t0[] = {5246, 3023, 9853, 5854, 3541, 7131, 8763, 9467, 6738, 196, 4787, 9945, 9931, 5695, 9862, 7717, 6321, 7399, 443, 9038, 8137, 2459, 4276, 9866, 2494, 2930, 7318, 8967, 3970, 5458, 9625, 3325, 6464, 2817, 9363, 3660, 9181, 8988, 901, 1668, 5488, 1557, 6386, 3438, 8821, 1360, 154, 5445, 6805, 9495};
        //p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        //int t1[] = {22, 40, 16, 30, 27, 5, 42, 18, 14, 37, 41, 48, 39, 43, 34, 21, 35, 11, 29, 20, 7, 49, 9, 32, 2, 0, 44, 1, 45, 15, 12, 26, 33, 23, 28, 10, 25, 38, 31, 36, 24, 4, 6, 19, 46, 47, 17, 13, 8, 3};
        //p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        //p2 = 295631;
        //all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        //// ------------------
    //}

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
