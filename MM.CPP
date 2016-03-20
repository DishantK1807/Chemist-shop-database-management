#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
class chemist_shop
{
      private:
	      int c_code;
	      char c_name[40];

	      int c_discount;
	      float c_price;
	      float c_quantity;
      public:
	     void getdata();
	     void mod(int n);
	     void putdata();
	     int ret_disc()
	     {
		 return c_discount;
		 }
	     int rett_code()
	     {
		 return c_code;
		 }
	     char *ret_nm()
	     {
		 return c_name;
		 }
	     float ret_pr()
	     {
		 return c_price;
		 }
	     float ret_qty()
	     {
		 return c_quantity;
		 }
	     };
void write();
void modify();
void del();
void search_all();
void search_id();
void search_nm();
void search_pr();
	 void search_qty();
void purchase();
      void title()
      {
      gotoxy(15,9);
      cout<<"ллллллллллллллллллллллллллллллллллллллллллл";
      gotoxy(15,10);
      cout<<"лл                                       лл";
      gotoxy(15,11);
      cout<<"лл                                       лл";
      gotoxy(15,12);
      cout<<"лл                                       лл";
      gotoxy(15,13);
      cout<<"лл                                       лл";
      gotoxy(15,14);
      cout<<"лл             ўўўTITLEўўў               лл";
      gotoxy(15,15);
      cout<<"лл           Chemist Shop                лл";
      gotoxy(15,16);
      cout<<"лл                                       лл";
      gotoxy(15,17);
      cout<<"лл                                       лл";
      gotoxy(15,18);
      cout<<"лл                                       лл";
      gotoxy(15,19);
      cout<<"лл                                       лл";
      gotoxy(15,20);
      cout<<"лл                                       лл";
      gotoxy(15,21);
      cout<<"лл                                       лл";
      gotoxy(15,22);
      cout<<"лл                                       лл";
      gotoxy(15,23);
      cout<<"лл                                       лл";
      gotoxy(15,24);
      cout<<"ллллллллллллллллллллллллллллллллллллллллллл";
      getch();
 }
 void mmenu()
 {  clrscr();
    gotoxy(15,5);
    cout<<"лллллллллллллллллллллллллллллллллллллллллллл";
    gotoxy(15,6);
    cout<<"лл                                        лл";
    gotoxy(15,7);
    cout<<"лл                                        лл";
    gotoxy(15,8);
    cout<<"лл             MAIN MENU лл";
    gotoxy(15,9);
    cout<<"лл                                        лл";
    gotoxy(15,10);
    cout<<"лл                                        лл";
    gotoxy(15,11);
    cout<<"лл          1.File menu                   лл";
    gotoxy(15,12);
    cout<<"лл          2.Search                      лл";
    gotoxy(15,13);
    cout<<"лл          3.Purchase                    лл";
    gotoxy(15,14);
    cout<<"лл          4.Exit                        лл";
    gotoxy(15,15);
    cout<<"лл                                        лл";
    gotoxy(15,16);
    cout<<"лл                                        лл";
    gotoxy(15,17);
    cout<<"лл                                        лл";
    gotoxy(15,18);
    cout<<"лл                                        лл";
    gotoxy(15,19);
    cout<<"лл                                        лл";
    gotoxy(15,20);
    cout<<"лллллллллллллллллллллллллллллллллллллллллллл";
    cout<<"\n\n\nўўў ENTER YOUR CHOICE ўўў  ";
    }
 void filem()
 {
   int t;
   do{
   clrscr();
   gotoxy(25,7);
   cout<<"ььь FILE MAINTAINANCE MENU ььь";
   gotoxy(15,10);
   cout<<"1.Addition";
   gotoxy(15,12);
   cout<<"2.Modification";
   gotoxy(15,14);
   cout<<"3.Deletion";
   gotoxy(15,16);
   cout<<"4.Exit";
   cin>>t;
   switch(t)
   {
       case 1: write();
       break;
       case 2: modify();
       break;
       case 3: del();
       break;
       case 4: return;
       default: cout<<"Invalid Choice";
       getch();
   }
 }while(t!=4);
 }
 void search()
 {
     int t;
     do{
     clrscr();
     gotoxy(25,7);
     cout<<"\nьььSEARCH MENUььь";
     gotoxy(15,12);
     cout<<"\n1.display all records";
     gotoxy(15,14);
     cout<<"\n2.Display on the basis of code";
     gotoxy(15,16);
     cout<<"\n3.Display on the basis of Medicine name";
     gotoxy(15,18);
     cout<<"\n4.Display on the basis of Price";
     gotoxy(15,20);
     cout<<"\n5.Display on the basis of quantity";
     gotoxy(15,22);
     cout<<"\n6.Exit";
     cin>>t;
  switch(t)
  {
      case 1: search_all();
      break;
      case 2: search_id();
      break;
      case 3: search_nm();
      break;
      case 4: search_pr();
      break;
      case 5: search_qty();
      break;
      case 6: return;
      default: cout<<"\n Invalid Choice";
      getch();
  }
 }while(t!=6);
 }
 struct pur
 {
     int cid;
     char cnm[40];
     int qty;
     float disc;
     float price;
     float amt;
 };
 pur p[10];
 double totamt;
 pur find_rec(int n)
 {
 pur p;
 ifstream f;
 f.open("chemist.dat",ios::binary);
 chemist_shop c;
 int flg=0;
 while(f.read((char*)&c,sizeof(c)))
 {
 if(c.rett_code()==n)
	{  flg=1;
 p.cid=n;
 strcpy(p.cnm,c.ret_nm());
 p.price=c.ret_pr();
 p.disc=c.ret_disc();
 break;
	 }
 }
 f.close();
 if(flg==0){cout<<"Record not found";getch();}
 return p; }
 void billing(int i)
{
double totamt=0,d=0;
clrscr();
gotoxy(7,9);
cout<<"\n\n";
gotoxy(7,10);
cout<<"\n                                                          \n";
gotoxy(7,11);
cout<<"\n                                                          \n";
gotoxy(7,12);
cout<<"\n                                                          \n";
gotoxy(7,13);
cout<<"\n                                                          \n";
gotoxy(7,14);
cout<<"\n-*-*-*-*-*-*-*-*-*-*--*-*-*BILL-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
gotoxy(7,15);
cout<<"\n                                                          \n";
gotoxy(7,16);
cout<<"\n==========================================================\n";
gotoxy(7,17);
cout<<"\n                                                          \n";
gotoxy(7,18);
cout<<"\nMedicine   Medicine     qty     rate   disc    value      \n";
gotoxy(7,19);
cout<<"\n   id        name                                         \n";
gotoxy(7,20);
cout<<"\n                                                          \n";
gotoxy(7,21);
cout<<"\n                                                          \n";
gotoxy(7,22);
cout<<"\n                                                          \n";
gotoxy(7,23);

for( int k=0;k<i;k++ )
{
cout<<"\n"<<""<<p[k].cid<<"\t\t"<<p[k].cnm<<"\t"<<p[k].qty<<"\t"<<p[k].price
<<"\t"<<double(p[k].disc/100)<<"\t"<<p[k].amt-(double(p[k].amt*p[k].disc)/100)<<"     ";
d+=(double(p[k].amt*p[k].disc)/100);
totamt+=double(p[k].amt);
gotoxy(7,24);
cout<<"\n\n";

}
cout<<"\n\n\n ўўTotal amount=   "<<totamt;
cout<<"\n ўўDiscount=   "<<d;
cout<<"\n ўўNet amount=   "<<totamt-d;
getch();
}
void purchase()
 {
 int i=0;
 int cid,q;
 char resp='y';
 while(resp=='y')
 {
 clrscr();
cout<<"\n\n\nMedicine ID(enter 0 to exit)";
cin>>cid;
if(cid==0)
break;
p[i]=find_rec(cid);
cout<<"\n Medicine name:"<<p[i].cnm;
cout<<"\nMedicine price:"<<p[i].price;
cout<<"\nEnter quantity to purchase:";
cin>>p[i].qty;
p[i].amt=p[i].price*p[i].qty;
totamt+=p[i].amt;
i++;
cout<<"do you want to purchase more(y/n)?";
cin>>resp;
}
billing(i);
}
void start()
{
int ch;
do
{
clrscr();
mmenu();
cin>>ch;
switch(ch)
{
case 1: filem();
break;
case 2: search();
break;
case 3: purchase();
break;
case 4: exit(1);
break;
default: cout<<"Invalid Choice";
}
}while(ch!=4);  }

void chemist_shop::getdata()
{
cout<<"\n Enter code";
cin>>c_code;
cout<<"\n Enter name";
gets(c_name);
cout<<"\nEnter discount";
cin>>c_discount;
cout<<"\nEnter price";
cin>>c_price;
cout<<"\n Ener quantity";
cin>>c_quantity;
};
void chemist_shop::mod(int n)
{
clrscr();
c_code=n;
cout<<"\n Enter code"<<c_code;
cout<<"\n Enter name";
cin>>c_name;
cout<<"\n Enter discount";
cin>>c_discount;
cout<<"\nEnter price";
cin>>c_price;
cout<<"\nEnter quantity";
cin>>c_quantity;
};
void chemist_shop::putdata()
{
clrscr();
cout<<"\nCode"<<c_code;
cout<<"\nName"<<c_name;
cout<<"\nDiscount"<<c_discount;
cout<<"\nPrice"<<c_price;
cout<<"\nQuantity"<<c_quantity;
};
void write()
{
clrscr();
ofstream f("chemist.dat",ios::app|ios::binary|ios::app);
chemist_shop c;
char ans;
do{
c.getdata();
f.write((char*)&c,sizeof(c));
cout<<"\nWant to enter more(y/n):";
cin>>ans;
}while(ans=='y');
f.close();
}
void search_all()
{
		ifstream f("chemist.dat",ios::binary);
		chemist_shop c;
		while (f.read((char*)&c,sizeof(c)))
		{
		      c.putdata();
		      getch();
		}
		f.close();
		}


		void modify()
		{
		     int no,found=0;
		     clrscr();
		     cout<<"\n\n\tTo Modify";
		     cout<<"\n\n\tPlease enter the product no. of the product";
		     cin>>no;
		     fstream f("chemist.dat",ios::in|ios::out|ios::binary);
		     chemist_shop pr;
		     while(f.read((char*)&pr,sizeof(pr))&&(found==0))
		     {
			 if(pr.rett_code()==no)
			 {
			 pr.putdata();
			 cout<<"\nPlease enter the new details of Product"<<endl;
			 pr.mod(no);
			 int pos=f.tellg()-sizeof(pr);
			 f.seekp(pos);
			 f.write((char*)&pr,sizeof(pr));
			 cout<<"\n\nRecord updated";
			 found=1;
			 break;
			 }
			 }
			 f.close();
			 }

		void del()
		{
		     int no,found =0;
		     clrscr();
		     cout<<"\n\n\tTo Delete";
		     cout<<"\n\n\tPlease enter the medicine no. to delete";
		     cin>>no;
		     fstream f("chemist.dat",ios::in|ios::binary);
		     fstream f1("c.dat",ios::out|ios::binary);
		     chemist_shop pr;
		     while(f.read((char*)&pr,sizeof(pr))&&(found==0))
		     {
			 if(pr.rett_code()!=no)

					       f1.write((char*)&pr,sizeof(pr));
		     }
					       f.close();
					       f1.close();
					       remove("chemist.dat");


			 rename("c.dat","chemist.dat");
}
void search_id()
{
ifstream f;
f.open("chemist.dat",ios::binary);
chemist_shop c;
int c_code;
cout<<"\n enter code";
cin>>c_code;
while(f.read((char*)&c,sizeof(c)))
{
if(c.rett_code()==c_code)
{
c.putdata();
getch();
}}
f.close();
};


void search_pr()
{
ifstream f;
f.open("chemist.dat",ios::binary);
chemist_shop c;
int price;
cout<<"\n enter price(to search less than or equal to price)";
cin>>price;
while(f.read((char*)&c,sizeof(c)))
{
if(c.ret_pr()<=price)
{
c.putdata();
getch();
}}
f.close();
};


void search_qty()
{
ifstream f;
f.open("chemist.dat",ios::binary);
chemist_shop c;
int qty;
cout<<"\n Enter qty(to search less than or equal to qty)";
cin>>qty;
while(f.read((char*)&c,sizeof(c)))
{
if(c.ret_qty()<=qty)
{
c.putdata();
getch();
}}
f.close();
};


void search_nm()
{
ifstream f;
f.open("chemist.dat",ios::binary);
chemist_shop c;
char cnm[40];
cout<<"\n enter name of medicine to search";
gets(cnm);
while(f.read((char*)&c,sizeof(c)))
{
if(strcmpi(c.ret_nm(),cnm)==0)
{
c.putdata();
getch();
}}
f.close();
};



int main()
{

clrscr();
title();
mmenu();
/*mod();
del();
getch();
*/
start();
getch();

return 0;
}

























