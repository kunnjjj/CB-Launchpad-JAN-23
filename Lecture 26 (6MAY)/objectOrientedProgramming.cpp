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

    Car(int WHEELSIZE,string COLOR,int LEN,int SPEED)
    {
        cout<<"parameterised contructor"<<endl;
        wheelSize=WHEELSIZE;
        color=COLOR;
        len=LEN;
        speed=SPEED;
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
};

int main()
{

    Car BMW(18,"Black",4300,0);

    cout<<BMW.getColor()<<endl;
    BMW.changeColor("MatteBlack");
    // BMW.color="Pink";
    // BMW.wheelSize=12;
    cout<<BMW.getColor()<<endl;
    // cout<<BMW.color<<endl;


    Car Audi;

    BMW.changeColor(Audi.getColor());



    return 0;
}