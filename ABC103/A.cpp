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
    int cost = 1 << 20;
    int a[3];

    cin >> a[0] >> a[1] >> a[2];

    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            for(int k=0;k<3;++k)
            {
                if(i==j || j==k || i==k) continue;

                cost = min(cost, abs(a[j] - a[i]) + abs(a[k] - a[j]));
            }
        }
    }
    cout << cost << endl;
}