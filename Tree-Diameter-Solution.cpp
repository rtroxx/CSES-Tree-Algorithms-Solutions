/*
     If you can't think of solution think some well known algorithm related to it!
     Always BE COOL!
     Last minute hustle might give you AC
            -----RATNESH KUMAR TIWARY
*/
/*
  Method 1:solve using two BFS:-
             Algo:-
               1.start Bfs from any arbitary node reach to the farthest nodefrom it,
               2.again start bfs from that last node visited in step-1;
               3.that will be the max dia of given tree.
 
  Method 2:Solve using DP:-
             Algo:-
               1.consider two states going through a particular node on or not going through
                 it.
               2.Moreover follow the solution coded below.
*/
 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define re(i,a,b) for(int i=a;i<b;i++)
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
int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
void prtn(ll i){
cout<<i<<ln;}

int DownPath[200002];//DownPath[i] represent max depth of all possible  children rooted at i,

int Diam[200002];//Diam[i] represent Diameter of tree passing through node i;

vector<int> v[200002];
void eval_DownPath(int src,int p){
  int BestChild=0;
  bool leaf=1;
  for(auto i:v[src]){
    if(i!=p){
      leaf=0;
      eval_DownPath(i,src);
      BestChild=max(BestChild,DownPath[i]);
    }
  }
  if(leaf)DownPath[src]=0;
  else
    DownPath[src]=1+BestChild;
}
void solve1(int src,int p){
  int ans=0;
  vector<int> ChildDown;
  for(auto i:v[src]){
    if(i!=p){
      solve1(i,src);
      ChildDown.pb(DownPath[i]);
    ans=max(ans,Diam[i]);
  }
}
int NoC=ChildDown.size();
sort(ChildDown.begin(),ChildDown.end());
if(NoC==0)Diam[src]=0;
else if(NoC==1)Diam[src]=1+ChildDown[0];
else{
  Diam[src]=2+ChildDown[NoC-1]+ChildDown[NoC-2];// {x->ChildDown[NoC-1],dis=1}->{y->ChildDown[NoC-2],dis=1}
}
Diam[src]=max(Diam[src],ans);
}
void solve(){
  int n,x,y;
  cin>>n;
 for(int i=1;i<=n-1;i++){
  cin>>x>>y;
  v[y].pb(x);
  v[x].pb(y);
 }
 eval_DownPath(1,0);
 solve1(1,0);
 cout<<Diam[1]<<endl;
  }
int main(){
#ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("output.txt", "w", stdout); 
#endif 
   int t=1;
   while(t--){
    solve();
}
}
