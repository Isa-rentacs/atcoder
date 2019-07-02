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
    int n,m;
    cin >> n >> m;

    map<int,int> events;
    for(int i=0;i<m;++i)
    {
        int l, r;
        cin >> l >> r;
        events[l] += 1;
        events[r+1] -= 1; 
    }

    int score = 0;
    int ret = 0;
    int prev_event = -1;
    for(const auto& event : events)
    {
        if(score == m)
        {
            ret += event.first - prev_event;
        }
        prev_event = event.first;
        score += event.second;
    }
    cout << ret << endl;
}