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
    vector<pair<ll,int>> v[11];

    v[1].push_back(MP(0ll, 0));

    for(int i=1;i<=9;++i)
    {
        for(pair<ll, int> tmp: v[i])
        {
            int last_digit = tmp.first % 10;
            int max_digit = tmp.second;
            for(int j=0;j<=max_digit+1;++j)
            {
                v[i+1].push_back(MP(tmp.first * 10 + j, j == max_digit + 1 ? max_digit + 1 : max_digit));
            }
        }
    }
    int n;
    cin >> n;

    for(pair<ll, int> tmp: v[n])
    {
        ll x = tmp.first;
        char c[n+1] = {};
        for(int i=0;i<n;++i)
        {
            c[i] = x % 10 +'a';
            x /= 10;
        }
        string s(c);
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}