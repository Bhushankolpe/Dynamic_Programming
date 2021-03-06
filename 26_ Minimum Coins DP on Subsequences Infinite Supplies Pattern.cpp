

// Link:
// 	https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0
//Que:
//	You are given an array of ?N? distinct integers and an integer ?X? representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ?X?.



#include<iostream>
#include<vector>
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

int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int i=0;i<x+1;i++)
    {
       if(i%nums[0]==0) dp[0][i]=i/nums[0];
        else
            dp[0][i]=1e9;
        
           
    }
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<=x;j++)
      {
          int ntk=0+dp[i-1][j];
          int tk=INT_MAX;
          if(nums[i]<=j)
          {
           tk=1+dp[i][j-nums[i]];
          }
          dp[i][j]=min(ntk,tk);
      
      }
    }
    int ans= dp[n-1][x];
    if(ans>=1e9) return -1;
    return ans;
}

int main()
{
	BHUSHAN;
	ll T;
	cin>>T;
	while(T--)
	{
	   
	}
	return 0;
}
