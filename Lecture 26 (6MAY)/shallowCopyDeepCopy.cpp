#include<iostream> 
using namespace std; 

class XYZ
{
    int x;
    int *y;
    public:
    XYZ(int X)
    {
        x=X;
        y=&x;
    }

    XYZ(XYZ &obj) // deep copy
    {
        x=obj.x;
        
        y=&x;
    }

    void print()
    {
        cout<<"value of x: "<<x<<endl;
    }

    void increaseX()
    {
        (*y)=(*y)+5;
    }

};

int main()
{
    XYZ obj1(10);
    obj1.print();
    obj1.increaseX();
    obj1.print();


    XYZ obj2=obj1;

    obj2.print();

    obj2.increaseX();
    obj2.print();

    obj1.print();




    return 0;
}