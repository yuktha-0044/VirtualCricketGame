#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void fbatting();
void fbowling();
void main()
{
	clrscr();
	int toss_ch,toss,batbowl_ch;
	char ans;
	cout<<"\t\t\t************* PC CRICKET **************\n"<<endl;
	do
	{
		cout<<"\t\t\t!!!!!! TOSS !!!!!!!\n"<<endl;
		cout<<"1. Heads"<<endl;
		cout<<"2. Tails"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>toss_ch;
		if(toss_ch==1||toss_ch==2)
		{
			toss=1+random(2);
			if(toss_ch==toss)
			{
				cout<<"Congrats!!! You have won the toss"<<endl;
				cout<<"Select your option"<<endl;
				cout<<"1.Bat"<<endl;
				cout<<"2.Bowl"<<endl;
				cin>>batbowl_ch;
				switch(batbowl_ch)
				{
					case 1:
					fbatting();
					cout<<"\t\t\t*******MATCH OVER*******"<<endl;
					break;
					case 2:
					fbowling();
					cout<<"\t\t\t*******MATCH OVER*******"<<endl;
					break;
					default:
					cout<<"Invalid option entered"<<endl;
					break;
				}
			}
			else
			{
				cout<<"Curses!!!You have lost the toss"<<endl;
				if(toss==1)
				{
					cout<<"Compter has chosen Batting first"<<endl;
					fbowling();
					cout<<"\t\t\t******* MATCH OVER *******"<<endl;
				}
				else
				{
					cout<<"Computer has chosen bowling first"<<endl;
					fbatting();
					cout<<"\t\t\t******* MATCH OVER *******"<<endl;
				}
			}
		}
		else
		{
			cout<<"Invalid option entered"<<endl;
		}
		cout<<"Want to play again?(y/n)"<<endl;
		cin>>ans;
	}
	while(ans=='Y'||ans=='y');
	getch();
}
void fbatting()
{
	int i,sc[100],comp_ch,run_ch,p,q,comp_sc[100],c_ch,r_ch,target;
	//***********************BATTING FIRST***********************//
	for(i=1;i<=10;i++)
	{
		cout<<"Enter any number between 1 and 6"<<endl;
		cin>>run_ch;
		comp_ch=1+random(6);
		cout<<"You entered     : "<<run_ch<<endl;
		cout<<"Computer entered: "<<comp_ch<<endl;
		sc[0]=0;
		if(run_ch>=1&&run_ch<=6)
		{
			sc[i]=sc[i-1]+run_ch;
			if(run_ch!=comp_ch)
			{
				cout<<"\t\t\t\tSCORE: "<<sc[i]<<" in "<<i<<" balls"<<endl;
				cout<<"\t\t\t\tBalls remaining: "<<10-i<<endl;
			}
			else
			{
				cout<<"You are out!!!"<<endl;
				sc[i]=sc[i-1];
				cout<<"\t\t\t\tSCORE: "<<sc[i]<<" in "<<i<<" balls"<<endl;
				break;
			}
		}
		else
		{
			 cout<<"Invalid number"<<endl;
			 i--;
		}
	}
	target=sc[i-1]+1;
	cout<<"\t\t\t\tTARGET: "<<target<<" runs from 10 balls"<<endl;

	//**********************BOWLING SECOND*********************//
	cout<<"\t\t\t\tBOWLING STARTS"<<endl;
	for(p=1;p<=10;p++)
	{
		cout<<"Enter any number between 1 and 6"<<endl;
		cin>>r_ch;
		c_ch=1+random(6);
		cout<<"You entered     : "<<r_ch<<endl;
		cout<<"Computer entered: "<<c_ch<<endl;
		comp_sc[0]=0;
		if(r_ch>=1&&r_ch<=6)
		{
			comp_sc[p]=comp_sc[p-1]+c_ch;
			if(r_ch!=c_ch)
			{
				cout<<"\t\t\t\tSCORE: "<<comp_sc[p]<<" in "<<p<<" balls"<<endl;
				if(target<=comp_sc[p])
				{
					cout<<"\t\t\t\t\You lose!!!"<<endl;
					break;
				}
				else if(target-1==comp_sc[p]&&p==10)
				{
					cout<<"\t\t\t\tIt is a tie!!!"<<endl;
					break;
				}
				else
				cout<<"\t\t\t\tRuns needed: "<<target-comp_sc[p]<<"\tBalls remaining: "<<10-p<<endl;
			}
			else
			{
				cout<<"Computer is out!!!"<<endl;
				comp_sc[p]=comp_sc[p-1];
				cout<<"\t\t\t\tSCORE: "<<comp_sc[p]<<" in "<<p<<" balls"<<endl;
				cout<<"\t\t\t\tYou win by "<<target-comp_sc[p]-1<<" runs!!!"<<endl;
				break;
			}
		}
		else
		{
			 cout<<"Invalid number"<<endl;
			 p--;
		}
	}
}
//*****************************BOWLING FIRST************************//
void fbowling()
{
	int i,sc[100],comp_ch,run_ch,p,q,comp_sc[100],c_ch,r_ch,target;
	cout<<"\t\t\t\tBOWLING STARTS"<<endl;
	for(p=1;p<=10;p++)
	{
		cout<<"Enter any number between 1 and 6"<<endl;
		cin>>r_ch;
		c_ch=1+random(6);
		cout<<"You entered     : "<<r_ch<<endl;
		cout<<"Computer entered: "<<c_ch<<endl;
		comp_sc[0]=0;
		if(r_ch>=1&&r_ch<=6)
		{
			comp_sc[p]=comp_sc[p-1]+c_ch;
			if(r_ch!=c_ch)
			{
				cout<<"\t\t\t\tSCORE: "<<comp_sc[p]<<" in "<<p<<" balls"<<endl;
				cout<<"\t\t\t\tBalls remaining: "<<10-p<<endl;
			}
			else
			{
				cout<<"Computer is out!!!"<<endl;
				comp_sc[p]=comp_sc[p-1];
				cout<<"\t\t\t\tSCORE: "<<comp_sc[p]<<" in "<<p<<" balls"<<endl;
				break;
			}
		}
		else
		{
			 cout<<"Invalid number"<<endl;
			 p--;
		}
	}
	target=comp_sc[p-1]+1;
	cout<<"\t\t\t\tTARGET: "<<target<<" runs from 10 balls"<<endl;

	//*************************BATTING SECOND***********************//
	cout<<"\t\t\t\tBATTING STARTS"<<endl;
	for(i=1;i<=10;i++)
	{
		cout<<"Enter any number between 1 and 6"<<endl;
		cin>>run_ch;
		comp_ch=1+random(6);
		cout<<"You entered     : "<<run_ch<<endl;
		cout<<"Computer entered: "<<comp_ch<<endl;
		sc[0]=0;
		if(run_ch>=1&&run_ch<=6)
		{
			sc[i]=sc[i-1]+run_ch;
			if(run_ch!=comp_ch)
			{
				cout<<"\t\t\t\tSCORE: "<<sc[i]<<" in "<<i<<" balls"<<endl;
				if(target<=sc[i])
				{
					cout<<"\t\t\t\t\You win!!!"<<endl;
					break;
				}
				else if(target-1==sc[i]&&i==10)
				{
					cout<<"\t\t\t\tIt is a tie!!!"<<endl;
					break;
				}
				else
				cout<<"\t\t\t\tRuns needed: "<<target-sc[i]<<"\tBalls remaining: "<<10-i<<endl;
			}
			else
			{
				cout<<"You are out!!!"<<endl;
				sc[i]=sc[i-1];
				cout<<"\t\t\t\tSCORE: "<<sc[i]<<" in "<<i<<" balls"<<endl;
				cout<<"\t\t\t\tYou lose by "<<target-sc[i]-1<<" runs!!!"<<endl;
				break;
			}
		}
		else
		{
			 cout<<"Invalid number"<<endl;
			 i--;
		}
	}
}
