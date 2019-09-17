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
    int n = s.length();
    int odd[2][100001] = {}; // R, L
    int even[2][100001] = {}; // R, L
    int r_cont = 1;
    int l_cont = 1;
    for(int i=1;i<n;++i)
    {
        if(s[i] == 'R')
        {
            r_cont++;
        }
        else
        {
            even[0][i-1] = r_cont / 2 + r_cont % 2;
            odd[0][i-1] = r_cont / 2;
            r_cont = 0;
        }
        
        if(s[n-1-i] == 'L')
        {
            l_cont++;
        }
        else
        {
            even[1][n-i] = l_cont / 2 + l_cont % 2;
            odd[1][n-i] = l_cont / 2;
            l_cont = 0;
        }
    }

    for(int i=0;i<n;++i)
    {
        if(s[i] == 'R')
        {
            if(s[i+1] == 'L')
            {
                cout << even[0][i] + odd[1][i+1];
            }
            else
            {
                cout << 0;
            }
        }
        else
        {
            if(s[i-1] == 'R')
            {
                cout << even[1][i] + odd[0][i-1];
            }
            else
            {
                cout << 0;
            }
        }
        cout << " \n"[i == (n-1)];
    }
}