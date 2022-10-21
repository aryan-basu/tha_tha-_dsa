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

int phi[1000001];

void init(int maxN){
    for(int i=1;i<=maxN;i++){
        phi[i] = i;
    }

    for(int i=2;i<=maxN;i++){
        if(phi[i] == i){
            for(int j=i;j<=maxN;j+=i){
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
}
//If gcd(x,N) = d, then gcd(x/d,N/d) = 1, Thus we find the coprimes of N/D from 1 to N
int getCount(int d,int N){
    return phi[N/d];
}

int main(){
    FIO;

    init(1000000);

    int q,n;
    cin>>q;

    while(q--){
        cin>>n;

        int res = 0;

        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                int d1 = i;
                int d2 = n/i;

                res += d1*getCount(d1,n);

                if(d1!=d2){
                    res += d2*getCount(d2,n);
                }
            }
        }

        cout<<res<<endl;
    }
}