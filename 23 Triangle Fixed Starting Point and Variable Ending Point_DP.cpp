//Link:
//	https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//que:
//	You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.
//The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
//You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.

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

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>>dp(n,vector<int>(n));
    for(int i=0;i<n;i++)
        dp[n-1][i]=triangle[n-1][i];
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
             int a=triangle[i][j]+dp[i+1][j];
            int b=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(a,b);
        
        }
    
    }
    return dp[0][0];
}

int main()
{
	BHUSHAN;
	ll T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
	   vector<vector<int>>triangle;
	   for(ll i=0;i<n;i++)
	   {
	   	for(ll j=0;j<i+1;j++)
	   	{
	   		ll x;
	   		cin>>x;
	   		triangle[i].push_back(x);
		   }
	   }
	   cout<< minimumPathSum(triangle, n)<<endl;
	}
	return 0;
}
