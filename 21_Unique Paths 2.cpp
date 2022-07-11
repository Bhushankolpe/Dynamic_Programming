//Link:
//	https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
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


int mod=1e9+7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    
     vector<vector<int>>dp(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<m;j++)
     {

         
         if(mat[i][j]==-1)
           dp[i][j]=0;
      else if(i==0 && j==0)
       {
          
               dp[i][j]=1;
       }
           else
           {
               int up=0;
               int down=0;
               if(i>0)
                  up= dp[i-1][j];
               if(j>0)
                   down=dp[i][j-1];
                   
                 dp[i][j]=(up+down)%mod;
           
           }
             
     }

    }
    return dp[n-1][m-1];
}
int main()
{
	BHUSHAN;
	ll T;
	cin>>T;
	while(T--)
	{
	   ll n,m;
	   cin>>n>>m;
	   vector<vector<int>>mat;
	   for(ll i=0;i<n;i++)
	   {
	   	for(ll i=0;i<m;i++)
	   	{
	   		ll x;
	   		cin>>x;
	   		mat[i].push_back(x);
		   }
	   }
	   cout<<mazeObstacles(n, m,mat)<<endl; 
	}
	return 0;
}
