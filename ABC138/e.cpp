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
    string s, t;
    int chars=0, chart=0;
    cin >> s;
    cin >> t;
    vector<int> pos_s[26];
    for(int i=0;i<s.length();++i)
    {
        int c = s[i] - 'a';
        pos_s[c].push_back(i);
        chars |= 1 << c;
    }

    for(int i=0;i<26;++i)
    {
        pos_s[i].push_back(-1);
    }

    for(int i=0;i<t.length();++i)
    {
        chart |= 1 << (t[i] - 'a');
    }
    if ((chars & chart) != chart) {
        cout << -1 << endl;
        return 0;
    }

    int current_ind[26] = {};
    ll ret = 0;
    int pos = -1;
    for(int i=0;i<t.length();++i)
    {
        // dump(t[i])
        int c = t[i] - 'a';
        int next_pos;        
        while(true){
            next_pos = pos_s[c][current_ind[c]];
            if(next_pos > pos){
                pos = next_pos;
                break;
            }
            current_ind[c]++;
            next_pos = pos_s[c][current_ind[c]];
            if(next_pos == -1) break;
        }

        if(next_pos == -1)
        {
            fill(current_ind, current_ind + 26, 0);
            ret += s.length();
            next_pos = pos_s[c][0];
        }
        //dump(next_pos)
        pos = next_pos;
    }
    ret += pos + 1;
    cout << ret << endl;
}