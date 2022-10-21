#include<bits/stdc++.h>
using namespace std;
 
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp              make_pair
#define pb              push_back
#define ins             insert
#define lb              lower_bound
#define ub              upper_bound
#define ff              first
#define ss              second
#define sz(x)           (int)(x).size()
#define vi              vector<int>
#define mii             map<int,int>
#define pii             pair<int,int>  
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define all(x)          x.begin(), x.end()
const int MOD = 1000000007;
#define ll long long int

vector<ll>primeSieve(ll *p,ll N){
    p[0] = p[1] = 1;

    for(int i=2;i*i<=N;i++){
        if(p[i]==0){
            for(int j=i*i;j<=N;j+=i){
                p[j] = 1;
            }
        }
    }

    vector<ll>v;

    for(int i=2;i<=N;i++){
        if(p[i]==0){
            v.pb(i);
        }
    }

    return v;
}

void printPrimes(ll l,ll r,vector<ll>primes){
    if(l==1){
        l++;
    }
    bool isPrime[r-l+1];
    for(ll i=0;i<=r-l;i++){
        isPrime[i] = true;
    }

    for(ll i=0;primes[i]*primes[i]<=r;i++){
        ll currentPrime = primes[i];

        ll base = (l/currentPrime)*currentPrime;
        if(base < l){
            base += currentPrime;
        }

        for(ll j=base;j<=r;j+=currentPrime){
            isPrime[base-l] = false;
        }

        if(base == currentPrime){
            isPrime[base-l] = true;
        }
    }

    for(ll i=0;i<=r;i++){
        if(isPrime[i] == true){
            cout<<i+l<<" ";
        }
    }

    cout<<endl;
}

int main(){
    FIO;
    
    ll N = 100000;
    ll p[N] = {0};

    vector<ll>primes = primeSieve(p,N);
    int t;
    cin>>t;

    while(t--){
        ll l,r;
        cin>>l>>r;

        printPrimes(l,r,primes);
    }    
}