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
    cin >> n;
    ll a[n];
    vector<ll> negs;
    vector<ll> poss;
    for(int i=0;i<n;++i) {
        ll tmp;
        cin >> tmp;
        if (tmp > 0) {
            poss.push_back(tmp);
        } else {
            negs.push_back(tmp);
        }
    }
    ll ret = 0;
    if((negs.size() % 2) == 0)
    {
        for(int i=0;i<negs.size();++i)
        {
            ret += negs[i] * -1;
        }

        for(int i=0;i<poss.size();++i)
        {
            ret += poss[i];
        }    
    }
    else
    {
        sort(negs.begin(), negs.end());
        sort(poss.begin(), poss.end());
        if(poss.empty())
        {
            ret += negs.back();
        }
        else
        {
            ll last = negs.back() + poss.front();
            if (last < 0) {
                last *= -1;
            }
            ret += last;
        }

        for(int i=0;i<negs.size()-1;++i)
        {
            ret += negs[i] * -1;
        }

        for(int i=1;i<poss.size();++i)
        {
            ret += poss[i];
        }

    }

    cout << ret << endl;
}