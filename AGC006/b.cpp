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

int ret[200000] = {};
bool used[200001] = {};

int main(){
    std::ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    if(x == 1 || x == 2*n-1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        if(n == 2)
        {
            for(int i=1;i<=3;++i) cout << i << endl;
        }
        else
        {
            if(x == (2 * n - 2))
            {
                ret[n-2] = x-1;
                ret[n-1] = x;
                ret[n] = x+1;
                ret[n+1] = x-2;
                used[x-2] = true;
                used[x-1] = true;
                used[x] = true;
                used[x+1] = true;
            }
            else
            {
                ret[n-2] = x+1;
                ret[n-1] = x;
                ret[n] = x-1;
                ret[n+1] = x+2;
                used[x-1] = true;
                used[x] = true;
                used[x+1] = true;
                used[x+2] = true;
            }
            int cur = 1;
            for(int i=0;i<2*n-1;++i)
            {
                while(used[cur])
                {
                    cur++;
                }
                if(ret[i] == 0)
                {
                    ret[i] = cur;
                    used[cur] = true;
                }
            }
            for(int i=0;i<2*n-1;++i)
            {
                cout << ret[i] << endl;
            }
        }
    }
}