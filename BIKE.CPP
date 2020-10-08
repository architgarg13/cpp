#include<dos.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
class file
{
private:
	int bikeno;
	float capacity;
	char name[100];
	float milage;
	float maxpower;
	float weight;
public:
	float price;
	void DisplayB();
	void input();
	void show();
	int getn()
	{
		return bikeno;
	}
	char *geta()
	{
		return name;
	}

};file fileobj;
class dealer
{
	private:
	char nameofcomp[100];
	char Address[100];
	long long int phone;
	int year;
	int rating;
	char brand[100];
	public:
	void get();
	void output();
	char *getno()
	{
		return nameofcomp;
	}
};dealer dealerobj;
void color()
{
	int gd=DETECT,gm,i,y=50,c;
	initgraph(&gd,&gm,"c:/TURBOC3/BGI");
	c=getmaxcolor();
	for(i=0;i<=c;i++)
	{
		for(int g=4;g<5;g++)
		{
			setcolor(i);
			settextstyle(g,0,g);
			outtextxy(20,30*g," WELCOME TO THE BIKE DROVERS !!! ");
			y=y+20;
			delay(200);
		}
	}
	delay(20);
	getch();
	closegraph();
}
void colore()
{
	int gd=DETECT,gm,i,y=50,c;
	initgraph(&gd,&gm,"c:/TURBOC3/BGI");
	c=getmaxcolor();
	for(i=0;i<=c;i++)
	{
		for(int g=4;g<5;g++)
		{
			setcolor(i);
			settextstyle(g,0,g);
			outtextxy(20,30*g," THANK YOU MADE BY BIKE RIDERS ");
			y=y+20;
			delay(200);
		}
	}
	delay(20);
	getch();
	closegraph();
}
void cycle()
{
	int a=DETECT,b,x,i,j;
  initgraph(&a,&b,"c:\\turboc3\\BGI");
  for(x=170,i=0;!kbhit();x++,i--)
  {
  arc(x,200,270,90,20);
  line(x,220,x-60,220);
  line(x,180,x-60,200);
  line(x-60,220,x-60,200);
  rectangle(x-110,200,x-60,220);
  line(x-110,220,x-60,250);
  line(x,220,x-60,250);
  line(x-60,220,x-60,250);
  circle(x-140,250,5);
  circle(x-140,250,30);
  line(x-60,250,x-140,250);
  line(x-110,220,x-140,250);
  line(x,200,x+50,250);
  line(x,220,x+50,250);
  circle(x+50,250,5);
  circle(x+50,250,30);
  circle(x,200,5);
  arc(x,200,315,45,30);
  line(x,200,x+21,179);
  line(x,200,x-25,175);
  circle(x-25,175,5);
  line(x-25,175,x-60,160);
  line(x-60,160,x-80,200);
  circle(x-60,145,15);
  line(x-80,200,x-50,215);
  line(x-50,215,x-60,250);
  line(0,280,639,280);
  for(j=0;j<30;j++)
  { arc(x-140,250,i,i+1,j);
    arc(x-140,250,i+90,i+91,j);
    arc(x-140,250,i+180,i+181,j);
    arc(x-140,250,i+270,i+271,j);
    arc(x+50,250,i,i+1,j);
    arc(x+50,250,i+90,i+91,j);
    arc(x+50,250,i+180,i+181,j);
    arc(x+50,250,i+270,i+271,j);
  }
  delay(20);
  cleardevice();
  if(x==558)
  {x=170;
  i=0;
  }
  }
  closegraph();
}
void dealer::get()
{
	cout<<"\n Dealers which want to be Part of Bike Drovers:";
	cout<<"\n Enter Name of company:";
	gets(nameofcomp);
	cout<<"\n Enter Address of company:";
	gets(Address);
	cout<<"\n Enter Phone Number:";
	cin>>phone;
	cout<<"\n Enter Established Year:";
	cin>>year;
	cout<<"\n Enter Rating in market:";
	cin>>rating;
	cout<<"\n Enter Brand which you want to serve:";
	gets(brand);
}
void dealer::output()
{
	cout<<"\n Name of company:"<<nameofcomp;
	cout<<"\n Address of company:"<<Address;
	cout<<"\n Phone Number:"<<phone;
	cout<<"\n Established Year:"<<year;
	cout<<"\n Rating in market:"<<rating;
	cout<<"\n Brand which you want to serve:"<<brand;
}
void file::input()
{
	cout<<"\n Enter Bike number      :";
	cin>>bikeno;
	cout<<"\n Enter Name             :";
	gets(name);
	cout<<"\n Enter price of bike    :";
	cin>>price;
	cout<<"\n Enter capacity of bike :";
	cin>>capacity;
	cout<<"\n Enter  milage          :";
	cin>>milage;
	cout<<"\n Enter max power        :";
	cin>>maxpower;
	cout<<"\n Enter weight           :";
	cin>>weight;

}
void file::show()
{
	cout<<"\n Bike Number is       :"<<bikeno;
	cout<<"\n Bike Name is         :"<<name;
	cout<<"\n Price of Bike is     :"<<price<<"  Onwards";
	cout<<"\n Capacity of Bike is  :"<<capacity<<"  cc.";
	cout<<"\n Milage of Bike is    :"<<milage<<"  Kilometers";
	cout<<"\n Max power of Bike is :"<<maxpower<<"  Bhp";
	cout<<"\n Weight of Bike is    :"<<weight<<"  Kg";
}
void Add();
void DisplayP();
void Modify();
void Delete();
fstream fil;
void Add()              //Function to Add New Record in Data File
{
	char ch='y';
	fil.open("binary.dat",ios::app| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		fileobj.input();
		fil.write((char*)&fileobj, sizeof(fileobj));
		cout<<"Want to Continue.....";
		cin>>ch;
	}
	fil.close();
}
void DisplayP()		//Function to Display particular Record from Data File
{

	int n;
	cout<<"\n Enter Bike no to be searched:";
	cin>>n;
	clrscr();
	fil.open("binary.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(n==fileobj.getn())
			{
				fileobj.show();
				getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
}
void Modify()		//Function to Modify Particular Record from Data File
{
	int n;
	cout<<"Enter Bike no to be searched:";
	cin>>n;
	fil.open("binary.dat",ios::in| ios::out|ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(n==fileobj.getn())
			{
				fil.seekg(0,ios::cur);
				cout<<"Enter New Record.."<<endl;
				fileobj.input();
				fil.seekp(fil.tellg() - sizeof(fileobj));
				fil.write((char*)&fileobj, sizeof(fileobj));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
}
void Delete()		//Function to Delete Particular Record from Data File
{
	int n;
	cout<<"Enter bike no to be Deleted :";
	cin>>n;
	ofstream o;
	o.open("new.dat",ios::out|ios::binary);
	fil.open("binary.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(n!=fileobj.getn())
			{
				o.write((char*)&fileobj, sizeof(fileobj));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	o.close();
	fil.close();
	remove("binary.dat");
	rename("new.dat", "binary.dat");
}
void Displayd()		//Function to Display All Record from Data File
{
	fil.open("dealer.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&dealerobj, sizeof(dealerobj));
		while(!fil.eof())
		{
			dealerobj.output();
			cout<<"Press Any Key....For Next Record"<<endl;
			getch();
			fil.read((char*)&dealerobj, sizeof(dealerobj));
		}
	}
	fil.close();
}
void Addd()              //Function to Add New Record in Data File
{
	char ch='y';
	fil.open("dealer.dat",ios::app| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		dealerobj.get();
		fil.write((char*)&dealerobj, sizeof(dealerobj));
		cin>>ch;
	}
	fil.close();
}
void DisplayPd()		//Function to Display particular Record from Data File
{
	char no[100];
	cout<<"\n Enter Bike Dealer Name to be searched:";
	gets(no);
	clrscr();
	fil.open("dealer.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&dealerobj, sizeof(dealerobj));
		while(!fil.eof())
		{
			if(strcmp(no,dealerobj.getno())==0)
			{
				dealerobj.output();
				cout<<"\n Press any key to Exit...... ";
				getch();
			}
			fil.read((char*)&dealerobj, sizeof(dealerobj));
		}
	}
	fil.close();
}
void Modifyd()		//Function to Modify Particular Record from Data File
{
	char no[100];
	cout<<"Enter Bike dealer Name to be searched:";
	gets(no);
	fil.open("dealer.dat",ios::in| ios::out|ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&dealerobj, sizeof(dealerobj));
		while(!fil.eof())
		{
			if(strcmp(no,dealerobj.getno())==0)
			{
				fil.seekg(0,ios::cur);
				cout<<"Enter New Record.."<<endl;
				dealerobj.get();
				fil.seekp(fil.tellg() - sizeof(dealerobj));
				fil.write((char*)&fileobj, sizeof(fileobj));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&dealerobj, sizeof(dealerobj));
		}
	}
	fil.close();
}
void Deleted()		//Function to Delete Particular Record from Data File
{
	char no[100];
	cout<<"Enter bike Dealer Name to be Deleted :";
	gets(no);
	ofstream o;
	o.open("dealer1.dat",ios::out|ios::binary);
	fil.open("dealer.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&dealerobj, sizeof(dealerobj));
		while(!fil.eof())
		{
			if(strcmp(no,dealerobj.getno())!=0)
			{
				o.write((char*)&dealerobj, sizeof(dealerobj));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&dealerobj, sizeof(dealerobj));
		}
	}
	o.close();
	fil.close();
	remove("dealer.dat");
	rename("dealer1.dat", "dealer.dat");
}

void con()
{
	char ch;
	cout<<"\n   Do you want to continue[Y/N] :";
	cin>>ch;
	if(ch=='n'||ch=='N')
	{
		colore();
		exit(0);
	}
}
struct Dealer
{
	char name[50];
	char address[50];
	int long  phoneno;
	char email;
	int establish;
	int rating;
	char brand[20];
}a1;
void honda()
{
			clrscr();
			cout<<"\n Choose bike :";
			cout<<"\n 1:Honda Navi";
			cout<<"\n 2:Honda cliq";
			cout<<"\n 3:Honda CD 110 Dream";
			cout<<"\n 4:Honda Activa i";
			cout<<"\n 5:Honda Dream neo";
			cout<<"\n 6:Honda dio";
			cout<<"\n 7:Honda Activa 4G";
			cout<<"\n 8:Honda dream yuga";
			cout<<"\n 9:Honda aviator";
			cout<<"\n 10:Honda livo";
			cout<<"\n 11:Honda CB Shine";
			cout<<"\n 12:Honda Activa 125";
			cout<<"\n 13:Honda Grazia";
			cout<<"\n 14:Honda CB Shine SP";
			cout<<"\n 15:Honda CB Unicorn 150";
			DisplayP();
}
void bajaj()
{
		clrscr();
			cout<<"\n Choose bike :";
			cout<<"\n 16:Bajaj CT100";
			cout<<"\n 17:Bajaj Platina";
			cout<<"\n 18:Bajaj Discover 125";
			cout<<"\n 19:Bajaj V12";
			cout<<"\n 20:Bajaj Pulsar 125";
			cout<<"\n 21:Bajaj V15";
			cout<<"\n 22:Bajaj Pulsar 150";
			cout<<"\n 23:Bajaj Avenger 150 Street";
			cout<<"\n 24:Bajaj Pulsar ns160";
			cout<<"\n 25:Bajaj Pulsar180";
			cout<<"\n 26:Bajaj Avenger 220 Street";
			cout<<"\n 27:Bajaj Avenger 220 cruise";
			cout<<"\n 28:Bajaj Pulsar 220F";
			cout<<"\n 29:Bajaj Pulsar NS200";
			cout<<"\n 30:Bajaj Pulsar RS200";
			cout<<"\n 31:Bajaj Dominor 400";
			DisplayP();
}
void hero()
{
			clrscr();
			cout<<"\n Choose bike :";
			cout<<"\n 32:Hero HF Deluxe";
			cout<<"\n 33:Hero HF Deluxe Eco";
			cout<<"\n 34:Hero Splendor Plus";
			cout<<"\n 35:Hero HF Delux i3s";
			cout<<"\n 36:Hero Pleasure";
			cout<<"\n 37:Hero Duet";
			cout<<"\n 38:Hero Splendor Pro";
			cout<<"\n 39:Hero Splendor Plus i3s";
			cout<<"\n 40:Hero Passion pro i3s";
			cout<<"\n 41:Hero Maestro Edge";
			cout<<"\n 42:Hero Super Splendor";
			cout<<"\n 43:Hero Splendor ismart 110";
			cout<<"\n 44:Hero Glamour";
			cout<<"\n 45:Hero Achiever 150";
			cout<<"\n 46:Hero Glamour i3s";
			cout<<"\n 47:Hero Glamour Fl";
			cout<<"\n 48:Hero Xtreme Sports";
			DisplayP();
}
void Tvs()
{
			clrscr();
			cout<<"\n Choose Bike:";
			cout<<"\n 49:TVS Xl 100";
			cout<<"\n 50:TVS Xl 100 Comfort";
			cout<<"\n 51:TVS Sport";
			cout<<"\n 52:TVS Scooty Pep Plus";
			cout<<"\n 53:TVS Star City Plus";
			cout<<"\n 54:TVS Scooty Zest 110";
			cout<<"\n 55:TVS Jupiter";
			cout<<"\n 56:TVS Victor";
			cout<<"\n 57:TVS Wego";
			cout<<"\n 58:TVS Apache RTR 160";
			cout<<"\n 59:TVS Apache RTR 180";
			cout<<"\n 60:TVS Apache RTR 180 ABS";
			cout<<"\n 61:TVS Apache RTR 200 4V";
			DisplayP();
}
void Yahama()
{
			clrscr();
			cout<<"\n Choose Bike :";
			cout<<"\n 62:Yamaha Saluto RX";
			cout<<"\n 63:Yamaha Ray Z";
			cout<<"\n 64:Yamaha Alpha";
			cout<<"\n 65:Yamaha Cygnus Ray ZR";
			cout<<"\n 66:Yamaha Saluto";
			cout<<"\n 67:Yamaha Fascino";
			cout<<"\n 68:Yamaha SZ RR V 2.0";
			cout<<"\n 69:Yamaha FZ V 2.0";
			cout<<"\n 70:Yamaha FZ S V 2.0";
			cout<<"\n 71:Yamaha FL V 2.0";
			cout<<"\n 72:Yamaha YZF R15 S";
			cout<<"\n 73:Yamaha FZ 25";
			cout<<"\n 74:Yamaha YZF R15";
			cout<<"\n 75:Yamaha YZF R15 V3";
			cout<<"\n 76:Yamaha Fazer 25";
			cout<<"\n 77:Yamaha YZF R3";
			cout<<"\n 78:Yamaha MT 09";
			DisplayP();
}
void Suzuki()
{
			clrscr();
			cout<<"\n Choose Bike :";
			cout<<"\n 79:Suzuki Let's";
			cout<<"\n 80:Suzuki Hayate Ep";
			cout<<"\n 81:Suzuki Access 125";
			cout<<"\n 82:Suzuki Gixxer";
			cout<<"\n 83:Suzuki Gixxer SF";
			cout<<"\n 84:Suzuki Gixxer SF Fi ";
			cout<<"\n 85:Suzuki Intuder";
			cout<<"\n 86:Suzuki GSX S1000";
			cout<<"\n 87:Suzuki GSX S1000f";
			cout<<"\n 88:Suzuki v Strome 1000";
			cout<<"\n 89:Suzuki Hayabusa";
			cout<<"\n 90:Suzuki intuder M1800R";
			cout<<"\n 91:Suzuki GSX R1000";
			DisplayP();
}
void KTM()
{
			clrscr();
			cout<<"\n Choose bike :";
			cout<<"\n 92:KTM 200 Duke";
			cout<<"\n 93:KTM RC200";
			cout<<"\n 94:KTM 250 Duke";
			cout<<"\n 95:KTM RC390";
			cout<<"\n 96:KTM 390 Duke";
			DisplayP();
}
void HarleyDavidson()
{
			clrscr();
			cout<<"\n Enter Bike:";
			cout<<"\n 97:Harley Davidson Street 750";
			cout<<"\n 98:Harley Davidson Street Rod";
			cout<<"\n 99:Harley Davidson Iron 883";
			cout<<"\n 100:Harley Davidson 1200 Custom";
			cout<<"\n 101:Harley Davidson Forty Eight";
			cout<<"\n 102:Harley Davidson Roadster";
			cout<<"\n 103:Harley Davidson Street bob";
			cout<<"\n 104:Harley Davidson Fat Bob";
			cout<<"\n 105:Harley Davidson Fat Boy";
			cout<<"\n 106:Harley Davidson Heritage classic";
			DisplayP();
}
void BMW()
{
			clrscr();
			cout<<"\n Choose bike:";
			cout<<"\n 107:BMW F750 GS";
			cout<<"\n 108:BMW F850 GS";
			cout<<"\n 109:BMW R1200 R";
			cout<<"\n 110:BMW R Nine T Scrambler";
			cout<<"\n 111:BMW R 1200 RS";
			cout<<"\n 112:BMW R1200 GS ";
			cout<<"\n 113:BMW S 1000 R ";
			cout<<"\n 114:BMW R Nine T Racer";
			cout<<"\n 115:BMW R1200 GS Adventure";
			cout<<"\n 116:BMW R Nine T ";
			cout<<"\n 117:BMW S 1000 XR";
			DisplayP();
}
void Ducati()
{
			clrscr();
			cout<<"\n Choose Bike :";
			cout<<"\n 118:Ducati Scrambler Icon";
			cout<<"\n 119:Ducati Monster 797";
			cout<<"\n 120:Ducati Scrambler Classic";
			cout<<"\n 121:Ducati Scrambler Full Throttle";
			cout<<"\n 122:Ducati Scrambler Mach 2.0";
			cout<<"\n 123:Ducati Scrambler Cafe Racer";
			cout<<"\n 124:Ducati Scrambler Desert Sled";
			cout<<"\n 125:Ducati Monster 821 ";
			cout<<"\n 126:Ducati Hypermotared 939";
			cout<<"\n 127:Ducati SuperSport";
			DisplayP();
}
void Indian()
{
			clrscr();
			cout<<"\n Choose bike:";
			cout<<"\n 128:Indian Scout Sixty";
			cout<<"\n 129:Indian Scout Bobber";
			cout<<"\n 130:Indian Scout";
			cout<<"\n 131:Indian Chief Dark Horse";
			cout<<"\n 132:Indian Chief Classic";
			cout<<"\n 133:Indian Chief Vintage";
			cout<<"\n 134:Indian Chieftain Dark Horse";
			cout<<"\n 135:Indian Chieftain";
			cout<<"\n 136:Indian Spring Field";
			cout<<"\n 137:Indian Roadmaster Classic";
			DisplayP();
}
void YO()
{
			clrscr();
			cout<<"\n Choose Bike:";
			cout<<"\n 138: Yo Electron ER";
			cout<<"\n 139: Yo Xplor";
			cout<<"\n 140: Yo Spark";
			cout<<"\n 141: Yo EXL";
			DisplayP();
}
void Brand()
{
		int b;
		cout<<"\n Views bikes of your favourite brand:";
		cout<<"\n 1:Honda";
		cout<<"\n 2:Bajaj";
		cout<<"\n 3:Hero";
		cout<<"\n 4:TVS";
		cout<<"\n 5:Yamaha";
		cout<<"\n 6:Suzuki";
		cout<<"\n 7:KTM";
		cout<<"\n 8:Harley Davidson";
		cout<<"\n 9:BMW";
		cout<<"\n 10:Ducati";
		cout<<"\n 11:Indian";
		cout<<"\n 12:YO";
		cout<<"\n Enter your option :";
		cin>>b;
		con();
		switch(b)
		{
			case 1:
			honda();
			break;
			case 2:
			bajaj();
			break;
			case 3:
			hero();
			break;
			case 4:
			Tvs();
			break;
			case 5:
			Yahama();
			break;
			case 6:
			Suzuki();
			break;
			case 7:
			KTM();
			break;
			case 8:
			HarleyDavidson();
			break;
			case 9:
			BMW();
			break;
			case 10:
			Ducati();
			break;
			case 11:
			Indian();
			break;
			case 12:
			YO();
			break;
		}
}
void Budget()
{
		int c,t,u,v,w;
		cout<<"\n View bikes in your Price range:";
		cout<<"\n 1:Upto Rs.50,000";
		cout<<"\n 2:Between Rs.50,000 - Rs.1 lac ";
		cout<<"\n 3:Between Rs.1 Lac-2 Lac";
		cout<<"\n 4:Above Rs.2 Lac";
		cout<<"\n Enter your option:";
		cin>>c;
		con();
		switch(c)
		{
			case 1:
			clrscr();
			cout<<"\n Bikes Upto Rs.50,000 are:";
			cout<<"\n 1:YO";
			cout<<"\n 2:Hero";
			cout<<"\n Enter Your choice :";
			cin>>t;
			con();
			switch(t)
			{
				case 1:
				YO();
				break;
				case 2:
				hero();
				break;
			}
			break;
			case 2:
			clrscr();
			cout<<"\n Bikes Between Rs.50,000 - Rs.1 lac are:";
			cout<<"\n 1:Honda";
			cout<<"\n 2:Bajaj";
			cout<<"\n 3:Hero";
			cout<<"\n 4:TVS";
			cout<<"\n Enter your choice:";
			cin>>u;
			con();
			switch(u)
			{
				case 1:
				honda();
				break;
				case 2:
				bajaj();
				break;
				case 3:
				hero();
				break;
				case 4:
				Tvs();
				break;
			}
			break;
			case 3:
			clrscr();
			cout<<"\n Bikes Between Rs.1 Lac-2 Lac are:";
			cout<<"\n 1:Yahama";
			cout<<"\n 2:KTM";
			cout<<"\n 3:Suzuki";
			cout<<"\n Enter your choice:";
			cin>>v;
			con();
			switch(v)
			{
				case 1:
				Yahama();
				break;
				case 2:
				KTM();
				break;
				case 3:
				Suzuki();
				break;
			 }
			 break;
			 case 4:
			 clrscr();
			 cout<<"\n Bikes Above Rs.2 Lac";
			 cout<<"\n 1:Indian";
			 cout<<"\n 2:Ducati";
			 cout<<"\n 3:BMW";
			 cout<<"\n 4:Harley Davidson";
			 cout<<"\n Enter choice";
			 cin>>w;
			 con();
			 switch(w)
			 {
				case 1:
				Indian();
				break;
				case 2:
				Ducati();
				break;
				case 3:
				BMW();
				break;
				case 4:
				HarleyDavidson();
				break;
			  }
			  break;



		}
}
void Milage()
{
		int d,t,u,v,w;
		cout<<"\n View bikes with your desiered milage:";
		cout<<"\n 1:Above 70 kmpl";
		cout<<"\n 2:Between 70 kmpl-50 kmpl";
		cout<<"\n 3:Between 50 kmpl-30 kmpl";
		cout<<"\n 4:Upto 30 kmpl";
		cout<<"\n Enter your option :";
		cin>>d;
		con();
		switch(d)
		{
			case 1:
			clrscr();
			cout<<"\n Bikes Milage Above 70 kmpl are:";
			cout<<"\n 1:YO";
			cout<<"\n Enter Your choice :";
			cin>>t;
			con();
			switch(t)
			{
				case 1:
				YO();
				break;
			}
			break;
			case 2:
			clrscr();
			cout<<"\n Bikes Milage between 70kmpl-50kmpl are:";
			cout<<"\n 1:Honda";
			cout<<"\n 2:Bajaj";
			cout<<"\n 3:Hero";
			cout<<"\n 4:TVS";
			cout<<"\n 5:Hero";
			cout<<"\n Enter your choice:";
			cin>>u;
			con();
			switch(u)
			{
				case 1:
				honda();
				break;
				case 2:
				bajaj();
				break;
				case 3:
				hero();
				break;
				case 4:
				Tvs();
				break;
				case 5:
				hero();
			}
			break;
			case 3:
			clrscr();
			cout<<"\n Bikes Milage between 50kmpl-30kmpl are:";
			cout<<"\n 1:Yahama";
			cout<<"\n 2:KTM";
			cout<<"\n 3:Suzuki";
			cout<<"\n Enter your choice:";
			cin>>v;
			con();
			switch(v)
			{
				case 1:
				Yahama();
				break;
				case 2:
				KTM();
				break;
				case 3:
				Suzuki();
				break;
			 }
			 break;
			 case 4:
			 clrscr();
			 cout<<"\n Bikes Milage Upto 30kmpl are";
			 cout<<"\n 1:Indian";
			 cout<<"\n 2:Ducati";
			 cout<<"\n 3:BMW";
			 cout<<"\n 4:Harley Davidson";
			 cout<<"\n Enter choice";
			 cin>>w;
			 con();
			 switch(w)
			 {
				case 1:
				Indian();
				break;
				case 2:
				Ducati();
				break;
				case 3:
				BMW();
				break;
				case 4:
				HarleyDavidson();
				break;
			  }
			  break;
		}
}
void Ridestyle()
{
		int e,t,r,y,s,z;
		cout<<"\n View bikes that suit your riding style:";
		cout<<"\n 1:Scooter";
		cout<<"\n 2:Street";
		cout<<"\n 3:Crusier";
		cout<<"\n 4:Sports";
		cout<<"\n Enter your option :";
		cin>>e;
		con();
		switch(e)
		{
			case 1:
			clrscr();
			cout<<"\n In Scooter Style listed brand provide Bikes:";
			cout<<"\n 1:YO";
			cout<<"\n Enter Your choice :";
			cin>>t;
			con();
			switch(t)
			{
				case 1:
				YO();
				break;
			}
			break;
			case 2:
			clrscr();
			cout<<"\n In Street Style Listed brands provides Bikes:";
			cout<<"\n 1:Honda";
			cout<<"\n 2:Bajaj";
			cout<<"\n 3:Hero";
			cout<<"\n 4:TVS";
			cout<<"\n 5:Yamaha";
			cout<<"\n 6:Suzuki";
			cout<<"\n Choose Brand :";
			cin>>s;
			con();
			switch(r)
			{
				case 1:
				honda();
				break;
				case 2:
				bajaj();
				break;
				case 3:
				hero();
				break;
				case 4:
				Tvs();
				break;
				case 5:
				Yahama();
				break;
				case 6:
				Suzuki();
				break;
			}
			case 3:
			clrscr();
			cout<<"\n In Crusier style some Brands are listed below:";
			cout<<"\n 1:Indian";
			cout<<"\n 2:Harley Davidson";
			cout<<"\n Enter choice";
			cin>>y;
			con();
			switch(y)
			{
				case 1:
				Indian();
				break;
				case 2:
				HarleyDavidson();
				break;
			}
			break;
			case 4:
			clrscr();
			cout<<"\n Sports style listed brands provide bikes:";
			cout<<"\n 1:Ducati";
			cout<<"\n 2:BMW";
			cout<<"\n Enter your Choice:";
			cin>>z;
			con();
			switch(z)
			{
				case 1:
				Ducati();
				break;
				case 2:
				BMW();
				break;
			}
		}
}
void DisplayB()		//Function to Display particular Record from Data File
{
	char a[100];
	cout<<"\n Enter Name that should be searched:";
	cout<<"\n* If you dont know Name of bike (press a)";
	gets(a);
	if(a==a)
	{
		Brand();

	}
	fil.open("binary.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"\n File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(a,fileobj.geta())==0)
			{
				fileobj.show();
				cout<<"\n Press Any Key...."<<endl;
				getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
}
void main()
{
	clrscr();
	cycle();
	int a,b,c,d,e,u,v,w,x,s,t,r,k,y,z;
	color();
	start:
	clrscr();
	textcolor(CYAN);
	cprintf("\n *************************************************************************@@@@@");
	cprintf("\n #########################################################################@@@@@");
	cout<<"\n WELCOME TO THE \n BIKE DROVERS \n ";
	cprintf("\n #########################################################################@@@@@");
	cprintf("\n *************************************************************************@@@@@");
	cout<<"\n Choose options from the given menu :";
	cout<<"\n 1:Brand              |B                              B                    |";
	cout<<"\n 2:Budget             |  I                 M            I                  |";
	cout<<"\n 3:Milage             |    K                 A            K                |";
	cout<<"\n 4:Ride Style         |      E                 D            E              |";
	cout<<"\n 5:Comparision        |        D                 E            R            |";
	cout<<"\n 6:Locate Dealers     |          R                              I          |";
	cout<<"\n 7:On Road Price      |            O                              D        |";
	cout<<"\n 8:Technical Issues   |              V                B             E      |";
	cout<<"\n 9:News               |                E                Y             R    |";
	cout<<"\n 10:Expert Reviews    |                  R                              S  |";
	cout<<"\n 11:Features          |                    S                               |";
	cout<<"\n 12:Exit	      |                                                    |";
	cout<<"\n Enter your choice : ";
	cin>>a;
	con();
	switch(a)
	{
		case 1:
		clrscr();
		Brand();
		goto start;
		break;
		case 2:
		clrscr();
		Budget();
		goto start;
		break;
		case 3:
		clrscr();
		Milage();
		goto start;
		break;
		case 4:
		clrscr();
		Ridestyle();
		goto start;
		break;
		case 5:
		clrscr();
		cout<<"\n Comparision by Brand of Bikes:";
		cout<<"\n Brand : Honda         || Bajaj         || Hero            || TVS";
		cout<<"\n Milage: above70kmpl   || 60-70kmpl     || Above 70kmpl    || 50- 60kmpl";
		cout<<"\n Price : Rs60K - 80K   || Rs70K-110K    || Rs 60K - 70K    || Rs50K -75K";
		cout<<"\n Type  : Scooter,Street|| Sports,Street || Scooter,Street  || Scooter,Street";
		cout<<"\n Power : Upto 100cc    || Upto 150cc    || Upto 125cc      || Upto 125cc";
		cout<<"\n ****************************************************************************";
		cout<<"\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
		cout<<"\n ****************************************************************************";
		cout<<"\n Brand : Yahama        || Suzuki        || KTM             || HarleyDavidson";
		cout<<"\n Milage: 60-65kmpl     || 50-60kmpl     || 40-45kmpl       || 30- 35kmpl";
		cout<<"\n Price : Rs60K - 110K  || Rs70K-210K    || Rs150k -650K    || Rs200k-1000k";
		cout<<"\n Type  : Scooter,Street|| Sports,Street || Sports          || Crusier";
		cout<<"\n Power : Upto 800cc    || Upto 1250cc   || Upto 1000cc     || Upto1250cc";
		cout<<"\n ****************************************************************************";
		cout<<"\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
		cout<<"\n ****************************************************************************";
		cout<<"\n Brand : BMW           || Ducati        || Indian          || YO";
		cout<<"\n Milage: 20-30kmpl     || 15-25kmpl     || 20-30kmpl       || Above kmpl";
		cout<<"\n Price : Above 1000K   || Above 2000K   || Rs3000k - 4800k || Rs50k-60k";
		cout<<"\n Type  : Sports        || Sports        || Crusier         || Scooter";
		cout<<"\n power : Upto 2000cc   || Upto 2000cc   || Upto 3000cc     || Upto 150cc";
		getch();
		goto start;
		break;
		case 6:
		clrscr();
		char d;
		cout<<"\n Dealers types:";
		cout<<"\n 1:Dealers which are part of Bike Drovers ";
		cout<<"\n 2:Dealers which want to be Part of Bike Drovers";
		cout<<"\n Enter your choice :";
		cin>>k;
		con();
		switch(k)
		{
			case 1:
			clrscr();
			cout<<"\n Dealers which are part of Bike Drovers are Listed Below:";
			cout<<"\n Dealers  : Rohan            || Riders       || Duet           || Ducati ";
			cout<<"\n Address  : near lg chowk,gr.|| sec-62,Noida || sec-18,Noida   || New Delhi ";
			cout<<"\n Phone no : 941222431        || 865046727    || 701741711      || 8006090237 ";
			cout<<"\n Ratings  : 4.4*             || 4.8*         || 4.7*           || 5.0* ";
			cout<<"\n Brand    : Suzuki           || All Brands   || Indian(crusier)|| Ducati(Sports)";
			cout<<"\n*******************************************************************************";
			cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
			cout<<"\n*******************************************************************************";
			cout<<"\n Dealers  : Dewan            || TCS          || Swadesh        || Baggalink ";
			cout<<"\n Address  : palam Dabri Road || Okhla, Delhi || sec-21,Noida   || Karol Bagh ";
			cout<<"\n Phone no : 9313382111       || 8644444727   || 7017333311     || 80433490237 ";
			cout<<"\n Ratings  : 4.4*             || 4.9*         || 4.1*           || 5.0* ";
			cout<<"\n Brand    : Bajaj,suzuki     || All Brands   || YO(Scooter)    || bajaj";
			cout<<"\n******************************************************************************";
			cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
			cout<<"\n******************************************************************************";
			cout<<"\n Dealers  : Royal            || Rajivraj     || Fairdeal       || Ambe ";
			cout<<"\n Address  : Chowk,gr.        || Durgachowk   || Noida          || Greater noida ";
			cout<<"\n Phone no : 9222222431       || 865046727    || 7222341711     || 80344240237 ";
			cout<<"\n Ratings  : 4.6*             || 4.8*         || 4.6*           || 5.0* ";
			cout<<"\n Brand    : All Brands       || All Brands   || Ducati         || Ducati(Sports)";
			cout<<"\n Display By Delear Name(y/n) :";
			cin>>d;
			if(d=='y')
			{
				DisplayPd();
				getch();
				goto start;
			}
			else
			{
				goto start;
			}
			break;
			case 2:
			clrscr();
			Addd();
			cout<<"\n Please submit amount to www.bikewale.com ";
			cout<<"\n You will get you company name(if transection is cleared) ";
			cout<<"\n Information Will be displayed in next update";
			textcolor(YELLOW+BLINK);
			cprintf("\n Congratulations!!!                Now You are a part of Bike Drovers");
			break;

		}
		break;
		case 7:
		clrscr();
		long long float tax,insurence,roadtax;
		long long float bike;
		cout<<"\n::::ON ROAD PRICE MENU::::";
		int state;
		cout<<"\n:::::Select State From Below:::::";
		cout<<"\n 1:Andhra Pradesh";
		cout<<"\n 2:Arunachal Pradesh ";
		cout<<"\n 3:Assam";
		cout<<"\n 4:Bihar";
		cout<<"\n 5:Chhattisgarh";
		cout<<"\n 6:Goa";
		cout<<"\n 7:gujrat";
		cout<<"\n 8:Haryana";
		cout<<"\n 9:Himachal Pradesh";
		cout<<"\n 10:Jammu and Kashmir";
		cout<<"\n 11:Jharkhand";
		cout<<"\n 12:Karnataka";
		cout<<"\n 13:Kerala";
		cout<<"\n 14:Madhya Pradesh";
		cout<<"\n 15:Maharashtra";
		cout<<"\n 16:Manipur";
		cout<<"\n 17:Odisha";
		cout<<"\n 18:Punjab";
		cout<<"\n 19:Rajasthan";
		cout<<"\n 20:Uttar Pradesh";
		cout<<"\n Enter State Number :";
		cin>>state;
		con();
		switch(state)
		{
			case 1:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.06;
			roadtax=bike*.03;
			tax=bike*.09;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 2:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.07;
			roadtax=bike*.04;
			tax=bike*.08;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 3:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.05;
			roadtax=bike*.05;
			tax=bike*.08;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 4:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.06;
			roadtax=bike*.03;
			tax=bike*.09;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 5:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.04;
			roadtax=bike*.03;
			tax=bike*.07;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 6:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.08;
			roadtax=bike*.03;
			tax=bike*.06;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 7:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.05;
			roadtax=bike*.05;
			tax=bike*.06;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 8:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.09;
			roadtax=bike*.02;
			tax=bike*.10;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 9:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.02;
			roadtax=bike*.07;
			tax=bike*.09;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 10:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.06;
			roadtax=bike*.06;
			tax=bike*.06;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 11:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.07;
			roadtax=bike*.05;
			tax=bike*.08;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 12:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.08;
			roadtax=bike*.09;
			tax=bike*.02;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 13:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.04;
			roadtax=bike*.03;
			tax=bike*.11;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 14:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.02;
			roadtax=bike*.07;
			tax=bike*.09;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 15:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.03;
			roadtax=bike*.06;
			tax=bike*.08;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 16:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.08;
			roadtax=bike*.01;
			tax=bike*.08;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 17:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.16;
			roadtax=bike*.01;
			tax=bike*.01;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 18:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.08;
			roadtax=bike*.01;
			tax=bike*.09;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 19:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.05;
			roadtax=bike*.04;
			tax=bike*.08;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
			case 20:
			clrscr();
			DisplayB();
			cout<<"\n Enter price of Bike:";
			cin>>bike;
			insurence=bike*.07;
			roadtax=bike*.02;
			tax=bike*.07;
			cout<<"\n Road Tax :"<<roadtax;
			cout<<"\n Insurence :"<<insurence;
			cout<<"\n Other Tax :"<<tax;
			cout<<"\n Total On Road Price is :"<<bike+tax+insurence+roadtax;
			getch();
			goto start;
			break;
		}
		break;
		case 8:
		int choice;
		clrscr();
		cout<<"\n Technical Menu";
		int password;
		cout<<"\n Enter Password :";
		cin>>password;
		if(password==12345)
		{
			cout<<"\n Choose from below :";
			cout<<"\n 1:Add Bikes";
			cout<<"\n 2:Delete Bikes";
			cout<<"\n 3:Modify Bikes";
			cout<<"\n 4:Add Dealer";
			cout<<"\n 5:Delete Dealer";
			cout<<"\n 6:Modify Dealer";
			cout<<"\n 7:Display Dealer";
			cout<<"\n 8:Display All Dealer";
			cout<<"\n Enter your Choice :";
			cin>>choice;
			con();
			switch(choice)
			{
				case 1:
				clrscr();
				Add();
				getch();
				goto start;
				break;
				case 2:
				clrscr();
				Delete();
				getch();
				goto start;
				break;
				case 3:
				clrscr();
				Modify();
				getch();
				goto start;
				break;
				case 4:
				clrscr();
				Addd();
				getch();
				goto start;
				break;
				case 5:
				clrscr();
				Deleted();
				getch();
				goto start;
				break;
				case 6:
				clrscr();
				Modifyd();
				getch();
				goto start;
				break;
				case 7:
				clrscr();
				DisplayPd();
				getch();
				goto start;
				break;
				case 8:
				clrscr();
				Displayd();
				getch();
				goto start;
				break;
				default:
				clrscr();
				textcolor(YELLOW);
				cprintf("\n:::::INCORRECT OPTION:::::");
				getch();
				goto start;
				break;
			}
		}
		else
		{
			textcolor(YELLOW);
			cprintf("\n:::::INCORRECT PASSWORD:::::");
		}
		break;
		case 9:
		clrscr();
		cout<<"\n #####@@@@@#####@@@@@ NEWS HEADLINES #####@@@@@#####@@@@@";
		cout<<"\n* Four bikes that will compete against the upcoming KTM 390 Adventure";
		cout<<"\n* KTM 790 Duke launched in Malaysia at Rs 10.99 lakhs";
		cout<<"\n* Ducati Multistrada 1260 S vs BMW R 1200 GS spec Comparison";
		cout<<"\n* Suzuki Access 125 CBS:What else can you buy";
		cout<<"\n* KTM Confirms 390 Adventure for india in 2019";
		cout<<"\n* Ducati Multistrada 1260:what to expect";
		cout<<"\n* MV Agusta Turismo Veloce 800 Lusso SCS Photo Gallery";
		cout<<"\n* Mahindra Mojo XT300 now available in a new colour";
		cout<<"\n* Suzuki Burgman Street bookings to begin from 1st july";
		cout<<"\n* Kawasaki India begins Ninja 400 deliveries";
		cout<<"\n  For more Visit to WWW.Bikewala.com ";
		getch();
		goto start;
		break;
		case 10:
		clrscr();
		cout<<"\n #####@@@@@#####@@@@@ Expert Reviews #####@@@@@#####@@@@@";
		cout<<"\n* Royal Enfield Classic 350 : 3.8 Stars";
		cout<<"\n* Harley Davidson : 4.0 Stars";
		cout<<"\n* TVS Apache RR 310 : 4.2 Stars";
		cout<<"\n* Suzuki Intuder : 4.4 Stars";
		cout<<"\n* Hero Xtreme 200 : 2.8 Stars";
		cout<<"\n* TVS Ntorq : 3.8 Stars";
		cout<<"\n* TVS Apache RTR 160 4V : 4.6 Stars";
		cout<<"\n* Honda CBR 650 F : 3.6 Stars";
		cout<<"\n  For more Visit to WWW.Bikewala.com ";
		getch();
		goto start;
		break;
		case 11:
		clrscr();
		cout<<"\n #####@@@@@#####@@@@@ Features #####@@@@@#####@@@@@#####";
		cout<<"\n* Apollo Alpha H1 Motorcycle Radial Tyre";
		cout<<"\n* Daytona AC pro Short boots Product Review";
		cout<<"\n* Top Gun India Adventure Riding Academy Review";
		cout<<"\n* Helsons sonny Mesh jacket Product Review";
		cout<<"\n* Helmet Cooler Made by a Boy From India Review";
		cout<<"\n  For more Visit to WWW.Bikewala.com ";
		getch();
		goto start;
		case 12:
		cout<<"\n You will be exited ";
		getch();
		colore();
		exit(0);
		break;
		default:
		clrscr();
		textcolor(YELLOW+BLINK);
		cprintf("\n:::::INCORRECT OPTION:::::");
		break;
	}
		getch();
}