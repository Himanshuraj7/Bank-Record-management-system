#include<bits/stdc++.h>
using namespace std;
class HDFC_BANK
{
public:
	char account_number[20];
    char firstName[10];
    char lastName[10];
    float total_Balance;
    
    void read_data();
    void show_data();
    void write_data();
    void read_rec();
    void search_data();
    void edit();
    void delete_data();
    void fordelay(int j);
};

void HDFC_BANK::fordelay(int j)
{   int i,k=0;
    for(i=0;i<j;i++)
         k++;
}
void HDFC_BANK::read_data()
{
    cout<<"\nEnter Account Number: ";
    cin>>account_number;
    cout<<"Enter First Name: ";
    cin>>firstName;
    cout<<"Enter Last Name: ";
    cin>>lastName;
    cout<<"Enter Balance: ";
    cin>>total_Balance;
    cout<<endl;
}
void HDFC_BANK::show_data()
{
    cout<<"Account Number: "<<account_number<<endl;
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Current Balance: Rs.  "<<total_Balance<<endl;
    cout<<"-------------------------------"<<endl<<endl;
}
void HDFC_BANK::write_data()
{
    ofstream outfile; // ofstream to write
    outfile.open("record.txt", ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
    system("cls");
}
void HDFC_BANK::read_rec()
{
    ifstream infile; // ifstream to read
    infile.open("record.txt", ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    
    cout<<"\n****Data from file****"<<endl;
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
        {
            show_data();
        }
    }
    infile.close();
}
void HDFC_BANK::search_data()
{
    int n;
    ifstream infile;
    infile.open("record.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
}
void HDFC_BANK::edit()
{
    int n;
    fstream iofile;
    iofile.open("record.txt", ios::in|ios::binary);
    if(!iofile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to edit: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
    show_data();
    iofile.close();
    iofile.open("record.txt", ios::out|ios::in|ios::binary);
    iofile.seekp((n-1)*sizeof(*this));
    cout<<"\nEnter data to Modify "<<endl;
    read_data();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void HDFC_BANK::delete_data()
{
    int n;
    ifstream infile;
    infile.open("record.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("tmpfile.txt", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("record.txt");
    rename("tmpfile.txt", "record.txt");
}
int main()
{	HDFC_BANK A;
	system("color 9"); // color 9 for blue
	printf("\n\n\t\t\t\t======BANKING RECORD MANAGEMENT SYSTEM======\n\n\n\n");
	printf("\t\tCREATED BY\n\n");
	printf("\t\tHIMANSHU RAJ\n\n");
	printf("\t\tCSE   LOVELY PROFESSIONAL UNIVERSITY\n\n\n\n");
	
	
	char pass[10],password[10]="c";
    int i=0, main_exit;;
    
    pass:
    cout<<"\n\n\t\tEnter the password to login:";
    cin>>pass;
    
    if (strcmp(pass,password)==0)
        {
		cout<<"\n\nPASSWORD MATCH!\nLOADING";
        for(i=0;i<=8;i++)
        {
            A.fordelay(100000000);
            printf(".");
        }
            system("cls");
            goto start;
        }
    else
        {   cout<<"\n\nWrong password!!";
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        goto pass;
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    exit(0);
					}
            else
                    {
					printf("\nInvalid!");
                    A.fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }

	start:
    int choice;
    while(true)
    {
    	cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Show record from file";
        cout<<"\n\t3-->Search Record from file";
        cout<<"\n\t4-->Update Record";
        cout<<"\n\t5-->Delete Record";
        cout<<"\n\t6-->Quit";
        cout<<"\nEnter your choice: ";
        
        cin>>choice;
        switch(choice)
        {
        case 1:
            A.write_data();
            break;
        case 2:
            A.read_rec();
            break;
        case 3:
            A.search_data();
            break;
        case 4:
            A.edit();
            break;
        case 5:
            A.delete_data();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\n-*-*-Enter correct choice-*-*-"<<endl<<endl;
        }
    }
    return 0;
}
