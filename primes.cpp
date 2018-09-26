#include <bits/stdc++.h>
using namespace std;
#define fastcin ios_base::sync_with_stdio(false)
#define precisecout cout << fixed << setprecision(10)
#define pb push_back
#define mk make_pair
#define mkt make_tuple
#define binary(x) bitset<8*sizeof(x)>(x)
#define zero(x) memset(x, 0, sizeof(x))
#define init(x, i) memset(x, i, sizeof(x))
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define ll long long
#define inf 0x3f3f3f3f

#ifdef ebug
#define dprintf printf
#else
#define dprintf if(false) printf
#endif

const int N = 1e5;
bitset<N> primesBool;
vector<int> primesVector;
void buildPrimes(){
    primesVector.clear();
    primesBool.set();
    primesBool[0] = false;
    primesBool[1] = false;

    for(int i = 2; i < N; i++){
        if(primesBool[i]){
            primesVector.pb(i);
            for(int j = i+i; j < N; j += i)
                primesBool[j] = false;
        }
    }
}

bool isPrime(int val){
    if(val < N) {
        return primesBool[val];
    }

    for(int p : primesVector){
        if(val % p == 0)
            return false;
        if(p * 1ll * p > val)
            return true;
    }
    return true;
}

int main(){
    buildPrimes();

    for(int i = 0; i < 100; i++)
        cout << i << " " << isPrime(i) << endl;
}