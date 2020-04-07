#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

long int pow(long int a, long b, long mod) {
	long int ret = 1, pow = a;
	while(b) {
		if(b & 1) ret = (ret*pow)%mod;
		pow = (pow*pow)%mod;
		b >>= 1;
	}
	return ret;	
}

int isprime(int n) {
	if(n==1) return 0;
	for(int i=2; i<sqrt(n); i++)
		if(n%i == 0)
			return 0;
	return 1;
}


void printf_prime(int n) {
	int m = sqrt(n);
	int vis[n];	
	memset(vis, 0 ,sizeof(vis));
	for(int i=1; i<=m; i++) {
		if(isprime(i)) {
			for(int j=i; j<n; j+=i)	
				vis[j] = 1;
		}
	}
	for(int i=1; i<n; i++)
		if(!vis[i])
			cout << i << endl;
}

int main() {
	printf_prime(120);
}
