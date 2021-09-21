#include<iostream>
#include<conio.h>
class demo
{
int r;
char name[50],branch[30];
public:
void input()
{
cout<<”Enter Name”<<endl;
cin>>name;
cout<<”Enter Branch”<<endl;
cin>>branch;
cout<<”Enter Roll No.”<<endl;
cin>>r;
}
void display();
};
void demo::void display();
{
cout<<”NAME :- “<<endl;
cout<<”BRANCH :- “<<endl;
cout<<”ROLL NO :- “<<endl;
}
void main()
{
demo d1,d2;
d1.input();
d2.display();
getch();
}
