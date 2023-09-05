#include<iostream>
using namespace std;

int main(){
    int quant;
    int choice;

    int Qrooms=0,Qpasta=0,Qburgar=0,Qnoodles=0,Qchicken=0;
    int Srooms=0,Spasta=0,Sburgar=0,Snoodles=0,Schicken=0;
    int Total_rooms=0,Total_pasta=0,Total_burgar=0,Total_noodles=0,Total_chicken=0;

    cout<<"Quantity of items we have:";

    cout<<"\n Rooms available:";
    cin>>Qrooms;

    cout<<"\n Quantity of pasta:";
    cin>>Qpasta;

    cout<<"\n Quantity of burgar:";
    cin>>Qburgar;

    cout<<"\n Quantity of noodles:";
    cin>>Qnoodles;

    cout<<"\n Quantity of chicken:";
    cin>>Qchicken;
    
    m:
    cout<<"\n\nPlease select what you want?";
    cout<<"\n 1.Rooms";
    cout<<"\n 2.pasta";
    cout<<"\n 3.Burgar";
    cout<<"\n 4.Noodles";
    cout<<"\n 5.Chicken-roll";
    cout<<"\n 6.Information regarding sale and collection";
    cout<<"\n 7.Not Intrested";

    cout<<"\n\nEnter Your choice!!";
    cin>>choice;

    switch(choice)
    {
        case 1:
              cout<<"\n\nEnter the number of rooms you want:";
              cin>>quant;
              if(Qrooms-Srooms>=quant)
              {
                Srooms=Srooms+quant;
                Total_rooms=Total_rooms+quant*2500;
                cout<<"\n\n\t"<<quant<<"-room/rooms have been allocated to you!";
                break;
              }
              else
              {
                cout<<"\n\tOnly"<<Qrooms-Srooms<<"Rooms remaining in hotel";
                break;
              }

        case 2:
              cout<<"\n\nEnter the quantity of pasta";
              cin>>quant;
              if(Qpasta-Spasta>=quant)
              {
                Spasta=Spasta+quant;
                Total_pasta=Total_pasta+quant*50;
                cout<<"\n\n\t"<<quant<<"-pasta is ordered!";
                break;
              }
              else
              {
                cout<<"\n\tOnly"<<Qpasta-Spasta<<"pasta remaining in hostel";
                break;
              }

        case 3:
              cout<<"\n\nEnter the quantity of Burgar:";
              cin>>quant;
              if(Qburgar-Sburgar>=quant)
              {
                Sburgar=Sburgar+quant;
                Total_burgar=Total_burgar+quant*50;
                cout<<"\n\n\t"<<quant<<"-Burgar is ordered!";
                break;
              }
              else
              {
                cout<<"\n\tOnly"<<Qburgar-Sburgar<<"Burgar remaining in hostel";
                break;
              }

        case 4:
              cout<<"\n\nEnter the quantity of noddles:";
              cin>>quant;
              if(Qnoodles-Snoodles>=quant)
              {
                Snoodles=Snoodles+quant;
                Total_noodles=Total_noodles+quant*50;
                cout<<"\n\n\t"<<quant<<"-noodles is ordered!";
                break;
              }
              else
              {
                cout<<"\n\tOnly"<<Qnoodles-Snoodles<<"noodles remaining in hostel";
                break;
              }

         case 5:
              cout<<"\n\nEnter the quantity of chicken_roll:";
              cin>>quant;
              if(Qchicken-Schicken>=quant)
              {
                Schicken=Schicken+quant;
                Total_chicken=Total_chicken+quant*50;
                cout<<"\n\n\t"<<quant<<"-chicken_Roll is ordered!";
                break;
              }
              else
              {
                cout<<"\n\tOnly"<<Qchicken-Schicken<<"noodles remaining in hostel";
                break;
              }

         case 6:
              cout<<"\n\t\tDetails of sales and collection";
              cout<<"\n\nNumber of rooms we had:"<<Qrooms;
              cout<<"\n\nNumber of rooms we gave for rent:"<<Srooms;
              cout<<"\n\nRemaining Rooms:"<<Qrooms-Srooms;
              cout<<"\n\nTotal rooms collection for the day:"<<Total_rooms;


              cout<<"\n\nNumber of pasta we had:"<<Qpasta;
              cout<<"\n\nNumber of pasta we sold:"<<Spasta;
              cout<<"\n\nRemaining pasta:"<<Qpasta-Spasta;
              cout<<"\n\nTotal pasta collection for the day:"<<Total_pasta;  

              
              cout<<"\n\nNumber of burgar we had:"<<Qburgar;
              cout<<"\n\nNumber of burgar we sold:"<<Sburgar;
              cout<<"\n\nRemaining burgar:"<<Qburgar-Sburgar;
              cout<<"\n\nTotal burgar collection for the day:"<<Total_burgar;
              

              cout<<"\n\nNumber of noodles we had:"<<Qnoodles;
              cout<<"\n\nNumber of Noodles we sold:"<<Snoodles;
              cout<<"\n\nRemaining Noddles:"<<Qnoodles-Snoodles;
              cout<<"\n\nTotal Noodles collection for the day:"<<Total_noodles;


              cout<<"\n\nNumber of chicken_Roll we had:"<<Qchicken;
              cout<<"\n\nNumber of chiken_roll we sold:"<<Schicken;
              cout<<"\n\nRemaining chicken_Roll:"<<Qchicken-Schicken;
              cout<<"\n\nTotal chicken_Roll collection for the day:"<<Total_chicken;

        case 7:
             exit(0);

             default:
                  cout<<"\n\nPlease select the choice correctly!!";    

    }
    goto m;
    return 0;

}