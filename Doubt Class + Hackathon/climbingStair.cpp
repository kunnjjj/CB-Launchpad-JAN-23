#include<iostream>
using namespace std;

int waysParisha(int cur_stair,int N)
{
    // number of ways that she can reach from cur_stair to Nth Stair
    if(cur_stair==N)
    {
        return 1;
    }
    
    if(cur_stair > N)
    {
        return 0;
    }


    // she  can jump from cur_stair->cur_stair+1, or cur_stair+2

    return waysParisha(cur_stair+1,N) + waysParisha(cur_stair+2,N);

}

int waysPrabhnoor(int N)
{
    // this func gives me total ways to reach from Nth Stair to 1st stair
    if(N==1)
    {
        return 1;
    }
    if(N<=0)
    {
        return 0;
    }
    // prabh can jump from N to N-1, to N to N-2

    return waysPrabhnoor(N-1) + waysPrabhnoor(N-2);
}

int main()
{

    cout<<waysParisha(1,5)<<endl;

    cout<<waysPrabhnoor(5)<<endl;


    return 0;
}