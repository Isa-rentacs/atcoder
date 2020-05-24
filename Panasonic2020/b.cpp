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
    ll h, w;
    cin >> h >> w;

    ll odd_row = floor(1.0 * (w + 1) / 2);
    ll even_row = floor(1.0 * w / 2);

    ll ret = 0;
    ret += h / 2 * (odd_row + even_row);
    if((h%2) == 1)
    {
        ret += odd_row;
    }

    if(h == 1 || w == 1)
    {
        ret = 1;
    }
    cout << ret << endl;


}