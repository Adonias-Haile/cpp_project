#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>//used to set the width
using namespace std;
void register_student_info();
void view_grade_report();
struct student
 {
 string fname,lname;
 string letterGrade;
 string id;
 string sub;//subject

 //int id;
 double numGrade;
 double mark;
 int cp;
 };
struct student subject;
int main()
 {
 int k;
 start:
 system("cls");// to clear the screen
 cout<<"\n\t ____________________________________________________";
 cout<<"\n\t| STUDENT REPORT MANAGEMENT SYSTEM  |";
 cout<<"\n\t|____________________________________________________|";
 a:cout<<"\n\t| Press [1] To write student data into file |";
 cout<<"\n\t| Press [2] To generate student grade report|";
 cout<<"\n\t| Press [3] To exit|";
 cout<<"\n\t|____________________________________________________|\n";
 cin>>k;
 switch(k)
 {
 case 1:
    register_student_info();
    break;
 case 2:
    view_grade_report();
     break;
 case 3:
    _exit(0);
    break;
 default:
    cout<<"please enter a valid input!!!"<<endl;
    goto a;
 }
 char ch;
	  cout<<"\n\n\t\tPress [A or a] to continue\n";
	  cout<<"\t\tPress [any key] to close\n";
	  cin>>ch;
	  if(ch=='A'||ch=='a')
	  {
	  goto start;
	  }
	  else
	  {
	      _exit(0);
	  //clrscr();
	  }
 return 0;
 }
void register_student_info()
 {
int st;
do// to insert students until we finish
{
  cout<<"enter Student ID number"<<endl;
  cin>>subject.id;
  cout<<"enter First_name"<<endl;
  cin>>subject.fname;
  cout<<"enter Last name"<<endl;
  cin>>subject.lname;
  int s;
  do// to insert the total subject that taken by the student
  {
 cout<<"enter the subject that has taken by registered student \t"<<endl;
  cin>>subject.sub;
  cp1: cout<<"enter the credit point of the subject \t"<<endl;
  cin>>subject.cp;
  if(subject.cp<1)
  {
      goto cp1;
  }
  g:cout<<"enter the mark scored by the registered student \t"<<endl;
  cin>>subject.mark;
  if(subject.mark>=90&&subject.mark<=100)
  {
  subject.letterGrade="A+";
  subject.numGrade=4.0;
	}
  else if(subject.mark>=85&&subject.mark<90)
	{
  subject.letterGrade="A";
  subject.numGrade=4.0;
	}
	else if(subject.mark>=80&&subject.mark<85)
  {
  subject.letterGrade="A-";
  subject.numGrade=3.75;
	}
		else if(subject.mark>=75&&subject.mark<80)
  {
  subject.letterGrade="B+";
  subject.numGrade=3.5;
	}
		else if(subject.mark>=70&&subject.mark<75)
  {
  subject.letterGrade="B";
  subject.numGrade=3.0;
	}
	else if(subject.mark>=65&&subject.mark<70)
  {
  subject.letterGrade="B-";
  subject.numGrade=2.75;
	}
  else if(subject.mark>=60&&subject.mark<70)
  {
  subject.letterGrade="C+";
  subject.numGrade=2.5;
	}
	else if(subject.mark>=50&&subject.mark<60)
  {
  subject.letterGrade="C";
  subject.numGrade=2.0;
	}
	else if(subject.mark>=45&&subject.mark<50)
  {
  subject.letterGrade="C-";
  subject.numGrade=1.75;
	}
	else if(subject.mark>=40&&subject.mark<45)
  {
  subject.letterGrade="D";
  subject.numGrade=1.0;
	}
  else if(subject.mark>=30&&subject.mark<40)
  {
  subject.letterGrade="Fx";
  subject.numGrade=0.0;
	}
	else if(subject.mark>=0&&subject.mark<30)
  {
  subject.letterGrade="F";
  subject.numGrade=0.0;
	}
	else
	{
	    cout<<"Invalid Entry\n";
	    goto g;
	}
  ofstream report;
  report.open("greport.doc",ios::out|ios::app);
  report<<subject.id<<"\t"<<subject.fname<<"\t"<<subject.lname<<"\t"<<subject.sub<<"\t"<<subject.mark<<"\t"<<subject.letterGrade<<"\t"<<subject.numGrade<<"\t"<<subject.cp<<endl;
   report.close();
 cout<<"\n\t|____________________________________________________|";
 cout<<"\n\t| Press [1] To register other subject taken by this student |";
 cout<<"\n\t| Press [any key] To stop subject registration|";
 cout<<"\n\t|____________________________________________________|\n";
 cin>>s;
  }
while(s==1);
 cout<<"\n\t|____________________________________________________|";
 cout<<"\n\t| Press [1] To register other student information |";
 cout<<"\n\t| Press [any key] To stop student registration|";
 cout<<"\n\t|____________________________________________________|\n";
 cin>>st;
}
  while(st==1);
  }
 void view_grade_report()
  {
  string roll;
  cout<<"\tenter the student id number\n";
  cin>>roll;
	ifstream report1;
	report1.open("greport.doc");
int j=0;
 float c_result=0,total_c_result=0,tcp=0,gpa=0;
 while(report1>>subject.id>>subject.fname>>subject.lname>>subject.sub>>subject.mark>>subject.letterGrade>>subject.numGrade>>subject.cp)
	{
	    if(subject.id==roll)
        { if(j==0)
           { //cout<<j;

             cout<<"\n ______________________________________________________________________";
             cout<<"\n STUDENT ID:"<<subject.id;
             cout<<"\n STUDENT NAME:"<<subject.fname<<" "<<subject.lname;
             cout<<"\n_______________________________________________________________________";
             cout<<"\n subject"<<setw(15)<<"mark"<<setw(15)<<"Lgrade"<<setw(15)<<"Ngrade"<<setw(15)<<"CP\n";
	         cout<<"   |"<<setw(15)<<" |"<<setw(15)<<" |"<<setw(15)<<"|"<<setw(15)<<" "<<setw(15)<<"\n"<<endl;
           }

               // cout<<j;
        cout<<"  "<<subject.sub<<"\t\t"<<subject.mark<<"\t\t"<<subject.letterGrade<<"\t\t"<<subject.numGrade<<"\t\t"<<subject.cp<<endl;
        c_result=subject.cp*subject.numGrade;
        total_c_result=c_result+total_c_result;
        tcp=subject.cp+tcp;
        j++;
       }
       else
       {
           continue;
       }

    }
  gpa=total_c_result/tcp;
  cout<<"\n_______________________________________________________________________";
  cout<<"\n comulative GPA of the student:"<<gpa;
  cout<<"\n_______________________________________________________________________"<<endl;
  report1.close();
  }

