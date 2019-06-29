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
    string s;
    cin >> s;
    int cnt[28] = {};
    for(int i=0;i<4;++i)
    {
        cnt[s[i] - 'A']++;
    }

    bool ret = true;
    int twice = 0;
    for(int i=0;i<26;++i) {
        if (cnt[i] != 0 && cnt[i] != 2)
        {
            ret = false;
        } 
        else if(cnt[i] == 2)
        {
            twice++;
        }
    }

    if (twice == 2 && ret)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}