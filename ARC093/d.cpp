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

int field[100][100];

int main(){
    std::ios::sync_with_stdio(false);
    int w, b;
    cin >> w >> b;
    
    for(int i=0;i<100;++i)
    {
        for(int j=0;j<100;++j)
        {
            if(i < 50)
            {
                field[i][j] = 0;
            }
            else
            {
                field[i][j] = 1;
            }
        }
    }

    while(b > 1)
    {
        int row = (b-1) / 50;
        int col = (b-1) % 50;
        field[row * 2][col * 2] = 1;
        --b;
    }

    while(w > 1)
    {
        int row = (w-1) / 50;
        int col = (w-1) % 50;
        field[99 - row * 2][col * 2] = 0;
        --w;
    }

    cout << "100 100" << endl;
    for(int i=0;i<100;++i)
    {
        for(int j=0;j<100;++j)
        {
            cout << (field[i][j] == 0 ? "." : "#");
        }
        cout << endl;
    }
}