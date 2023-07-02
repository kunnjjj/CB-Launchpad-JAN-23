// https://leetcode.com/problems/find-median-from-data-stream/
#include<iostream>
#include<queue>
#include <iomanip>
using namespace std;


class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int,vector<int>,greater<int>> rightMinHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.empty() or num < leftMaxHeap.top())
        {
            leftMaxHeap.push(num);
        }
        else
        {
            rightMinHeap.push(num);
        }

        if(leftMaxHeap.size() > 1+rightMinHeap.size())
        {
            int x=leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(x);
        }
        else if(leftMaxHeap.size() + 1 < rightMinHeap.size())
        {
            int x=rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxHeap.push(x);
        }
    }
    
    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size())
        {
            return ((double)leftMaxHeap.top() + rightMinHeap.top())/2;
        }
        else if(leftMaxHeap.size() > rightMinHeap.size())
        {
            return leftMaxHeap.top();
        }
        else
        {   
            return rightMinHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



int main()
{
    MedianFinder obj;
    int q; cin>>q;
    for(int i=0;i<q;i++)
    {
        int type; cin>>type;
        if(type==1)
        {
            int x; cin>>x;
            obj.addNum(x);
        }
        else
        {
            cout<<fixed;
            cout<<setprecision(3);

            cout<<setprecision(3)<<obj.findMedian()<<endl;
        }
    }

    return 0;

}