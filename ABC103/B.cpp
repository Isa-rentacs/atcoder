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
    string s,t;
    cin >> s >> t;

    int count[2][26] = {0};
    bool possible = false;

    if(s == t){
        possible = true;
    }
    else
    {
        for(int i=0;i<s.length();++i)
        {
            s = s[s.length() - 1] + s.substr(0, s.length() - 1);
            if ( s == t )
            {
                possible = true;
                break;
            }
        }
    }
    cout << (possible ? "Yes" : "No") << endl;
}