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

struct task {
    task(ll x, ll y)
    {
        len = x;
        deadline = y;
    }

    ll len;
    ll deadline;

    bool operator<(const task &lhs) const {
        if(this->deadline == lhs.deadline)
        {
            return this->len < lhs.len;
        }
        else
        {
            return this->deadline < lhs.deadline;
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<task> tasks;
    for(int i=0;i<n;++i)
    {
        int len, dl;
        cin >> len >> dl;
        tasks.PB(task(len, dl));
    }

    sort(tasks.begin(), tasks.end());

    ll cur = 0;
    bool ret = true;
    for(int i=0;i<n;++i)
    {
        cur += tasks[i].len;
        if (cur > tasks[i].deadline)
        {
            ret = false;
            break;
        }
    }

    cout << (ret ? "Yes" : "No") << endl;
}