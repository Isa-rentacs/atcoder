#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

int main(){
    std::ios::sync_with_stdio(false);
    string s;
    deque<char> pre, suf;
    int q, t, f;
    int reverse = 0;
    char c;
    cin >> s >> q;
    for(int i=0;i<q;++i)
    {
        cin >> t;
        if(t == 1)
        {
            reverse = 1 - reverse;
        }
        else
        {
            cin >> f >> c;
            string app(1, c);
            if((f == 1 && !reverse) || (f == 2 && reverse))
            {
                pre.push_front(c);
            }
            else
            {
                suf.push_back(c);
            }
        }
    }
    string ret = string(pre.begin(), pre.end()) + s + string(suf.begin(), suf.end());
    if(reverse)
    {
        ret = string(ret.rbegin(), ret.rend());
    }

    cout << ret << endl;
}