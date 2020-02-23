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

bool predication(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    return a.first.second < b.first.second;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<pair<int,int>,int>> enemies;
    for(int i=0;i<n;++i) {
        int x, h;
        cin >> x >> h;
        enemies.push_back(MP(MP(x-d, x+d), h));
    }
    sort(enemies.begin(), enemies.end(), predication);

    ll ret = 0;
    ll dam = 0;
    ll cur_pos = -1 * (1 << 30);
    queue<pair<int,int>> q;
    for(int i=0;i<n;++i) {
        while(!q.empty() && q.front().first < enemies[i].first.first) {
            dam -= q.front().second;
            q.pop();
        }
        if (dam < enemies[i].second)
        {
            int bomb_count = ceil((enemies[i].second - dam) * 1.0 / a);
            ret += bomb_count;
            dam += bomb_count * a;
            q.push(MP(enemies[i].first.second, bomb_count * a));
        }        
    }

    cout << ret << endl;
}