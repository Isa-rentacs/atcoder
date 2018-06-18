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
#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
 
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

class cake {
public:
    long long a;
    long long b;
    long long c;
    long long score;
    bool operator < (const cake &arg) const{
        return score < arg.score;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    long long a, b, c;
    vector<cake> cakes = vector<cake>();
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        cin >> a >> b >> c;
        cake cake;
        cake.a = a;
        cake.b = b;
        cake.c = c;
        cake.score = 0;
        cakes.push_back(cake);
    }    

    ll ans = (1ull << 63);
    for(int b=0;b<2;++b)
    {
        for(int d=0;d<2;++d)
        {
            for(int p=0;p<2;++p)
            {
                for(size_t i=0;i<cakes.size();++i)
                {
                    cakes[i].score = cakes[i].a * (b == 0 ? 1 : -1) + cakes[i].b * (d == 0 ? 1 : -1) + cakes[i].c * (p == 0 ? 1 : -1);
                }

                sort(cakes.rbegin(), cakes.rend());
                long long temp[3] = {0};
                for(int i=0;i<m;++i)
                {
                    temp[0] += cakes[i].a;
                    temp[1] += cakes[i].b;
                    temp[2] += cakes[i].c;
                }
                ans = max(ans, abs(temp[0]) + abs(temp[1]) + abs(temp[2]));
            }
        }
    }
    cout << ans << endl;
}
