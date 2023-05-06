#include<iostream> 
using namespace std; 

class node
{
    public:
    int d;
    int x;
    node(int D)
    {
        d=D;
        x=90;
    }

    void print()
    {
        cout<<"value of d: "<<d<<endl;
    }
};

int main()
{

    int x=34;
    int *y=&x;

    cout<<x<<endl;
    cout<<(*y)<<endl;

    node obj(10);
    obj.print();

    node* ptr=&obj;

    (*ptr).print();

    ptr->print();

    cout<<obj.d<<endl;
    // cout<<obj->d<<endl;

    cout<<(*ptr).d<<endl;
    cout<<ptr->d<<endl;

    ptr->x+=23;
    cout<<(ptr->x)<<endl;



    return 0;
}