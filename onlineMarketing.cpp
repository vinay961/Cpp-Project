#include<iostream>
#include<fstream>

using namespace std;

class shopping{
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
            void rem();
            void list();
            void receipt();
};

void shopping:: menu()
{
    m:
    int choice;
    string email;
    string password;


    cout<<"\t\t\t\t______________________________\n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t    SUPPERMARKET MAIN MENU    \n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t______________________________\n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t 1.ADMINISTRATOR \n";
    cout<<"\t\t\t\t                 \n";
    cout<<"\t\t\t\t 2.BUYER \n";
    cout<<"\t\t\t\t                 \n";
    cout<<"\t\t\t\t 3.EXIT \n";
    cout<<"\t\t\t\t                 \n";
    cout<<"\t\t\t\t Please select what you want\n";
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please login \n";
            cout<<"\t\t\t Enter Email:";
            cin>>email;
            cout<<"\n";
            cout<<"\t\t\t Password:";
            cin>>password;
            cout<<"\n";

            if(email=="vinay100rai@gmail.com" && password=="vinayrai1")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid mail or password";
            }
            break;
        case 2:
            {
                buyer();
            }
        case 3:
            {
                exit(0);
            }
            default :
              {
                cout<<"Please select from given option";
              }    
    }
goto m;
}

void shopping ::administrator()
{
    m:
    int choice;
    cout<<"\n\n\t\t\t  Administrator menu";
    cout<<"\n\t\t\t______1.Add the product_____";
    cout<<"\n\t\t\t                            ";
    cout<<"\n\t\t\t______2.Modify the product__";
    cout<<"\n\t\t\t                            ";
    cout<<"\n\t\t\t______3.Delete the product__";
    cout<<"\n\t\t\t                            ";
    cout<<"\n\t\t\t______4.Back to main menu___";
    
    cout<<"\n\n\t Please Enter your choice:";
    cin>>choice;

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default :
            cout<<"Invalid choice!";    
    }
    goto m;
}

void shopping:: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t    Buyer menu   \n";
    cout<<"\t\t\t                 \n";
    cout<<"\t\t\t__1.Buy Product__\n";
    cout<<"\t\t\t                 \n";
    cout<<"\t\t\t__2.Go Back______\n";

    cout<<"\t\t\t Enter your choice:";
    cin>>choice;

    switch(choice){
        case 1:
           receipt();
           break;
        case 2:
           menu();
        default :
           cout<<"Invalid choice";      
    }
    goto m;
}

void shopping::add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p,d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product:";
    cin>>pcode;
    cout<<"\n\n\t Name of the product:";
    cin>>pname;
    cout<<"\n\n\t Price the product:";
    cin>>price;
    cout<<"\n\n\t Discout on the product:";
    cin>>dis;
    data.open("database.txt",ios::in);
    if(!data){
        data.open("database.txt",ios::app|ios::out); 
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    if(token==1)
      goto m;
    else{
        data.open("database.txt",ios::app|ios::out); 
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }

}
cout<<"\n\n\n\t Record Inserted !";
}

void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p,d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code:";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile does'not exist!";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode){
                cout<<"\n\t\t Product new code:";
                cin>>c;
                cout<<"\n\t\t Name of product:";
                cin>>n;
                cout<<"\n\t\t Price:";
                cin>>p;
                cout<<"\n\t\t Discount:";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited";
                token++;         
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found";
        }
    }
}

void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn'not exist";
    }
    else{
        data.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"product deleted succesfully";
                token++;
            }
            else{
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}

void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n_______________________________\n";
    cout<<"productNo\t\tName\t\tPrice";
    cout<<"\n\n_______________________________\n";
    data>>pcode>>pname>>price>>dis;
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
    int choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else{
        data.close();

        list();
        cout<<"\n________________________________\n";
        cout<<"\n|                               \n";
        cout<<"\n    Please place the order      \n";
        cout<<"\n|                               \n";
        cout<<"\n________________________________\n";
        do
        {
            m:
            cout<<"\n\nEnter the product code:";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i]){
                    cout<<"\n\nDuplicate product code.Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\nDo you want to buy another product? if yes then press 1 else for no 2:";
            cin>>choice;
        }
        while(choice==1);

        cout<<"\n\t\t\t____________RECEIPT_____________\n";
        cout<<"\nProduct No\t Product name\t product quantity\t price\t Amount with discount\n";

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrq[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n_______________________________________";
    cout<<"\n Total Amount:"<<total;
}


int main()
{
    shopping s;
    s.menu();
    return 0;
}