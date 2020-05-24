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

int k;
bool dfs(int depth, vector<int> &stack)
{
    int prev = stack.back();
    bool ret = false;
    if(depth == stack.size())
    {
        k--;
        if (k == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    for(int i=-1;i<=1;++i)
    {
        int next = prev + i;
        if(next < 0 || 10 <= next) continue;

        stack.push_back(next);
        ret = dfs(depth, stack);
        if(ret) break;
        stack.pop_back();
    }

    return ret;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> k;
    int num_digits = 1;
    vector<int> stack;
    while(k > 0)
    {
        for(int s = 1; s <= 9; ++s)
        {
            stack.push_back(s);
            if(dfs(num_digits, stack))
            {
                for(int tmp: stack)
                {
                    cout << tmp;
                }
                cout << endl;
                return 0;
            }
            stack.pop_back();
        }
        num_digits++;
    }
}