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

    int start_from_b = 0;
    int start_from_w = 0;

    for(int i=0;i<s.length();++i)
    {
        if(s[i] == '0') {
            //black
            if((i%2) == 0)
            {
                start_from_w++;
            }
            else
            {
                start_from_b++;
            }
        }
        else
        {
            if((i%2) == 0)
            {
                start_from_b++;
            }
            else
            {
                start_from_w++;
            }
        }
    }
    cout << min(start_from_b, start_from_w) << endl;
}