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

int calc_beauty(int i, int j, int k, int d)
{
    int ret = 0;
    ret += (abs(i-j) == d ? 1 : 0);
    ret += (abs(j-k) == d ? 1 : 0);

    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);

    for(int d=0;d<20;d++)
    {
        int m = 3;
        for(int n=1;n<(d+10);n++)
        {
            map<int,int> d_to_count;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    for(int k=1;k<=n;++k)
                    {
                        d_to_count[calc_beauty(i,j,k,d)]++;
                    }
                }
            }

            int temp = 0;
            for(pair<int,int> kvp : d_to_count)
            {
                cout << "beauty = " << (kvp).first << " : count = " << kvp.second << endl;
                temp += kvp.first * kvp.second;
            }
            cout << "sum = " << temp << endl;

            cout << "=== end of n = " << n << " ===" <<endl;
        }
        cout << "=== end of d = " << d << " ===" << endl;
    }
}