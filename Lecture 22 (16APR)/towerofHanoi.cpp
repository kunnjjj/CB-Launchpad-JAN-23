#include<iostream>
using namespace std;

void towerOfHanoi(char src,char dest,char aux,int n)
{
	if(n==0)
	{
		return ;
	}
	// SOLVE TOH PROBLEM FOR N BLOCKS, WHERE SRC, DEST, AUX are given in arguments
	char newSrc=src,newDest=aux,newAux=dest;
	towerOfHanoi(newSrc,newDest,newAux,n-1);
	cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dest<<endl;
	newSrc=aux,newDest=dest,newAux=src;
	towerOfHanoi(newSrc,newDest,newAux,n-1);
}

int main() {

	int n; cin>>n;
	towerOfHanoi('A','B','C',n);

	return 0;
}