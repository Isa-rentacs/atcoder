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
    int count = 0, k;
    string s;
    cin >> s >> k;
    set<string> setstr;
    for(int i=0;i<26;++i)
    {
        char c = 'a' + i;
        string tempstr = "";
        for(size_t j=0;j<s.length();++j)
        {
            if(s[j] == c)
            {
                tempstr = "";
                for(size_t p=0;p<k && (p+j) < s.length();++p)
                {
                    tempstr += s[p+j];
                    setstr.insert(tempstr);
                }
            }
        }
        if(setstr.size() >= k) break;
    }

    set<string>::iterator it = setstr.begin();
    for(int i=1;i<k;++i)
    {
        ++it;
    }
    cout << *it << endl;
}
