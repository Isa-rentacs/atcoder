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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    ll ret = 0;
    int left = 0;
    int right = 0;
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }

    ll sum = a[0];

    while(true)
    {
        if (sum >= k)
        {
            ret += (n-1) - right + 1;
            if(left == right)
            {
                if(left == (n-1)) break;

                ++right;
                ++left;
                sum = a[right];
            }
            else
            {
                //shrink
                sum -= a[left];
                ++left;
            }
        }
        else
        {
            if(right != (n-1))
            {
                ++right;
                sum += a[right];
            }
            else
            {
                break;
            }
            
        }
    }
    cout << ret << endl;
}