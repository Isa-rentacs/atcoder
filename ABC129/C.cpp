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
    int n, m;
    set<int> broken;
    cin >> n >> m;
    for (int i=0;i<m;++i)
    {
        int tmp;
        cin >> tmp;
        broken.insert(tmp);
    }

    ll dp[n+1] = {};
    dp[0] = 1;
    for(int i=1;i<=n;++i)
    {
        if (broken.find(i) != broken.end())
        {
            dp[i] = 0;
        }
        else
        {
            if (i==1)
            {
                dp[i] = dp[i-1];
            }
            else
            {
                dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
            }        
        }
    }

    cout << dp[n] << endl;
}