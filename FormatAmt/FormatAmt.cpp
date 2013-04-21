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


class FormatAmt {
public:
	string amount(int dollars, int cents) {
        ostringstream stream;
        stream << "$";
        int digits = 1;
        while ((long long)digits*1000 <= dollars)
            digits *= 1000;
        bool first = true;
        while (true) { 
            int number = dollars/digits;
            if (first) {
                stream << number;
                first = false;
            }
            else
            {
                if (number < 10)
                    stream << "00"; 
                else if (number < 100)
                    stream << "0";
                stream << number;
            }
            dollars %= digits;
            digits /= 1000;
            if (digits == 0)
                break;
            else
                stream << ",";
        }
        stream << ".";
        if (cents < 10)
            stream << "0" << cents;
        else
            stream << cents;
        return stream.str();
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1;
    cout << "]" << endl;
    FormatAmt *obj;
    string answer;
    obj = new FormatAmt();
    clock_t startTime = clock();
    answer = obj->amount(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p2 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
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

    int p0;
    int p1;
    string p2;

    {
        // ----- test 0 -----
        p0 = 123456;
        p1 = 0;
        p2 = "$123,456.00";
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 49734321;
        p1 = 9;
        p2 = "$49,734,321.09";
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 0;
        p1 = 99;
        p2 = "$0.99";
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 249;
        p1 = 30;
        p2 = "$249.30";
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 1000;
        p1 = 1;
        p2 = "$1,000.01";
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