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
    int a,b,h,m;
    cin >> a >> b >> h >> m;

    double hour = (60 * h + m) * 0.5;
    double minutes = 6 * m;
    double large=0;
    double small=0;
    large=max(hour,minutes);
    small=min(hour,minutes);

    double ret = sqrt(a*a + b*b - 2 * a * b * cos((large - small) / 180 * M_PI));

    printf("%.12f\n", ret);
}