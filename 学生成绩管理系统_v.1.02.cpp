#include<iostream>
#include<iomanip>
using namespace std;
const int MAX_STUDENT_NUM=5;//测试时可以使用5
void Menu(int &num);
void Input(float stu[],int &num);//输入数据 
void Output(float stu[],int num);//输出数据 
void Statis(float stu[],int num);//统计各分数段人数 
void Order(float stu[],int num);//成绩由大到小排序 
void Search(float stu[],int num);//查找分数 
void Insert(float stu[],int &num);//插入 
void Delete(float stu[],int &num);//删除 
int main()
{
	//int n;
	//cout<<"请输入学生人数: ";
	//cin>>n;
	int n=0;//取代currentN 
	float stu[MAX_STUDENT_NUM];//92,100,90,68,87};
	//int currentN=0;
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
void Input(float stu[],int &num)
{
	char ch='y';
	while(num<MAX_STUDENT_NUM&&(ch=='y'||ch=='Y'))
	{
		int tmp=0;
		cout<<"请输入成绩(0~100): ";
		cin>>tmp;
		if(tmp>=0&&tmp<=100)
		{
			stu[num++]=tmp;
			cout<<"继续输入学生数据请按y或Y: ";
			cin>>ch;
		}
		else{
			cout<<"输入错误，成绩应该在0到100之间！\n";
			num--;
		}
	}
	if(num>=MAX_STUDENT_NUM)
	cout<<"人数已达到"<<MAX_STUDENT_NUM<<"人上限，无法再输入！\n"; 
}
void Output(float stu[],int num)
{
	for(int i=0;i<num;i++)
	cout<<" "<<fixed<<setprecision(1)<<stu[i];
	cout<<endl;
}
void Statis(float stu[],int num)
{
	cout<<"100~90\t89~80\t79~70\t69~60\t<60\n";
	int a=0,b=0,c=0,d=0,e=0;
	for(int j=0;j<num;j++)
	{
		if(stu[j]>=90&&stu[j]<=100)a++;
		else if(stu[j]>=80&&stu[j]<90)b++;
		else if(stu[j]>=70&&stu[j]<80)c++;
		else if(stu[j]>=60&&stu[j]<70)d++;
		else e++;
	}
	cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\n";
}
void Order(float stu[],int num)
{
	for(int i=1;i<num;i++)
		for(int j=0;j<num-i;j++)
			if(stu[j]<stu[j+1])
			{
				float t=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=t;
			}
	cout<<"成绩信息如下：\n";
	for(int i=0;i<num;i++)
		cout<<setw(6)<<fixed<<setprecision(1)<<stu[i];
	cout<<endl;
}
void Insert(float stu[],int &num)
{
	float in;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		if(num>=MAX_STUDENT_NUM){
			cout<<"人数已达到上限！\n";break; 
		}
		cout<<"请输入插入成绩（0~100）：";
		cin>>in;
		if(in<=100&&in>=0)
		{
			stu[num++]=in;
			cout<<"成功插入！\n继续插入请按y或Y:";
			cin>>ch;
		}
		else
		{
			cout<<"输入错误，成绩应该在0到100之间！\n继续插入请按y或Y:";
			cin>>ch;
		}
	}
}
void Search(float stu[],int num)
{
	int score;
	for(int i=1;i<num;i++)
		for(int j=0;j<num-i;j++)
			if(stu[j]<stu[j+1])
			{
				float t=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=t;
			}
 	int h=0,b=num-1,m=0;
 	char ch='y';
	while(m>=0&&(ch=='y'||ch=='Y'))
	{
		cout<<"请输入您要查找的成绩：";
		cin>>score; 
		h=0;b=num-1;
		while(h<=b)
		{
			m=(h+b)/2;
			if(score==stu[m])
			{
				cout<<"查找到第一个相符成绩："<<stu[m]<<endl;
				cout<<"继续输入请按y或Y:";cin>>ch;break; 
			}
			if(score>stu[m])b=m-1;
			if (score<stu[m])h=m+1;
		}
		if(h>b)
		{
			cout<<"没有该学生的信息！\n";
			cout<<"继续输入请按y或Y:";
			cin>>ch;
		/*	if(ch=='y'||ch=='Y')
			{
				h=0;
				b=num-1;
				cout<<"请输入您要查找的成绩：";
				cin>>score;
			}*/
		}
	}
}
void Delete(float stu[],int &num)
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
			cout<<"请输入要删除的成绩：";
			cin>>del;
			for(i=0;i<num;i++)
			if(stu[i]==del)
			{
				for(int k=i;k<num;k++)
					stu[k]=stu[k+1];
				num--;
				cout<<del<<"分学生信息删除成功！\n"; 
				break; 
			}
			if(i>=num)
			{
				cout<<"没有该学生！\n";
			}
			cout<<"继续删除其他学生请按y或Y：";
			cin>>ch;
		}
	}
}
