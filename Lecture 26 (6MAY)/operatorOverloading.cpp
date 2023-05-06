#include<iostream> 
using namespace std; 

class complexNo
{
    public:
    int real,img;

    complexNo()
    {

    }

    complexNo(int REAL,int IMG)
    {
        real=REAL;
        img=IMG;
    }

    void print()
    {
        cout<<real<<" + "<<img<<"i"<<endl;
    }   
};



int &MAX(int &A,int &B)
{
    if(A>B) return A;
    else return B;
}


ostream& operator<<(ostream& o,complexNo& c)
{
    cout<<c.real<<" + "<<c.img<<"i"<<endl;
    return o;
}

complexNo operator+(complexNo& c1,complexNo &c2)
{
    complexNo res;
    res.real=(c1.real + c2.real);
    res.img=(c1.img + c2.img);
    return res;
}

int main()
{

    // int x=14,y=3;
    // int &z=MAX(x,y);

    // cout<<z<<endl;
    // z--;
    // cout<<x<<endl;










    complexNo C1(3,4);
    // C1.print();


    complexNo C2(10,12);
    // C2.print();

    // complexNo C3=C1 + C2;
    // C3.print();

    // cout<<"Hello World\n";
    // operator<<(cout,"Hello World\n");

    cout<<C1;
    operator<<(cout,C1);

    cout<<"hello world"<<"hello again"<<endl;

    cout<<C1<<C2;

    complexNo C3=C1 + C2;

    cout<<C3;

    return 0;
}