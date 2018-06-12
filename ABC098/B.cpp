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

    int count[101] = {0};
    int n;
    string s;
    cin >> n >> s;
    for(int i=0;i<26;i++)
    {
        int first = 0;
        int last = 0;
        for(size_t j=0;j<s.length();++j)
        {
            if(s[j] == ('a' + i))
            {
                first = j;
                break;
            }
        }

        for(size_t j=s.length() - 1;j>0;--j)
        {
            if(s[j] == ('a' + i))
            {
                last = j;
                break;
            }
        }
        count[first] += 1;
        count[last] -= 1;
    }

    int ans = 0;
    int tmp = 0;
    for(int i=0;i<101;++i)
    {
        tmp += count[i];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}