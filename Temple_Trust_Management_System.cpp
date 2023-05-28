#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<fstream>
using namespace std;

class Devotee
{
public:
    
    string pb_date,edar_date;
    int pid=1,doid=1,darid=1, dch;
    string edar_time;
    char pb_name[100],don_name[100],don_c[100],edar_name[100];
    long pb_contact,don_contact,don,edar_adh;
    
    void Edarshan();
    void PujaBooking();
    void Donation();
    void Mahaprasad();
    void dar_dis();
    void puj_dis();
    void don_dis();
};

void Devotee::PujaBooking()
{
    cout << "\nEnter the details.\n";
    cout<<"Booking ID : ";
    cin>>pid;
    cout << "Name : ";
    cin>>pb_name;
    cout << "Contact no. : +91 ";
    cin >> pb_contact;
    cout << "Puja Date : ";
    cin >> pb_date;
    
    fstream pobj;
    pobj.open("puja.txt",ios::app);
    pobj.seekp (0, ios::end);
    pobj<<pid<<endl<<pb_name<<endl<<pb_contact<<endl<<pb_date<<endl;
    pobj.close();
    cout<<"\nPooja Booking Successfull..."<<endl;
}

void Devotee::Donation()
{
    cout << "\nEnter the details.\n";
    cout<<"Donation ID : ";
    cin>>doid;
    cout << "Name : ";
    cin>> don_name;
    cout << "Contact no. : +91 ";
    cin >> don_contact;
    cout << "City : ";
    cin>>don_c;
    cout << "Donation : ";
    cin >> don;
    
    fstream ddon;
    ddon.open("donation.txt",ios::app);
    // ddon.seekp(0,ios::end);
    ddon<<doid<<endl<<don_name<<endl<<don_contact<<endl<<don_c<<endl<<don<<endl;
    ddon.close();
    cout<<"\nDonar info saved.";
}

void Devotee::Edarshan()
{
    cout << "\nEnter the details.\n";
    cout<<"Darshan ID : ";
    cin>>darid;
    cout<<"Name : ";
    cin>>edar_name;
    cout << "Aadhar no : ";
    cin >> edar_adh;
    cout << "Darshan Date : ";
    cin >> edar_date;
    cout << "1)10:00 - 12:00  2)14:00 - 16:00  3)16:00 - 18:00\n";
    cin >> dch;
    if(dch==1)
    {
        edar_time = "10:00-12:00";
    }
    if(dch==2)
    {
        edar_time = "14:00-16:00";
    }
    if(dch==3)
    {
        edar_time = "16:00-18:00";
    }
   
    fstream eobj;
    eobj.open("darshan.txt",ios::app);
    eobj.seekp(0,ios::end);
    eobj<<darid<<endl <<edar_name<<endl <<edar_adh<<endl <<edar_date<<endl <<edar_time<<endl;
    eobj.close();
    cout<<"\nEdarshan booking saved."<<endl;
}

void Devotee::dar_dis()
{
    int x,count=0;
    cout<<"\nEnter the ID of the Devotee : ";
    cin>>x;
    fstream eobj("darshan.txt",ios::in);
    // eobj.seekp(0);

    while(eobj>>darid>>edar_name>>edar_adh>>edar_date>>edar_time)
    {
        
        cout<<"1.ID : "<<darid<<endl <<"2.Name : "<<edar_name<<endl <<"3.Aadhar : "<<edar_adh<<endl <<"4.Date of Darshan : "<<edar_date<<endl <<"5.Time Slot : "<<edar_time<<endl;
        cout<<"i";
        if(darid==x)
        {
            cout<<"1.ID : "<<darid<<endl <<"2.Name : "<<edar_name<<endl <<"3.Aadhar : "<<edar_adh<<endl <<"4.Date of Darshan : "<<edar_date<<endl <<"5.Time Slot : "<<edar_time<<endl;
            count++;
            break;
        }
        
    }
    
    eobj.close();
    if(count==0)
    {
        cout<<"\nNo Match Found!!!"<<endl;
    }

}

void Devotee::puj_dis()
{
    int x,count=0;
    cout<<"\nEnter the ID of the Devotee : ";
    cin>>x;
    fstream pobj("puja.txt");
    pobj.seekg(0);

    while(pobj>>darid>>pb_name>>pb_contact>>pb_date)
    {
        if(pid==x){
        cout<<"1.ID : "<<pid<<endl <<"2.Name : "<<pb_name<<endl <<"3.Contact no. : +91 "<<pb_contact<<endl <<"4.Date of Darshan : "<<pb_date<<endl;
        count++;
        break;
        }
    }
    
    pobj.close();
    if(count==0)
    {
        cout<<"\nNo Match Found!!!"<<endl;
    }

}
void Devotee::don_dis()
{
    int x,count=0;
    cout<<"\nEnter the ID of the Devotee : "<<endl;
    cin>>x;
    fstream ddon("donation.txt");
    ddon.seekg(0);

    while(ddon>>doid>>don_name>>don_contact>>don_c>>don)
    {
        if(doid==x){
        cout<<"1.ID : "<<doid<<endl <<"2.Name : "<<don_name<<endl <<"3.Contact no. : "<<don_contact<<endl <<"4.City : "<<don_c<<endl <<"5.Donation : "<<don<<endl;
        count++;
        break;
        }
    }
    
    ddon.close();
    if(count==0)
    {
        cout<<"\nNo Match Found!!!"<<endl;
    }

}

int main()
{
    int ch;
    string usr,pass;
    
    cout << "\n-------------------------------------------------------------\n";
    cout << "                SAI BABA SANSTHAN , Shirdi\n";
    cout << "-------------------------------------------------------------\n";
    
    cout << "            **Temple Trust Management System**\n\n";
    
    do
    {
        cout << "Username : ";
        cin >> usr;
        cout << "Password : ";
        cin >> pass;
        if(usr != "admin" || pass != "Admin@123")
        {
            cout << "\nInvalid username or password!!!\n\n";
        }
    }while(usr != "admin" || pass != "Admin@123");
        
    do
    {
        Devotee D;
        
        cout << "\n                          .MENU.\n";
        cout<<"0.Exit"<<endl<<"1.Book E-darshan"<<endl<<"2.Book Pooja"<<endl<<"3.Donation Entry"<<endl<<"4.Display E-darshan data"<<endl<<"5.Display Pooja Booking data"<<endl<<"6.Display Donation Data"<<endl;
        cin >> ch;
                
            switch(ch)
            {
                case 1:
                    {
                        cout << "\n#E-darshan\n";
                        D.Edarshan();
                    }break;
                        
                case 2:
                    {
                        cout << "\n#Puja-Booking\n";
                        D.PujaBooking();
                    }break;
                        
                case 3:
                    {
                        cout << "\n#Donation\n";
                        D.Donation();
                    }break;
                        
                case 4:
                    {
                        D.dar_dis();
                    }break;
                        
                case 5:
                    {
                        D.puj_dis();
                    }break;
                        
                case 6:
                    {
                        D.don_dis();
                    }break;
            }
        
    }while(ch!=0);
    
    return 0;
}
