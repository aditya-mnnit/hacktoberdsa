#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll factorial(ll n)
{
    ll s=1;
    for(ll i=2;i<=n;i++)
    {
        s*=i;
    }
    return s;
}
int main()
{
    ll n;
    cin>>n;
    cout<<factorial(n)<<"\n";
}