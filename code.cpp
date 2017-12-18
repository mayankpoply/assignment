#include<bits/stdc++.h>
#define m 1000000007
using namespace std;

void multiply(long long fib[2][2],long long mul[2][2]){
	long long a=((fib[0][0]*mul[0][0])%m+(fib[0][1]*mul[1][0])%m)%m;
	long long b=((fib[0][0]*mul[0][1])%m+(fib[0][1]*mul[1][1])%m)%m;
	long long c=((fib[1][0]*mul[0][0])%m+(fib[1][1]*mul[1][0])%m)%m;
	long long d=((fib[1][0]*mul[0][1])%m+(fib[1][1]*mul[1][1])%m)%m;
	fib[0][0]=a;
	fib[0][1]=b;
	fib[1][0]=c;
	fib[1][1]=d;
}
void power(long long fib[2][2],long long n){
	if(n==0||n==1)
	return;
	long long mul[2][2]={{1,1},{1,0}};
	power(fib,n/2);
	multiply(fib,fib);
	if(n%2!=0)
	multiply(fib,mul);
}
long long bitstring(long long n){
	long long fib[2][2] = {{1,1},{1,0}};
	if(n==0)
	return 0;
	power(fib,n-1);
	return fib[0][0]%m;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		if(n==0){
			cout<<"0"<<"\n";
			continue;
		}
		long long ans=bitstring(n+2);
		cout<<ans<<"\n";
	}
	return 0;
}
