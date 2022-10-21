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

int power(int a,int n,int m){
    int res = 1;
    while(n > 0){
        if(n%2){
            res = (res*a)%m;
            n--;
        }
        else{
            a = (a*a)%m;
            n = n>>1;
        }
    }

    return res;
}

int main(){
    FIO;

    int t,a,b,m;

    cin>>t;

    while(t--){
        cin>>a>>m;

        cout<<"a^-1 = "<<power(a,m-2,m)<<endl;
    }
}