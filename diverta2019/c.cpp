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
    int ret = 0;
    cin >> n;
    vector<int> v(n);
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;++i)
    {
        cin >> v[i];
        if(v[i] >= 0) pos.push_back(v[i]);
        if(v[i] < 0) neg.push_back(v[i]);
    }

    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());
    if(pos.size() == 0)
    {
        int tmp = neg[0];
        cout << (accumulate(neg.begin(), neg.end(), 0) - neg[0] * 2) * -1 << endl;
        for(int i=0;i<n-1;++i) {
            cout << tmp << " " << neg[i+1] << endl;
            tmp -= neg[i+1];
        }
    }
    else if(neg.size() == 0)
    {
        int tmp = pos[0];
        cout << (accumulate(pos.begin(), pos.end(), 0) - pos[0] * 2) << endl;
        for(int i=0;i<n-2;++i) {
            cout << tmp << " " << pos[i+1] << endl;
            tmp -= pos[i+1];
        }
        cout << pos[pos.size() - 1] << " " << tmp << endl;;
    }
    else
    {
        int tmp = neg[0];
        cout << accumulate(pos.begin(), pos.end(), 0) + -1 * accumulate(neg.begin(), neg.end(), 0)<< endl;
        for(int i=0;i<(pos.size()-1);++i)
        {
            cout << tmp << " " << pos[i] << endl;
            tmp -= pos[i];
        }
        cout << pos[pos.size() - 1] << " " << tmp << endl;
        tmp = pos[pos.size() - 1] - tmp;
        for(int i=0;i<(neg.size() - 1);++i)
        {
            cout << tmp << " " << neg[i+1] << endl;
            tmp -= neg[i+1];
        }
    }
}