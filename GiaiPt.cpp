#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>
#define maxlist 3
using namespace std;
void giaibac1()
{
	double a,b;
	double x;
	cout<<"Nhap a,b:";
	cin>>a>>b;
	cout<<"Phuong trinh co dang "<<a<<"*x + "<<b<<" = 0"<<endl;
	if ((a==0)&&(b==0))
		cout<<"Phuong trinh vo so nghiem.";
	else if ((a==0)&&(b!=0))
		cout<<"Phuong trinh vo nghiem.";
	else
	{
		x=(-b)/a;
		cout<<"Nghiem phuong trinh: X= "<<x<<endl;
	}
}
void giaibac2()
{
	double a,b,c,k;
	cout<<"Nhap a,b,c:";
	cin>>a>>b>>c;
	double x1,x2;
	cout<<"Phuong trinh co dang "<<a<<"*x*x + "<<b<<"*x + "<<c<<" = 0"<<endl;
	k=b*b-4*a*c;
	if (k<0)
	 cout<<"Phuong trinh vo nghiem.";
	else if (k>0)
	{
		x1=(-b+sqrt(k))/(2*a);
		x2=(-b-sqrt(k))/(2*a);
		cout<<"Phuong trinh co 2 nghiem: X1= "<<x1<<endl;
		cout<<"                          X2= "<<x2;
	}
	else if (k==0)
	{
	 	x1=(-b)/(2*a);
		cout<<"Nghiem phuong trinh: X= "<<x1;
	}
}
int main()
{
	char* menu[maxlist];
	int pointer = 0;
	menu[0]= "1. Giai PTB1";
	menu[1]= "2. Giai PTB2";
	menu[2]= "3. Thoat";
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"---------- Menu ----------\n\n";
		for (int i=0; i<3; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				cout<<menu[i]<<endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				cout<<menu[i]<<endl;
			}
		}
		
		while (true)
		{
			if (kbhit())
			{
				char key = getch();
				if (key == 72)
				{
					pointer-=1;
					if (pointer == -1)
					{
						pointer = 2;
					}
					break;
				}
				else if (key == 80)
				{
					pointer+=1;
					if (pointer == 3)
					{
						pointer = 0;
					}
					break;
				}
				else if (key == 13)
				{
					if (pointer == 0)
					{
						giaibac1();
						system("pause");
						break;
					}
					else if (pointer == 1)
					{
						giaibac2();
						system("pause");
						break;
					}
					else if (pointer == 2)
					{
						exit(0);
					}
				}
			}
			Sleep(150);
		}
	}
	return 0;
}

