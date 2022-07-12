
//Link:
//	https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0


//Que:
//	Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.
//Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.
//If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.
//Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

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

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
    vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);

          }
        }
        cur[j1][j2] = maxi;
      }
    }
    front = cur;
  }

  return front[0][m - 1];
}

int main()
{
	BHUSHAN;
	ll T;
	cin>>T;
	while(T--)
	{
	   int n,m;
	   cin>>n>>m;
	   vector<vector<int>>grid;
	   for(ll i=0;i<n;i++)
	   {
	   	for(ll j=0;j<m;j++)
	   	{
	   		ll x;
	   		cin>>x;
	   		grid[i].push_back(x);
		   }
	   }
	   cout<<maximumChocolates(n, m, grid)<<endl;
	}
	
	return 0;
}
