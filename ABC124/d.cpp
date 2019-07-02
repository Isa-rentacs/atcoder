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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool isStartZero = s[0] == '0';

    vector<pair<int,int>> starts;

    int cnt = 0;
    int begin = 0;
    starts.PB(MP(0, s[0] - '0'));
    for(int i=1;i<s.length();++i)
    {
        if(s[i-1] != s[i])
        {
            starts.PB(MP(i, s[i] - '0'));
        }
    }

    int ret = 0;
    for(int i=0;i<starts.size();++i)
    {
        if(starts[i].second == 0)
        {
            if (i + 2 * k >= starts.size())
            {
                ret = max(ret, (int)s.length() - starts[i].first);
            }
            else
            {
                ret = max(ret, starts[i + 2 * k].first - starts[i].first);
            }
        }
        else
        {
            if (i + 2 * k + 1 >= starts.size())
            {
                ret = max(ret, (int)s.length() - starts[i].first);
            }
            else
            {
                ret = max(ret, starts[i + 2 * k + 1].first - starts[i].first);
            }        
        }
    }

    cout << ret << endl;
}