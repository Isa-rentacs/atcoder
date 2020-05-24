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

ll dp[100001][3] = {};

int main(){
    std::ios::sync_with_stdio(false);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> op;
    for(int i=0;i<n;++i)
    {
        string tmp;
        cin >> tmp;
        op.push_back(tmp);
    }

    string res = "Yes";
    vector<char> ops;
    for(int i=0;i<n;++i)
    {
        string cur = op[i], next;
        if(i != n-1)
        {
            next = op[i+1];
        }

        int *x, *y;
        string incx, incy;
        if(cur == "AB")
        {
            x = &a;
            y = &b;
        } else if(cur == "BC")
        {
            x = &b;
            y = &c;
        } else {
            x = &a;
            y = &c;
        }

        if(*x == 0 && *y == 0)
        {
            res = "No";
            break;
        }

        if(*x > *y)
        {
            *x = *x - 1;
            *y = *y + 1;
            ops.push_back(cur[1]);
        }else if(*x < *y)
        {
            *x = *x + 1;
            *y = *y - 1;
            ops.push_back(cur[0]);
        }else{
            if(i == n-1)
            {
                ops.push_back(cur[0]);
            }
            else
            {
                if(cur == next)
                {
                    *x = *x + 1;
                    *y = *y - 1;
                    ops.push_back(cur[0]);
                }else{
                    if(cur == "AB")
                    {
                        if(next == "AC")
                        {
                            *x = *x + 1;
                            *y = *y - 1;
                            ops.push_back(cur[0]);
                        }
                        else 
                        {
                            *x = *x - 1;
                            *y = *y + 1;
                            ops.push_back(cur[1]);
                        }
                    }else if(cur == "AC")
                    {
                        if(next == "AB")
                        {
                            *x = *x + 1;
                            *y = *y - 1;
                            ops.push_back(cur[0]);
                        }
                        else 
                        {
                            *x = *x - 1;
                            *y = *y + 1;
                            ops.push_back(cur[1]);
                        }
                    }
                    else //BC
                    {
                        if(next == "AB")
                        {
                            *x = *x + 1;
                            *y = *y - 1;
                            ops.push_back(cur[0]);
                        }
                        else 
                        {
                            *x = *x - 1;
                            *y = *y + 1;
                            ops.push_back(cur[1]);
                        }

                    }
                }
            }
        }
    }
    cout << res << endl;
    if(res == "Yes")
    {
        for(int i=0;i<ops.size();++i)
        {
            cout << ops[i] << endl;
        }
    }
}