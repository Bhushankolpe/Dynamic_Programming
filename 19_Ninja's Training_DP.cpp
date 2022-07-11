//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
//You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
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

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(max(points[0][0],points[0][1]),points[0][2] );
    
    for(int day=1;day<n;day++)
    {
      vector<int>temp(4,0);
        for(int last=0;last<4;last++)
        {
            temp[last]=0;
           for(int task=0;task<3;task++)
           {
               if(task!=last)
          temp[last]=max(temp[last],prev[task]+points[day][task]);
             
           }
            
      
        }
        prev=temp;
    
    }
    return prev[3];
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
	   vector<vector<int>>points;
	   for(ll i=0;i<n;i++)
	   {
	   	for(ll i=0;i<3;i++)
	   	{
	   		ll x;
	   		cin>>x;
	   		points[i].push_back(x);
		   }
	   }
	   cout<<ninjaTraining( n,points)<<endl;
	   
	}
	return 0;
}
