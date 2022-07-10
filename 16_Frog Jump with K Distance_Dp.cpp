
//https://atcoder.jp/contests/dp/tasks/dp_b
//There are N stones, numbered 1,2,…,N. For each i (1=i=N), the height of Stone i is h 
//i
//?
// .
//
//There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:
//
//If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. Here, a cost of |h 
//i
//?
// -h 
//j
//?
// | is incurred, where j is the stone to land on.
//Find the minimum possible total cost incurred before the frog reaches Stone N.
#include<iostream>
#include<vector>
#include<climits>
#include<map>
#include<unordered_map>
#include<set>
#include<stack>
#include<queue>
#include<cmath>
#include<math.h>
#include<string>
#include<iterator>
#include<algorithm>
#include<ctype.h>
#define BHUSHAN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define vi vector<ll>
#define vip vector<pair<ll,ll>>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

using namespace std;
ll factorial(ll n)
{return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);}
ll max(ll a,ll b)
{
	if(a>b)
	return a;
	return b;
}
void inputv(vector<ll>&v,ll n)
{
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		v.push_back(x);
	}
	return;
}
void coutv(vector<ll>v)
{
	for(ll i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	cout<<endl;
	return;
}
bool isPowerOfTwo(ll n)
{if(n==0)
   return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
bool isPrime(ll n)
{if (n <= 1)
    return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int gcd(int a, int b)
{if (a == 0)return b;return gcd(b % a, a);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll mex(vector<ll>v)
{
	ll ans=-1;
	unordered_map<ll,ll>mp;
	for(ll i=0;i<v.size();i++)
	mp[v[i]]++;
	for(ll i=0;i<=v.size();i++)
	{
		if(mp[i]==0)
		return i;
	}

}
 bool isSorted(vector<ll>v)
{    
      ll n=v.size();
    vector<ll>s;
    s=v;
    sort(s.begin(),s.end());
    for(ll i=0;i<n;i++)
    {
        if(s[i]!=v[i])
        {
            return false;
        }
    }
    return true;
}
//***************************************START YOUR CODE FROM HERE******************************************//
// ll arr[1001];



int main()
{
	BHUSHAN;
	ll T=1;
//	cin>>T;
	while(T--)
	{
	   ll n,k;
	   cin>>n>>k;
	   vector<ll>v;
	   inputv(v,n);
	   vector<ll>dp(n);
	   dp[0]=0;
	   for(ll i=1;i<n;i++)
	   {
	   	ll st=INT_MAX;
	   	for(ll j=1;j<=k;j++)
	   	{
	   		if(i-j<0)
	   		break;
	   		st=min(st,dp[i-j]+abs(v[i]-v[i-j]));
	   		
		   }
		   dp[i]=st;
	   	
	   }
	   cout<<dp[n-1]<<endl;
	}
	return 0;
}
