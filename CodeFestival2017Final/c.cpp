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
    int n;
    cin >> n;
    int d[13] = {};
    for(int i=0;i<n;++i)
    {
        int tmp;
        cin >> tmp;
        d[tmp] += 1;
    }

    int ret = -1;
    for(int i=0;i<(1<<13);++i)
    {
        vector<int> times;
        times.push_back(0);
        times.push_back(24);
        for(int j=0;j<13;++j)
        {
            if(d[j] == 1)
            {
                if((i & (1 << j)) == 0)
                {
                    // do not reverse
                    times.push_back(j);
                }
                else
                {
                    times.push_back(24 - j);
                }
            }
            else if(d[j] == 2)
            {
                times.push_back(j);
                times.push_back(24 - j);
            }
            else if(d[j] > 2)
            {
                times.push_back(j);
                times.push_back(j);
                times.push_back(24 - j);
            }
            
        }
        std::sort(times.begin(), times.end());
        
        int mini = 25;
        for(int j=1;j<times.size();++j)
        {
            //cerr << times[j] << " ";
            mini = min(mini, times[j] - times[j-1]);
        }
        //cerr << endl;

        ret = max(ret, mini);
    }

    cout << ret << endl;
}