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
    ll arr[n+1];
    for(int i=0;i<n;++i)
    {
        cin >> arr[i];
    }

    ll max_abs = -1;

    for(int i=0;i<n;++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            max_abs = max(max_abs, abs(arr[i] - arr[j]));
        }
    }

    cout << max_abs << endl;
}