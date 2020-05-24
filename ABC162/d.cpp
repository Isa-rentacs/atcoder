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

bool all_diff(char a, char b, char c)
{
    return a != b && b !=c && a != c;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ret = 0;
    ll cnt[3] = {}; // RGB
    for(int i=0;i<s.length();++i)
    {
        if(s[i] == 'R'){
            cnt[0]++;
        } else if(s[i] == 'G')
        {
            cnt[1]++;
        }else{
            cnt[2]++;
        }
    }
    ret = cnt[0] * cnt[1] * cnt[2];
    for(int i=1;(i*2)<s.length();++i)
    {
        for(int j=0;j + i*2 < s.length();++j)
        {
            if(all_diff(s[j], s[j+i], s[j+2 * i]))
            {
                ret--;
            }
        }
    }
    cout << ret << endl;
}