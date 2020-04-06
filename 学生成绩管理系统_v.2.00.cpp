#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
const int MAX_STUDENT_NUM=40;//测试时可以使用5
class Student
{
	public:
		Student(int I_id=0);//,char N_name,float R_regularGrade,float F_finalExam);
		void inputId();
		void inputName();
		void inputRegularGrade();
		void inputFinalExam();
		int getId(){return id;}
		static void heading(){cout<<"学号\t姓名\t平时\t期末\n";}
		void output();
		float calTotalMark();
	private:
		int id;
		char name[20];
		float regularGrade;
		float finalExam;
};
void Menu(int &num);
void Input(Student stu[],int &num);//输入数据 
void Output(Student stu[],int num);//输出数据 
void Statis(Student stu[],int num);//统计各分数段人数 
void Order(Student stu[],int num);//成绩由大到小排序 
void Search(Student stu[],int num);//查找分数 
void Insert(Student stu[],int &num);//插入 
void Delete(Student stu[],int &num);//删除  
int main()
{
	/*int n;
	cout<<"请输入学生人数: ";
	cin>>n;*/
	Student stu[MAX_STUDENT_NUM];//={100,92,90,87,68};
	//int currentN=0;
	int n=0;//取代currentN
	int num;
	while(1)
	{
		Menu(num);
		switch(num)
		{
			case 1:cout<<"您选择了1=录入学生\n";
				Input(stu,n);break;
			case 2:cout<<"您选择了2=显示信息\n";
				Output(stu,n);break;
			case 3:cout<<"您选择了3=排序总评\n";
				Order(stu,n);break;
			case 4:cout<<"您选择了4=查找学生\n";
				Search(stu,n);break;
			case 5:cout<<"您选择了5=插入学生\n";
				Insert(stu,n);break;
			case 6:cout<<"您选择了6=删除学生\n";
				Delete(stu,n);break;
			case 7:cout<<"您选择了7=统计人数\n";
				Statis(stu,n);break;
			case 0:return 0;
			default :cout<<"输入非法，请重新输入！\n"; 
		}
	}
	return 0;
}
void Menu(int &num)
{
	cout<<"      ========================================\n";
	cout<<"      =         欢迎使用成绩管理系统         =\n";
	cout<<"      =      1=录入学生     2=显示信息       =\n";
	cout<<"      =      3=排序总评     4=查找学生       =\n";
	cout<<"      =      5=插入学生     6=删除学生       =\n";
	cout<<"      =      7=统计人数     0=退出           =\n";
	cout<<"      ========================================\n";
	cout<<"请选择:";
	cin>>num;
}
Student::Student(int I_id)//,char N_name,float R_regularGrade,float F_finalExam)
{
	id=I_id;//regularGrade=0;finalExam=0;
}
void Student::inputId()
{
	int tid;
	while(1)
	{
		cout<<"请输入学号（1-40）之间：";
		cin>>tid;
		if(tid>=1&&tid<=40)
		{
			id=tid;break;
		}
		else
			cout<<"学号应在1~40之间！\n";
	}
}
void Student::inputName()
{
	cout<<"请输入姓名：";
	cin>>name; 
}
void Student::inputRegularGrade()
{
	while(1){
		cout<<"请输入平时成绩（0~100）：";
		cin>>regularGrade;
		if(regularGrade>=0&&regularGrade<=100)break;
		else cout<<"输入错误，成绩应该在0到100之间！\n";
	}
}
void Student::inputFinalExam()
{
	while(1){
		cout<<"请输入期末考试成绩（0~100）：";
		cin>>finalExam;
		if(finalExam>=0&&finalExam<=100)break;
		else cout<<"输入错误，成绩应该在0到100之间！\n";
	}
}
void Student::output()
{
	cout<<id<<"\t"<<name<<"\t"
	<<fixed<<setprecision(1)<<regularGrade<<"\t"
	<<fixed<<setprecision(1)<<finalExam<<endl;
}
float Student::calTotalMark()
{
	return regularGrade*0.5+finalExam*0.5;
}
void Input(Student stu[],int &num)
{
	if(num>=MAX_STUDENT_NUM)
		cout<<"人数已达到"<<MAX_STUDENT_NUM<<"人上限，无法再输入！\n";
	else
	{
		int i=0;//暂时用i代替num 
		for(i;i<MAX_STUDENT_NUM;i++)
		{
			stu[i].inputId();
			int j=0;
			for(j;j<i;j++)
				if(stu[i].getId()==stu[j].getId())break;
			if(j==i)
			{
				stu[i].inputName();
				stu[i].inputRegularGrade();
				stu[i].inputFinalExam();
				cout<<"继续输入学生数据请按y或Y: ";
				char ch='a';
				cin>>ch;
				if(ch=='y'||ch=='Y');
				else break; 
			}
			else{
			cout<<"学号不允许重复，该学号已经存在！\n";
			i--;	
			}
			if(i==MAX_STUDENT_NUM-1)
				cout<<"人数已达到"<<MAX_STUDENT_NUM<<"人上限，无法再输入！\n";
		}
		num=0;
		for(int j=0;j<MAX_STUDENT_NUM;j++)
			if(stu[j].getId()!=0)num++; //获得num 
	}
}
void Output(Student stu[],int num)
{
	Student::heading();
	for(int i=0;i<num;i++)
	if(stu[i].getId()!=0)stu[i].output();
	cout<<endl;
}
void Order(Student stu[],int num)
{
	for(int i=1;i<num;i++)
		for(int j=0;j<num-i;j++)
			if(stu[j].calTotalMark()<stu[j+1].calTotalMark())
				swap(stu[j],stu[j+1]);
	Output(stu,num);
}
void Search(Student stu[],int num)
{
	int cId;
 	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		cout<<"请输入您要查找的学号：";
		cin>>cId;
		int i=0;
		for(i;i<num;i++)
			if(cId==stu[i].getId())
			{
				Student::heading();
				stu[i].output();
				break;
			}
		if(i==num)
			cout<<"没有该学生的信息！\n";
		cout<<"继续查找请按y或Y:";
		cin>>ch;
	}
}
void Insert(Student stu[],int &num)
{
	int i=0;
	Student sin;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		if(num>=MAX_STUDENT_NUM){
			cout<<"人数已达到上限！\n";break; 
		}
		sin.inputId();
		for(i=0;i<num;i++)
			if(sin.getId()==stu[i].getId())break;
		if(i==num)
		{
			sin.inputName();
			sin.inputRegularGrade();
			sin.inputFinalExam();
			stu[num++]=sin;
			cout<<"成功插入！\n继续插入请按y或Y:";
		}
		else
			cout<<"学号不允许重复，该学号已经存在！\n继续插入请按y或Y:";
		cin>>ch;
	}
}
void Delete(Student stu[],int &num) 
{
	int del;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		cout<<"当前人数:"<<num<<endl;
		int i=0;
		if(num==0)
		{
			cout<<"没有学生可删！\n";break;
		}
		else
		{
			cout<<"请输入要删除的学生学号：";
			cin>>del;
			int i=0;
			for(i;i<num;i++)
				if(stu[i].getId()==del)
				{
					for(int k=i;k<num;k++)
						stu[k]=stu[k+1];
					num--;
					cout<<del<<"号学生信息删除成功！\n";
					break; 
				}
			if(i>=num)
			{
				cout<<"没有该学号学生！\n";
			}
			cout<<"继续删除其他学生请按y或Y：";
			cin>>ch;
		}	
	}
}
void Statis(Student stu[],int num)
{
	cout<<"100~90\t89~80\t79~70\t69~60\t<60\n";
	int a=0,b=0,c=0,d=0,e=0;
	for(int j=0;j<num;j++)
	{
		if(stu[j].getId()!=0)
			if(stu[j].calTotalMark()>=90&&stu[j].calTotalMark()<=100)a++;
			else if(stu[j].calTotalMark()>=80&&stu[j].calTotalMark()<90)b++;
			else if(stu[j].calTotalMark()>=70&&stu[j].calTotalMark()<80)c++;
			else if(stu[j].calTotalMark()>=60&&stu[j].calTotalMark()<70)d++;
			else e++; 
	}
	cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\n";
}
