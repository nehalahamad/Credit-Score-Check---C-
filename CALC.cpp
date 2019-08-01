#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include "windows.h"
using namespace std;

void gotoxy(int x, int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class applicant{
	string name, address;
	int age, m_sal, h_loan, p_loan, no_chq_bounce, company_tier;
	char own_house, spouse_working, dependent_parents;
	public:
		void get_data();
		int calc_liability();
		void display_score();	
};
void applicant::get_data(){
	system("cls");
	cout<<"Name of applicant: ";
	getline(cin, name);
	cout<<"Age: ";
	cin>>age;
	
	cin.clear();
	cin.ignore(1000, '\n');
	
	cout<<"Monthly Salary: ";
	cin>>m_sal;
	cout<<"Total Home Loan EMI: ";
	cin>>h_loan;
	cout<<"Total Personal Loan EMI: ";
	cin>>p_loan;
	cout<<"Number of cheque bounces in last six months: ";
	cin>>no_chq_bounce;
	cout<<"Own house? (y or n): ";
	cin>>own_house;
	cout<<"Spouse working? (y or n): ";
	cin>>spouse_working;
	cout<<"Dependent parents? (y or n): ";
	cin>>dependent_parents;
	cout<<"Company Tiers? (1, 2, 3): ";
	cin>>company_tier;
}
int applicant::calc_liability(){
	int score=0, liability;
	if(age>22 && age<=30){ score+=2; }
	else if(age>30 && age<=35){ score++; }
	else{ score--; }
	liability=h_loan+p_loan;
	if(liability<=m_sal/4){ score+=5; }
	if(liability>m_sal/4 && liability<=m_sal/3){ score+=3; }
	if(liability>m_sal/3 && liability<=m_sal/2){ score++; }
	if(liability>m_sal/2){ score--; }
	if(no_chq_bounce>1){ score-=2;	}
	if(no_chq_bounce==1){ score--;	}
	if(no_chq_bounce==0){ score++;	}
	if(p_loan>h_loan){ score--;	}
	else{ score++; }
	if(own_house=='y'){ score++; }
	if(spouse_working=='y'){ score++; }
	if(dependent_parents=='y'){ }
	else{ score++; }
	if(company_tier==1){ score+=3; }
	if(company_tier==2){ score+=2; }
	else{ score++; }
	return(score);
}
void applicant::display_score(){
	int sc=calc_liability();
	system("cls");
	if(sc>9){ cout<<"The applicant "<<name<<" is at low risk.\nCredit score = "<<sc<<"\nCredit can be given.";}
	else if(sc>5 && sc<=9){ cout<<"The applicant "<<name<<" is at average risk. \nCredit score = "<<sc<<"\nCredit can be given with due precaution.";}
	else{ cout<<"The epplicant "<<name<<" is at high risk.\nCredit score = "<<sc<<"\nCredit can not be given.";	}
	getch();
}

int main(){
	char flag='f', ch;
	applicant a;
	while(1){
		system("cls");
		gotoxy(31, 8);            cout<<"Credit CalC";
		gotoxy(26, 9);       cout<<"_____________________";
		gotoxy(22, 12);cout<<"1 - Enter loan applicant's details";
		gotoxy(22, 13);cout<<"2 - Display credit score";
		gotoxy(22, 14);cout<<"3 - Exit";
		gotoxy(22, 16);cout<<"Select an optino by typing the numeric codes: ";
		ch=getch();
		switch(ch){
			case('1'):{
				a.get_data();
				flag='t';
				break;
			}
			case('2'):{
				if(flag=='f'){
					gotoxy(22, 18);
					cout<<"Loan applicant's details not yet entered! Press any key to continue..";
					getch();
				}
				else{ a.display_score(); }
				break;
			}
			case('3'):{
				exit(1);
				break;
			}
			default:{
				gotoxy(22, 18);
				cout<<"Invalid Choice! press any key to continue..";
				break;
			}
		}
	}
	return 0;
}
