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
    int p[n];
    for(int i=0;i<n;++i)
    {
        cin >> p[i];
    }

    int ret = 0;
    for(int i=1;i<n-1;++i)
    {
        if((p[i-1] < p[i] && p[i] < p[i+1]) || (p[i+1] < p[i] && p[i] < p[i-1]))
        {
            ret++;
        }
    }

    cout << ret << endl;
}