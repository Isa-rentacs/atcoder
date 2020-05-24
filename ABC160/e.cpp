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
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    ll score_red[a] = {};
    ll score_green[b] = {};
    ll score_void[c] = {};
    ll tmp;
    priority_queue<ll, std::vector<ll>, std::greater<ll>> red;
    priority_queue<ll, std::vector<ll>, std::greater<ll>> green;

    for(int i=0;i<a;++i)
    {
        cin >> score_red[i];
    }

    for(int i=0;i<b;++i)
    {
        cin >> score_green[i];
    }

    for(int i=0;i<c;++i) cin >> score_void[i];
    sort(score_void, score_void + c, std::greater<ll>());
    sort(score_red, score_red + a, std::greater<ll>());
    sort(score_green, score_green + b, std::greater<ll>());

    for(int i=0;i<x;++i)
    {
        red.push(score_red[i]);
    }

    for(int i=0;i<y;++i)
    {
        green.push(score_green[i]);
    }

    for(int i=0;i<c;++i)
    {
        ll red_smallest = red.top();
        ll green_smallest = green.top();
        ll void_apple = score_void[i];

        if(void_apple <= red_smallest && void_apple <= green_smallest) continue;

        if(void_apple > red_smallest && void_apple > green_smallest)
        {
            if(red_smallest > green_smallest)
            {
                green.push(void_apple);
                green.pop();
            }
            else
            {
                red.push(void_apple);
                red.pop();
            }
        }else if(void_apple > red_smallest)
        {
                red.push(void_apple);
                red.pop();
        }else{
                green.push(void_apple);
                green.pop();
        }
    }

    ll ret = 0;
    while(!red.empty())
    {
        ret += red.top();
        red.pop();
    }

    while(!green.empty())
    {
        ret += green.top();
        green.pop();
    }

    cout << ret << endl;
}