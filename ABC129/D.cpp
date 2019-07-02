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

bool field[2002][2002];
int horizontal[2002][2002];
int vertical[2002][2002];
int main(){
    std::ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    for(int i=1;i<=h;++i){
        for(int j=1;j<=w;++j){
            char c;
            cin >> c;
            if(c == '.')
            {
                field[i][j] = true;
            }
        }
    }

    for(int i=1;i<=h;++i)
    {
        int cnt = 0;
        for(int j=1;j<=w;++j)
        {
            if(field[i][j]){
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            horizontal[i][j] = cnt;            
        }

        int fill = 0;
        for(int j=w;j>=0;--j)
        {
            if(fill == 0)
            {
                fill = horizontal[i][j];
            }

            if(field[i][j]){
                horizontal[i][j] = fill;
            }
            else
            {
                fill = 0;
            }
        }
    }

    for(int i=1;i<=w;++i)
    {
        int cnt=0;
        for(int j=1;j<=h;++j)
        {
            if(field[j][i]){
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            vertical[j][i] = cnt;            
        }

        int fill = 0;
        for(int j=h;j>=0;--j)
        {
            if(fill == 0)
            {
                fill = vertical[j][i];
            }

            if(field[j][i]){
                vertical[j][i] = fill;
            }
            else
            {
                fill = 0;
            }
        }

    }

    int ret = 0;
    for(int i=1;i<=h;++i)
    {
        for(int j=1;j<=w;++j)
        {
            ret = max(ret, horizontal[i][j] + vertical[i][j] - 1);
        }
    }

    cout << ret << endl;
}