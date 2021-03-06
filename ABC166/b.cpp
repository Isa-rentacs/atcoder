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
    int n, k, d;
    cin >> n >> k;
    int count[n] = {};
    for(int i=0;i<k;++i)
    {
        cin >> d;
        for(int j=0;j<d;++j)
        {
            int tmp;
            cin >> tmp;
            count[tmp-1]++;
        }
    }
    int ret = 0;
    for(int i=0;i<n;++i)
    {
        if(count[i] == 0) ret++;
    }

    cout << ret << endl;
}