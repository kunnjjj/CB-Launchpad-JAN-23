#include<iostream> 
using namespace std; 



class Car
{   
    string color;
    int wheelSize;
    string modelNo;
    int len;
    int speed;
public:



    Car()
    {
        cout<<"contructor invoked"<<endl;
    }

    Car(int WHEELSIZE,string COLOR,int LEN,int SPEED,string MODELNO)
    {
        cout<<"parameterised contructor"<<endl;
        wheelSize=WHEELSIZE;
        color=COLOR;
        len=LEN;
        speed=SPEED;
        modelNo=MODELNO;
    }

    Car(Car &X)
    {
        cout<<"copy constructor invoked"<<endl;
        wheelSize=X.wheelSize;
        color=X.color;
        len=X.len;
        speed=X.speed;
        modelNo=X.modelNo;
    }

    ~Car()
    {
        cout<<"model: "<<modelNo<<endl;
        cout<<"destructor invoked"<<endl;
    }

    void accelerate()
    {
        speed=speed+5;
    }

    void changeColor(string newColor) // setter
    {
        color=newColor;
    }

    string getColor() //getter
    {
        return color;
    }

    void changeModel(string NEWMODEL)
    {
        modelNo=NEWMODEL;
    }

};

int main()
{

    Car BMW(18,"Black",4300,0,"S3");

    // ObjectKaNaam.propertyName;
    // ObjectKaNaam.funcName();
    cout<<BMW.getColor()<<endl;
    BMW.changeColor("MatteBlack");
    // BMW.color="Pink";
    // BMW.wheelSize=12;
    cout<<BMW.getColor()<<endl;
    // cout<<BMW.color<<endl;


    // Car Audi;
    
    Car Mercedes=BMW;
    // Car Mercedes(BMW);

    cout<<"Created Mercedes"<<endl;
    cout<<BMW.getColor()<<endl;
    cout<<Mercedes.getColor()<<endl;

    Mercedes.changeModel("M3");
    
    int x=10;
    // int y=x;
    int y(x);
    cout<<"y: "<<y<<endl;

    return 0;
}