#include<iostream> 
#include<vector>
using namespace std; 


class PriorityQueue // MAX HEAP
{
    vector<int> Priority_queue;

    int leftChild(int i)
    {
        return 2*i+1;
    }

    int rightChild(int i)
    {
        return 2*i+2;
    }

    int parent(int i)
    {
        return (i-1)/2;
    }

    void heapify(int i,int N)
    {
        // O(logN)
        int greatest=i;
        int left_child=leftChild(i);
        int right_child=rightChild(i);
        if(left_child<N && Priority_queue[left_child] > Priority_queue[greatest])
        {
            greatest=left_child;
        }

        if(right_child<N && Priority_queue[right_child] > Priority_queue[greatest])
        {
            greatest=right_child;
        }

        if(greatest!=i)
        {
            swap(Priority_queue[i],Priority_queue[greatest]);
            heapify(greatest,N);
        }
    }
    

    public:
    PriorityQueue()
    {

    }

    void push(int x)
    { 
        // O(logN)
        // PUSH ELEMENT INSIDE HEAP
        Priority_queue.push_back(x);
        int idx=(int)Priority_queue.size()  - 1;
        while(idx>0 && Priority_queue[parent(idx)] < Priority_queue[idx])
        {
            swap(Priority_queue[parent(idx)],Priority_queue[idx]);
            idx=parent(idx);
        }
    }


    void pop()
    {
        // O(logN)
        // REMOVE TOPMOST ELEMENT
        int root_idx=0;
        int last_idx=(int)Priority_queue.size()-1;
        swap(Priority_queue[0],Priority_queue[last_idx]); // STEP1

        Priority_queue.pop_back(); // STEP2

        heapify(0,(int)Priority_queue.size());
    }

    int top()
    {
        // O(1)

        //GET ELEMENT OF MAX PRIORITY
        if(Priority_queue.empty())
        {
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }

        return Priority_queue[0];
    }
};

int main()
{
    PriorityQueue pq;
    pq.push(10);
    pq.push(11);
    pq.push(2);
    cout<<pq.top()<<endl;

    pq.push(5);
    pq.pop();
    cout<<pq.top()<<endl;

    return 0;
}