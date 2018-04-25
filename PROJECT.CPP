#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<process.h>
#include<fstream.h>
#include<stdio.h>
#include <dos.h>

void change(int);
void increase(int);
void price(float);
class easyday
{long B_code;
int ecode,dis,q;
char product_name[20];
float rate,price;
public:
int getecode()
{
return ecode;
}
int retquan()
{return q;}
float retprice()
{return price;}
float retrate()
{return rate;}
char* retname()
{return product_name;}

void inputp ()
{cout<<"\nEnter Barcode ";
cin>>B_code;
cout<<"\nEnter code ";
cin>>ecode;
cout<<"\nEnter product name ";
gets(product_name);

cout<<"\n M.R.P ";
cin>>rate;
cout<<"\nQuntity ";
cin>>q;
cout<<"\n discount ";
cin>>dis;
 price=rate-(float(rate/100) * dis);
}
void change(int m)
{
q=q-m;
}
void increase(int m)
{
q=q+m;
}
void displayp()
{
cout<<"\n Barcode        : "<<B_code;
cout<<"\n code           : "<<ecode;
cout<<"\n product's name : "<<product_name;
cout<<"\n Quantity       : "<<q;
cout<<"\n M.R.P          : "<<rate;
cout<<"\n discount       : "<<dis;
cout<<"\n our price      : "<<price;
}
};
fstream file;
int main()
{clrscr();
cout<<"\n\n\n\n\n\n\n\n\t\t\tPROJECT OF C++"
    <<"\n\t\t\tMADE BY:-PRATEEK GUWALANI"
    <<"\n\t\t\tCLASS:-XII A"
    <<"\n\t\t\tCENTRAL ACADEMY"
    <<"\n\t\t\tSUBMIT TO:-M.R. I.B.SIR";
getch();
clrscr();
char password[30];
for(int i=0;i<3;i++)
{
cout<<"\n\n\n\t\t\tEnter password\n\t\t\t";
cin.getline(password,30);
clrscr();
if((strcmp(password,"nothing"))==0||(strcmp(password,"NOTHING"))==0)
{  cout<<"\n\n\n\t\t\tO.K\n";
getch();
clrscr();
cout<<"\n\n\n\n\n\n\n\n\t\t\tEasy day" ;
cout<<"\n\t\tsabse sasta sabse acha";
void intro();
char ch='y';
clrscr();
easyday e;
int n;
int choice;
ifstream fin;
ofstream fout;
while(ch=='y'||ch=='Y')
{
clrscr();
cout<<"\n\n\n\n\n"
    <<"\n\t1.INSERT PRODUCT\n"
    <<"\n\t2.REMOVE PRODUCT\n"
    <<"\n\t3.UPDATE PRODUCT DETAIL\n"
    <<"\n\t4.DISPLAY PRODUCT DETAIL\n "
    <<"\n\t5.CUSTOMER BILLING\n"
    <<"\n\t6.EXIT\n";
cin>>n;
    easyday itemlist[50];
    switch(n)
    {
     case 1: clrscr();
	    fout.open("c:\p\eas.dat",ios::binary|ios::app);
	    e.inputp();
	    fout.write((char*)&e,sizeof(e));
	    fout.close();
	    break;
     case 2:clrscr();
	    fin.open("c:\p\eas.dat",ios::binary);
	    fout.open("c:\p\eas1.dat");
	    cout<<"Enter product code for deletion";
	    cin>>n;
	    while(fin.read((char*)&e,sizeof(e)))
	    {
	    if(n!=e.getecode())
	    fout.write((char*)&e,sizeof(e));
	    }
	    fout.close();
	    fin.close();
	    remove("c:\p\eas.dat");
	    rename("c:\p\eas1.dat","c:\p\eas.dat");
	    break;
    case 3: clrscr();

	   cout<<"enter product code for updation";
	   cin>>n;
	   clrscr();
	   cout<<"What do you want to update \n"
		<<"1.full updation\n"
		<<"2.increase in qunantity\n"
		<<"3.Nothing to update get back\n " ;

	    cin>>choice;
	    switch(choice)
	    {
	    case 1:fin.open("c:\p\eas.dat",ios::binary);
		  fout.open("c:\p\eas1.dat",ios::binary);
		  while(fin.read((char*)&e,sizeof(e)))
		    {
		     if(n!=e.getecode())
		      fout.write((char*)&e,sizeof(e));
		       else
		       {
		     cout<<"ENTER NEW DETAILS OF PRODUCT\n";
		    e.inputp();
		     fout.write((char*)&e,sizeof(e));
			}
		    }
		fout.close();
		fin.close();
		remove("c:\p\eas.dat");
		rename("c:\p\eas1.dat","c:\p\eas.dat");
		break;
	    case 2:int p;
		file.open("c:\p\eas.dat",ios::in|ios::out);
		cout<<"Enter the quntity to be increased ";
		cin>>p;

		while(file.read((char*)&e,sizeof(e)))
		    {
		     if(n==e.getecode())
		     {e.increase(p);
		      int position=file.tellg();
		      file.seekg(position-sizeof(easyday),ios::beg);
		      file.write((char*)&e,sizeof(e));
		      }
		     }
		     break;
	    case 3: break;
	    default: break;
	      }break;
     case 4:clrscr();
	    cout<<"ENTER YOUR CHOICE\n"
		<<"1.FULL LENGTH DETAILS\n"
		<<"2.PARTICULAR CODE TO DISPLAY\n";
	    cin>>choice;
	    switch(choice)
	    {
	    case 1:clrscr();
		   fin.open("c:\p\eas.dat",ios::in|ios::binary);
		   while(fin.read((char*)&e,sizeof(e)))
		   {
		   e.displayp();
		   cout<<"\n";
		   }
		   fin.close();
		  getch();
		  break;
	    case 2:clrscr();
		   cout<<"Enter the code to be display\n ";
		   cin>>n;
		   fin.open("c:\p\eas.dat",ios::in|ios::binary);
		   while(fin.read((char*)&e,sizeof(e)))
		   {if (n==e.getecode())
		   {
		   e.displayp();
		   cout<<"\n";
		   }
		   }
		   fin.close();
		  getch();
		  break;
	    } break;
     case 5:
	    int order[50],quan[50],c=0,sn=0,m,k;
	    float amt,total=0.0;
	    char CH='y';
	    clrscr();
	    intro();
	    cout<<"\n\tPlace your order";
	    do{
	    cout<<"\n\nEnter the code of the product : ";
	    cin>>order[c];
	    cout<<"\nenter the quantity in number ";
	    cin>>quan[c];
	    c=c+1;
	    cout<<"\ndo you want to order another product ?(y/n) ";
	    cin>>CH;
	    }
	    while(CH=='y'||CH=='Y');
	    cout<<"\n\n Thank you for placing order ";
	    getch();
	    clrscr();
	    intro();
	    cout<<"\n\n===================================Billing===================================";
	    cout<<"\ns.no\tcode\tproduct name\tQuntity\tM.R.P\tour price\tamount\n";
	    for(int i=0;i<c;i++)
	    {
	    file.open("c:\p\eas.dat",ios::in|ios::out);

	    file.read((char*)&e,sizeof (e));
	    while(!file.eof())
	    {
	    if(e.getecode()==order[i])
	    {
	    amt=e.retprice()*quan[i];
	    cout<<"\n"<<i+1<<" \t "<<e.getecode()<<"\t"<<e.retname()<<"\t"<<quan[i]<<"\t"<<e.retrate()
		<<"\t"<<e.retprice()<<"\t"<<amt;
	   m=quan[i];
	    e.change(m);
	    int position=file.tellg();
	    file.seekg(position-sizeof(easyday),ios::beg);
	    file.write((char*)&e,sizeof(e));
	    file.seekg(position,ios::beg);
	     sn += quan[i];
	   total+=amt;
	   }
	   file.read((char*)&e,sizeof (easyday));
	   }
	   file.close();
	   }

	   cout<<"\n\n\t\t\t\t\t\t\tTOTAL= "<<total;
	   cout<<"\n\t\t\t\t\t\t TOTAl number item sold = "<<sn;
	   cout<<"\n\n\n		               THANK YOU		";
	   cout<<"\n	                       VISIT AGAIN	";
	    getch();
	    break;

     case 6:exit(0);
	    break;
     default:break;

	    }
	    clrscr();
	    cout<<"DO YOU WISH TO CONTINUE ";
	    cin>>ch;
	   }
      getch();
      break;
      }
else
 {
  cout<<"\n\n\n\t\t\tsorry incorect password !!!\n";
  getch();
  clrscr();
  }
}return 0;
}
void intro()
{
clrscr();
	    cout<<"                                                          ";
	    cout<<"\t\t\t\t\t\t     WELCOME TO EASYDAY \t\n";
	    struct date d;

   getdate(&d);
   printf("The current date is: %d/%d/%d\n", d.da_day,d.da_mon,d.da_year);
   struct  time t;

gettime(&t);
printf("The current time is: %2d:%02d:%02d.%02d\n",
       t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
}