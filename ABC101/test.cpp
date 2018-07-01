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

int s(int k)
{
    int ret =0;
    int temp = k;
    while(temp > 0)
    {
        ret += temp % 10;
        temp /= 10;
    }    

    return ret;
}


int main(){
    std::ios::sync_with_stdio(false);

    for(int i=100;i<1000;++i)
    {
        cout << i << "\t" << (double)i / s(i) << endl;
    }
}