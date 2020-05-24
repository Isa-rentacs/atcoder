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

ll pow_5(ll x)
{
    return x * x * x * x * x;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll x;
    cin >> x;
    for(int i=-122;i<=122;++i)
    {
        for(int j=-122;j<=122;++j)
        {
            if(pow_5(i) - pow_5(j) == x)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}