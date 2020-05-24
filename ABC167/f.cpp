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
    vector<pair<int,int>> vec[2];
    int open = 0, close = 0;
    for(int i=0;i<n;++i)
    {
        string tmp;
        cin >> tmp;
        int cnt = 0;
        int lowest = 0;
        for(int j=0;j<tmp.length();++j)
        {
            if(tmp[j] == '(')
            {
                cnt++;
                open++;
            }
            else
            {
                cnt--;
                close++;
            }
            if(lowest == 0)
            {
                lowest = cnt;
            }
            lowest = min(lowest, cnt);
        }

        if(cnt > 0)
        {
            vec[0].push_back(MP(lowest, cnt));
        }
        else
        {
            // reverse
            lowest = 0;
            cnt=0;
            for(int i=tmp.length()-1;i>=0;--i){
                if(tmp[i] == ')')
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
                if(lowest == 0)
                {
                    lowest = cnt;
                }
                lowest = min(lowest,cnt);
            }
            vec[1].push_back(MP(lowest,cnt));
        }
    }
    
    if(open != close)
    {
        cout << "No" << endl;
        return 0;
    }

    sort(vec[0].rbegin(), vec[0].rend());
    sort(vec[1].begin(), vec[1].end());
    bool ret = true;
    int cum = 0;
    for(int i=0;i<vec[0].size();++i)
    {
        // dump(cum)
        // dump(vec[0][i].first)
        if(cum + vec[0][i].first < 0) ret = false;
        cum += vec[0][i].second;
    }
    cum = 0;
    for(int i=vec[1].size();i>=0;--i)
    {
        // dump(cum)
        // dump(vec[1][i].first)
        if(cum + vec[1][i].first < 0) ret = false;
        cum += vec[1][i].second;
    }

    cout << (ret ? "Yes" : "No") << endl;
}