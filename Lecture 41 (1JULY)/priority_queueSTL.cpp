#include <iostream>
#include <queue>
using namespace std;

int main()
{

    // priority_queue<dataType> maxHeap;
    // priority_queue<dataType,vector<dataType>,greater<dataType>> minHeap;

    priority_queue<string,vector<string>,greater<string>> stringMinHeap;
    stringMinHeap.push("ayush");
    stringMinHeap.push("aryaman");
    cout<<stringMinHeap.top()<<endl;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(10);
    maxHeap.push(12);
    maxHeap.push(9);

    cout<<maxHeap.top()<<endl;

    maxHeap.pop();
    cout<<maxHeap.top()<<endl;

    minHeap.push(10);
    minHeap.push(12);
    minHeap.push(9);

    cout<<minHeap.top()<<endl;

    minHeap.pop();
    cout<<minHeap.top()<<endl;





    return 0;
}