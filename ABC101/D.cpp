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
#define ull unsigned long long
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

ull s(ull arg)
{
    ull ret = 0;
    while(arg > 0)
    {
        ret += arg % 10;
        arg /= 10;
    }

    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);
    ull k;
    cin >> k;

    ull base = 1;
    ull diff = 1;
    while(k > 0)
    {
        if(((double)base / s(base)) <= ((double)(base + diff) / s(base + diff)))
        {
            cout << base << endl;
            base += diff;
            k--;
        } 
        else
        {
            base -= diff;
            diff *= 10;
            base += diff;
        }
    }
}