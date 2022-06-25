#include<iostream>
#include<vector>
#include<cstring>
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

ll t[1000][1000];
ll knapsack(vector<ll>wt, vector<ll>val,ll W,ll n)
{
	  for(ll i=0;i<n+1;i++)
	  t[i][0]=0;
	  for(ll i=0;i<W+1;i++)
	  t[0][i]=0;
	  for(ll i=1;i<n+1;i++)
	  {
	  	for(ll j=1;j<W+1;j++)
	  	{
	  		if(wt[i-1]<=j)
	  		{
	  			t[i][j]=max(t[i-1][j-wt[i-1]]+val[i-1],t[i-1][j]);
			  }
			  else
			  t[i][j]=t[i-1][j];
		  }
	  }
	  return t[n][W];
}

int main()
{
	BHUSHAN;
	ll T;
	 T=1;
	while(T--)
	{
		memset(t,-1,sizeof(t));
	   vi wt;
	   vi val;
	   ll n;
	   ll W;
	   cout<<"Enter the number of items in knapsack "<<endl;
	   cin>>n;
	   cout<<"Enter the weight of the items "<<endl;
	   inputv(wt,n);
	   cout<<"Enter the values of items "<<endl;
	   inputv(val,n);
	   cout<<"Enter the capacity of knapsack "<<endl;
	   cin>>W;
	   cout<<"Maximum profit of knapsack is : "<<knapsack(wt,val,W,n)<<endl;
	   
	}
	return 0;
}
