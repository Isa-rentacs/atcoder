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
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 0;
    for(int i=0;i<n;++i)
    {
        if(a[i] == b[i] && b[i] == c[i])
        {
            // no increment
        }
        else if(a[i] == b[i] || b[i] == c[i] || a[i] == c[i])
        {
            ans += 1;
        }
        else
        {
            ans += 2;
        }
        
    }

    cout << ans << endl;
}