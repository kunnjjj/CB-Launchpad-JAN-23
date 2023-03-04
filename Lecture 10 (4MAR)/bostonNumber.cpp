#include<iostream>
using namespace std;

int sumOfDigits(int N)
{
	int sum=0;
	while(N>0)
	{
		sum+=N%10;
		N/=10;
	}
	return sum;
}
int sumOfDigitsOfPrimeFactors(int N)
{
	int sum=0;
	for(int i=2;i*i<=N;i++)
	{
		if(N%i==0)
		{
			while(N%i==0)
			{
				// i is a prime number which divides N/
				// sum of digit of i
				sum+=sumOfDigits(i);
				N/=i;
			}
		}
	}
	if(N>1)
	{
		sum+=sumOfDigits(N);
	}
	return sum;
}
int main() {
	int N; cin>>N;
	if(sumOfDigits(N)==sumOfDigitsOfPrimeFactors(N))
	{
		cout<<1;
	}
	else cout<<0;
	return 0;
}
