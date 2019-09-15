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
    int k;
    cin >> k;
    vector<ll> a(k);
    for(int i=0;i<k;++i)
    {
        cin >> a[i];
    }

    ll maxi = 2;
    ll mini = 2;
    for(int i=k-1;i>=0;--i)
    {
        ll max_mul = maxi / a[i] * a[i];
        if(max_mul < mini || maxi < max_mul)
        {
            maxi = -1;
            break;
        }

        maxi = max_mul + a[i] - 1;
        mini = mini % a[i] == 0 ? mini : (mini / a[i] + 1) * a[i];
    }
    
    if(maxi == -1)
    {
        cout << maxi << endl;
    }
    else
    {
        cout << mini << " " << maxi << endl;
    }



}