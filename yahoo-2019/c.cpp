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
    ll k, a, b;
    cin >> k >> a >> b;

    ll res = 1;
    if (b - a > 2)
    {
        if(((k+1-a)%2) == 0)
        {
            res = (b - a) * ((k+1-a) / 2) + a;
        }
        else
        {
            res = (b - a) * ((k+1-a) / 2) + a + 1;
        }
        
    }
    
    cout << max(1 + k, res) << endl;
}