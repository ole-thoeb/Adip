#include <stdio.h>

unsigned long long fakultaet(int n){
	unsigned long long p = 1;
	for(int i = 1; i <= n; i++){
		p *= i;
	}
	return p;
}

unsigned long long binomialkoeffizient(int n, int k){
	if(n < k) return 0;
	printf("%llu\n", fakultaet(n));
	printf("%llu\n", fakultaet(k));
	printf("%llu\n", fakultaet(n - k));
	return fakultaet(n) / (fakultaet(k) * fakultaet(n - k));
}

long long lotto(int n, int k){
	return binomialkoeffizient(n, k) * fakultaet(k);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
