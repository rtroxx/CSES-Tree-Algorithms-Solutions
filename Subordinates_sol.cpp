/*
     If you can't think of solution think some well known algorithm related to it!
     Always BE COOL!
     Last minute hustle might give you AC
            -----RATNESH KUMAR TIWARY
*/
 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define re(i,a,b) for(int i=a;i<b;i++)
//#define sort(all(v)) sort(v.begin(),v.end())
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define ln "\n"
#define mod 1000000007
using namespace std;
//int dis[100005]
//vector<int> ans;
//int n,m;
//vector<int> dis(n+1,100005);
int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 

int s[200002];
vector<int> v[200002];
void dfs(int c,int p){
  s[c]=1;
  for(auto i:v[c]){
    if(i!=p){
      dfs(i,c);
      s[c]+=s[i];
    }
  }
}
void solve(){
  int n,x;
  cin>>n;
  memset(s,0,sizeof(s));
//  memset(vis,false,size0f(vis));
 //vector<int> v[n+1];
 for(int i=2;i<=n;i++){
  cin>>x;
  v[i].pb(x);
  v[x].pb(i);
 }
 dfs(1,0);
 for(int i=1;i<=n;i++)
  cout<<s[i]-1<<" ";
cout<<endl;
  
  }
int main(){
#ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("output.txt", "w", stdout); 
#endif 
   int t=1;
  // cin>>t;
   while(t--){
    solve();
}
}
