#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void result();
    void List();
    void receipt();

};

void shopping:: menu()
{   m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t     Supermarket's Main Menu       \n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t|     1) Administrator     |\n";
    cout<<"\t\t\t\t|                          |\n";
    cout<<"\t\t\t\t|     2) Buyer             |\n";
    cout<<"\t\t\t\t|                          |\n";
    cout<<"\t\t\t\t|     3) Exit              |\n";
    cout<<"\t\t\t\t|                          |\n";
    cout<<"\n\t\t\t Please select:";
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Email  \n";
        cin>>email;
        cout<<"\t\t\t Password      \n";
        cin>>password;

        if(email=="admin@gmail.com" && password=="admin123")
        {
            administrator();
        }
        else
        {
            cout<<"Invalid ,Please try again!";
        }
        break;
    }

    case 2:
        {
            buyer();
        }
    case 3:
        {
            exit(0);
        }
    default:
        {
            cout<<"Please select from the given options";
        }

    }
goto m;

}
void shopping:: administrator()
{   x:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator's Menu";
    cout<<"\n\t\t\t|________1) Add the product_______|";
    cout<<"\n\t\t\t|                                 |";
    cout<<"\n\t\t\t|________2) Modify the product____|";
    cout<<"\n\t\t\t|                                 |";
    cout<<"\n\t\t\t|________3) Delete the product____|";
    cout<<"\n\t\t\t|                                 |";
    cout<<"\n\t\t\t|________4) Back to the Main menu_|";

    cout<<"\n\n\t Please Enter your choice!";
    cin>>choice;
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        result();
        break;

    case 4:
        menu();
        break;

    default:
        cout<<"Invalid Choice!";
    }
    goto x;
}

void shopping ::buyer()
{   m:
    int choice;
    cout<<"\t\t\t    Buyer        \n";
    cout<<"\t\t\t_________________\n";
    cout<<"                       \n";
    cout<<"\t\t\t 1) Buy Product  \n";
    cout<<"                       \n";
    cout<<"\t\t\t 2) Go back      \n";
    cout<<"\t\t\t Enter your choice: ";

    cin>>choice;

    switch(choice)
    {
         case 1:
             receipt();
             break;
         case 2:
            menu();

         default:
            cout<<"Invalid choice";

    }

    goto m;

}

void shopping:: add()
{   m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product      ";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product ";
    cin>>price;
    cout<<"\n\n\t Discount on product ";
    cin>>dis;

    data.open("database.txt",ios::in); //will open the file in reading mood
    if(! data){
        data.open("database.txt",ios::app|ios::out); //will open the file in writing mood
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n"; //writing in the file
        data.close();

    }
    else
    {
        data>>c>>n>>p>>d; //reading from the file
        while(!data.eof()){ //not end of the file
            if(c==pcode){
                token++;
            }
             data>>c>>n>>p>>d;
        }
        data.close();

    if(token ==1){
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app|ios::out); //will open the file in writing mood
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n"; //writing in the file
        data.close();


    }
    }


    cout<<"\n\n\t\t Record inserted !";

}
void shopping ::edit()
{
    fstream data,data1; //2 objects of stream class
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the Record";
    cout<<"\n\t\t\t Product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile does not exist!";
    }
    else
    {
        data.open("database.txt", ios::app|ios::out); //will open the file in writing mood
        cin>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product's new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        remove("database1.txt");
        remove("database.txt");

        if(token==0)
        {
            cout<<"\n\n Sorry! Record not found";
        }

    }
}
void shopping ::result()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File does not exist !";
    }
    else
    {
        data1.open("database.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted succesfullly";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database,txt");
        if(token==0){
            cout<<"\n\n Record not found !";
        }
    }
}

void shopping ::List()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_______________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice \n";
    cout<<"\n\n|_______________________________________\n";
    cout<<pcode<<pname<<price<<dis;

    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}
void shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice2;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database!";
    }
    else
    {
        data.close();

        List();
        cout<<"\n_________________________________\n";
        cout<<"\n|                                \n";
        cout<<"\n        Please place the order   \n";
        cout<<"\n|                                \n";
        cout<<"\n_________________________________\n";

        do
        {
            m:
            cout<<"\n\nEnter Product code:";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product , please try again !";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product ? if yes press y else press n";
            cin>>choice2;

        }
        while(choice2=='y');
        cout<<"\n\n\t\t\t_______________________RECEIPT ____________________\n";
        cout<<"\nProduct No\t Product Name\t quantity\t Price\tAmount\t Amount with discount \n";

        for(int i=0;i<c;i++)
        {
          data.open("database.txt",ios::in);
          data>>pcode>>pname>>price>>dis;
          while(!data.eof())
          {
              if(pcode==arrc[i])
              {
                  amount = price*arrq[i];
                  dis= amount-(amount*dis/100);
                  total=total+dis;
                  cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
              }
              data>>pcode>>pname>>price>>dis; //for iterating the file
          }
        }
        data.close();
    }
    cout<<"\n\n__________________________________";
    cout<<"\n Total Amount :"<<total;
}
int main()
{
    shopping s;
    s.menu();
}
