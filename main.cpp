#include <iostream>
using namespace std;
class ArrayList
{
private:
    char *p;
    int MaxSize;
    int CurrentSize;
    int Cursor;
    bool CursorMove;
public:
    ArrayList()
    {
        cout<<"Enter Max Size : ";
        cin>>MaxSize;
        CurrentSize=0;
        Cursor=0;
        CursorMove= false;

    }

    void init();
    void InitMemory();
    void Dashboard();
    void Insert();
    void Remove();
    void Replacement();
    void DisplayCharacter();
    void MoveForward();
    void MovePrevious();
    void MoveStart();
    void MoveEnd();
    void Empty();
    void occupied();
    void Clear();
    void display();

};
void ArrayList::init()
{
    for(int i=0;i<MaxSize;i++)
    {
        p=new char[MaxSize];
    }
}
void ArrayList::InitMemory()
{
    for(int i=0;i<MaxSize;i++)
    {
        p[i]='*';
    }
}
void ArrayList::Dashboard()
{
    cout<<"+	Insert a character"<<endl;
    cout<<"-	Remove character at the cursor"<<endl;
    cout<<"=	Replace character at the cursor"<<endl;
    cout<<"@	Display character at the cursor"<<endl;
    cout<<"F	Move cursor forward"<<endl;
    cout<<"P	Move cursor to previous character"<<endl;
    cout<<"<	Move to beginning of the list"<<endl;
    cout<<">	Move to end of the list"<<endl;
    cout<<"E	Report if the list is empty"<<endl;
    cout<<"O	Report whether the list is occupied"<<endl;
    cout<<"C	Clear the list"<<endl;
    cout<<"Q 	Quit the test program"<<endl;
}
void ArrayList::Insert()
{

    char CH;
    cout << "Enter Character : " << endl;
    cin >> CH;
    if (CurrentSize == MaxSize)
    {

        cout << "Array if Full you cannot enter Character " << endl;

    }
    else if (CurrentSize != MaxSize) {

        if (CursorMove == false) {
            if (p[Cursor] == '*') {

                p[Cursor] = CH;
                CurrentSize++;
                cout<<CurrentSize<<endl;
                Cursor++;
                cout<<Cursor<<endl;

            }
            else if(p[Cursor]!='*')
            {
                cout<<"The Cuurent Course Contain Character If you want to makes Changes Select Replace or Remove Option"<<endl;
            }

        }

        if (CursorMove == true) {

            for (int i = CurrentSize; i > Cursor; i--) {

                p[i] = p[i - 1];
            }
            p[Cursor] = CH;
            CurrentSize++;
            cout<<CurrentSize<<endl;
            Cursor++;
            cout<<Cursor<<endl;

        }

    }



}

void ArrayList::Remove()
{
    CurrentSize--;
    Cursor--;
    for(int i = Cursor; i <= CurrentSize; i++){

        p[i] = p[i + 1];

    }

}
void ArrayList::Replacement()
{

    char option;
    cout<<"Enter new character: "<<endl;
    cin>>option;
    p[Cursor - 1] = option;
}

void ArrayList::DisplayCharacter()
{
    cout<<"Your Last Enter Character is : "<<p[Cursor-1]<<endl;
}

void ArrayList::MoveForward()
{
    if(p[Cursor]!='*')
    {
        Cursor++;
    }
    else if(p[Cursor]=='*')
    {
        cout<<"We cannot move Cursor forward first fill the current Memory location "<<endl;
    }
}
void ArrayList::MovePrevious()
{
    Cursor--;
}
void ArrayList::MoveStart()
{
    CursorMove=true;
    Cursor=0;
}
void ArrayList::MoveEnd()
{
    Cursor=CurrentSize;
    CursorMove=false;
}
void ArrayList::Empty()
{
    if(CurrentSize==0)
    {
        cout<<"Your List is Empty "<<endl;
    }
    else
    {
        cout<<"Your List is not Empty "<<endl;
    }
}

void ArrayList::occupied()
{
    if(CurrentSize==MaxSize)
    {
        cout<<"Your List is completely occupied "<<endl;
    }
    else
    {
        cout<<"Your List is not completely occupied "<<endl;
    }
}
void ArrayList::Clear()
{

    for(int i=0;i<MaxSize;i++)

    {

        p[i]='*';

    }
    CurrentSize=0;
    Cursor=0;
}

void ArrayList::display() {

    for (int i = 0; i < CurrentSize; i++)

    {

        cout << p[i] << " ";

    }

    cout<<endl;

}


int main()
{
    char C;
    ArrayList A;
    A.init();
    A.InitMemory();
    A.Dashboard();
    cout<<"Enter Your Choice :"<<endl;
    cin>>C;
    while(C!='Q')
    {
        if(C=='+')
        {
            A.Insert();
            cout<<"Current List"<<endl;
            A.display();
        }
        if(C=='-')
        {
            A.Remove();
            cout<<"Current List"<<endl;
            A.display();
        }
        if(C=='=')
        {
            A.Replacement();
            cout<<"Current List"<<endl;
            A.display();
        }
        if(C=='@')
        {
            A.DisplayCharacter();
            cout<<endl;
        }
        if(C=='F')
        {
            A.MoveForward();
            cout<<"CHECK"<<endl;
        }
        if(C=='P')
        {
            A.MovePrevious();
            cout<<"CHECK"<<endl;
        }
        if(C=='<')
        {
            A.MoveStart();
        }
        if(C=='>')
        {
            A.MoveEnd();
        }
        if(C=='E')
        {
            A.Empty();
        }
        if(C=='O')
        {
            A.occupied();
        }
        if(C=='C')
        {
            A.Clear();
        }

        A.Dashboard();
        cout<<"Enter Your Choice :"<<endl;
        cin>>C;

    }
    A.display();
    return 0;
}