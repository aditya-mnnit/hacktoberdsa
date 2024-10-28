#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
typedef long long int ll;
using namespace std;
vector<vector<int>>adj;
vector<int>vis;
vector<int>depth;
vector<int>height;
vector<int>par,ch;
vector<ll>factdp;
set<ll>s;
ll ct=0;
ll cyc=0;
ll mod=1e9+7;
vector<bool>prime;
ll chil=0;
void seive(int n)
{
    prime.assign(n+1,true);
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            //cout<<i<<" ";//here i is prime
            for(int j=i*i;j<=n;j+=i)
            prime[j]=false;
        }
    }

}
ll binpow(ll a,ll b)
{
    a%=mod;
    ll res=1;
    while(b>0)
    {
        if(b&1)
        res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
ll inversemod(ll n)
{
return binpow(n,mod-2);
}
ll factorial(ll n)
{
    if(factdp.size()==0)
    factdp.push_back(1);
    for(int i=factdp.size();i<=n;i++)
    {
        factdp.push_back((factdp[i-1]*i)%mod);
    }
    return factdp[n];
}
void prmefactors(int n)
{
    s.insert(1);
    while(n%2==0)
    {
s.insert(2);
n/=2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0)
        {
            s.insert(i);
            n/=i;
        }
    }
if(n>2)
s.insert(n);
}
void printdivisors(int n)
{
    for(int i=0;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
            s.insert(i);
            else{
                s.insert(i);
                s.insert(n/i);
            }
        }
    }
}
ll ncr(ll n, ll r)
{
    return ((factorial(n)%mod)*(inversemod(factorial(n-r)%mod)%mod)*(inversemod(factorial(r)%mod)%mod));
}
void dfs(int node,int parent)
{

    vis[node]=1;
    depth[node]=depth[parent]+1;
    ct++;
par[node]=parent;
    for(auto i:adj[node])
    {
        if(vis[i]!=1)
        {
            dfs(i,node);
             chil=1;
    ch[node]+=(ch[i]+1);
        }
    }
    if(chil==0)
    ch[node]=chil;
    chil=0;
}

vector<int> path(int n)
{
    vector<int>ans;
    while(n!=0)
    {
        ans.push_back(n);
        n=par[n];

    }
    return ans;
}
vector<int>cp;


int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
  
    
  string s;
  cin>>s;
  int n=s.size();
  vector<pair<int,vector<char>>>v(n);
  for(int i=0;i<n;i++)
  {
    vector<char>w;
for(int j=0;j<i;j++)
{
    if(s[j]<s[i])
    {
        if(v[j].second.size()>w.size())
        {
            w=v[j].second;
        }
    }
}
w.push_back(s[i]);
v[i].first=w.size();
v[i].second=w;
  }
  int mx=INT_MIN;
  int id;
  for(int i=0;i<n;i++)
  {
    if(v[i].first>mx)
    {
        mx=v[i].first;
        id=i;
    }
  }
  for(int i=0;i<v[id].second.size();i++)
  cout<<v[id].second[i]<<" ";
    

   
}