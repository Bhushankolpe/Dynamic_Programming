//https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden. All houses along this street are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
//You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.
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


int maximumNonAdjacentSum(vector<ll> &nums){
    // Write your code here.
    ll n=nums.size();
    vector<ll>dp(n+1);
       ll prev2=0;
       ll prev1=nums[0];
    for(int i=2;i<=n;i++)
    {
        ll temp=prev1;
      prev1=max(prev1,prev2+nums[i-1]);
        prev2=temp;
    
    }
    return prev1;
}

//ll max(ll a ,ll b)
//{
// if(a>b)
//     return a;
//    return b;
//}
ll houseRobber(vector<ll>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(n==1)
        return valueInHouse[0];
    vector<ll>v1,v2;
    
    for(int i=0;i<n;i++)
    {
    if(i!=0)
        v1.push_back(valueInHouse[i]);
     if(i!=n-1)
         v2.push_back(valueInHouse[i]);
         
    }
    ll k=maximumNonAdjacentSum(v1);
     ll k1=maximumNonAdjacentSum(v2);
    return max(k1,k);
}
int main()
{
	BHUSHAN;
	ll T;
	cin>>T;
	while(T--)
	{
	   ll n;
	   cin>>n;
	   vi v;
	   inputv(v,n);
	   cout<<houseRobber(v)<<endl;
	}
	return 0;
}
