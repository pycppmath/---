#include<iostream>
#include<iomanip>
using namespace std;
const int MAX_STUDENT_NUM=5;//����ʱ����ʹ��5
void Menu(int &num);
void Input(float stu[],int &num);//�������� 
void Output(float stu[],int num);//������� 
void Statis(float stu[],int num);//ͳ�Ƹ����������� 
void Order(float stu[],int num);//�ɼ��ɴ�С���� 
void Search(float stu[],int num);//���ҷ��� 
void Insert(float stu[],int &num);//���� 
void Delete(float stu[],int &num);//ɾ�� 
int main()
{
	//int n;
	//cout<<"������ѧ������: ";
	//cin>>n;
	int n=0;//ȡ��currentN 
	float stu[MAX_STUDENT_NUM];//92,100,90,68,87};
	//int currentN=0;
	int num;
	while(1)
	{
		Menu(num);
		switch(num)
		{
			case 1:cout<<"��ѡ����1=¼��ѧ��\n";
				Input(stu,n);break;
			case 2:cout<<"��ѡ����2=��ʾ��Ϣ\n";
				Output(stu,n);break;
			case 3:cout<<"��ѡ����3=��������\n";
				Order(stu,n);break;
			case 4:cout<<"��ѡ����4=����ѧ��\n";
				Search(stu,n);break;
			case 5:cout<<"��ѡ����5=����ѧ��\n";
				Insert(stu,n);break;
			case 6:cout<<"��ѡ����6=ɾ��ѧ��\n";
				Delete(stu,n);break;
			case 7:cout<<"��ѡ����7=ͳ������\n";
				Statis(stu,n);break;
			case 0:return 0;
			default :cout<<"����Ƿ������������룡\n"; 
		}
	}
	return 0;
}
void Menu(int &num)
{
	cout<<"      ========================================\n";
	cout<<"      =         ��ӭʹ�óɼ�����ϵͳ         =\n";
	cout<<"      =      1=¼��ѧ��     2=��ʾ��Ϣ       =\n";
	cout<<"      =      3=��������     4=����ѧ��       =\n";
	cout<<"      =      5=����ѧ��     6=ɾ��ѧ��       =\n";
	cout<<"      =      7=ͳ������     0=�˳�           =\n";
	cout<<"      ========================================\n";
	cout<<"��ѡ��:";
	cin>>num;
}
void Input(float stu[],int &num)
{
	char ch='y';
	while(num<MAX_STUDENT_NUM&&(ch=='y'||ch=='Y'))
	{
		int tmp=0;
		cout<<"������ɼ�(0~100): ";
		cin>>tmp;
		if(tmp>=0&&tmp<=100)
		{
			stu[num++]=tmp;
			cout<<"��������ѧ�������밴y��Y: ";
			cin>>ch;
		}
		else{
			cout<<"������󣬳ɼ�Ӧ����0��100֮�䣡\n";
			num--;
		}
	}
	if(num>=MAX_STUDENT_NUM)
	cout<<"�����Ѵﵽ"<<MAX_STUDENT_NUM<<"�����ޣ��޷������룡\n"; 
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
	cout<<"�ɼ���Ϣ���£�\n";
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
			cout<<"�����Ѵﵽ���ޣ�\n";break; 
		}
		cout<<"���������ɼ���0~100����";
		cin>>in;
		if(in<=100&&in>=0)
		{
			stu[num++]=in;
			cout<<"�ɹ����룡\n���������밴y��Y:";
			cin>>ch;
		}
		else
		{
			cout<<"������󣬳ɼ�Ӧ����0��100֮�䣡\n���������밴y��Y:";
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
		cout<<"��������Ҫ���ҵĳɼ���";
		cin>>score; 
		h=0;b=num-1;
		while(h<=b)
		{
			m=(h+b)/2;
			if(score==stu[m])
			{
				cout<<"���ҵ���һ������ɼ���"<<stu[m]<<endl;
				cout<<"���������밴y��Y:";cin>>ch;break; 
			}
			if(score>stu[m])b=m-1;
			if (score<stu[m])h=m+1;
		}
		if(h>b)
		{
			cout<<"û�и�ѧ������Ϣ��\n";
			cout<<"���������밴y��Y:";
			cin>>ch;
		/*	if(ch=='y'||ch=='Y')
			{
				h=0;
				b=num-1;
				cout<<"��������Ҫ���ҵĳɼ���";
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
		cout<<"��ǰ����:"<<num<<endl;
		int i=0;
		if(num==0)
		{
			cout<<"û��ѧ����ɾ��\n";break;
		}
		else
		{
			cout<<"������Ҫɾ���ĳɼ���";
			cin>>del;
			for(i=0;i<num;i++)
			if(stu[i]==del)
			{
				for(int k=i;k<num;k++)
					stu[k]=stu[k+1];
				num--;
				cout<<del<<"��ѧ����Ϣɾ���ɹ���\n"; 
				break; 
			}
			if(i>=num)
			{
				cout<<"û�и�ѧ����\n";
			}
			cout<<"����ɾ������ѧ���밴y��Y��";
			cin>>ch;
		}
	}
}
