//
// Created by Lenovo on 24-12-18.
//

#include "system.h"
#include "sheeting.h"
#include<iostream>
#include"bookfile_managing.h"
using std::string;
using std::cout;
using std::endl;
using std::cin;
bool isempty(int i)
{
	if (books[i].bookTitle(0)=='\0')
	{return true;}
	return false;
}//判断文件名第一个字符空不空，空说明未曾写入（与isexist不同）
void LookUpBook(void)
{
	cout<<"输入书名"<<endl;
	string title;
	cin>>title;
	LookUpBook(title);
	pause();
	bookfile_managing();
	return;
}
void system_exit(void)
{
	std::ofstream fout("D://code//clion//book regulating system//bookfile.txt");
	if (!fout)
	{
		cout<<"读取书库失败,无法保存书库修改"<<endl;
		blockchoose();
		return;
	}
	int i=0;
	fout<<"书名\tisbn\t\t作者\t库存\t售价"<<endl;
	while (books[i].isexist||!isempty(i))
	{
        if (books[i].isexist)
		fout<<books[i].bookTitle()<<"\t"<<books[i].ISBN()<<"\t"<<books[i].bookauthor()<<"\t"<<books[i].qtyOnHand()<<"\t"<<books[i].retail()<<endl;
		i++;
	}
	fout.close();

}//把程序里的再写进文件，并结束
void blockchoose()
{
	cout<<"\t nuaa图书管理系统\t\n"<<"主菜单"<<endl<<"1.收银模块"<<endl<<"2.书库管理模块"<<endl<<"3.报表模块"<<endl<<"4.退出系统"<<endl;
	cout<<"请输入1-4内数字来选择"<<endl;
	string a;
	cin>>a;
	switch(a[0])
	{
	case '1':
		cash_managing();
		break;
	case '2':
		bookfile_managing();
		break;
	case '3':
		Sheeting();
			break;
	case '4':
		system_exit();
			break;
		default:
			cout<<"error:请输入1-4内数字"<<endl;
		pause();
		blockchoose();
		return;

	}

}//
void pause(void)
{
	cout<<endl;
	system("pause");
}

void cash_managing(void)
{

	string a;//isbn
	int b=0;//数量
	cout<<"\t前台销售模块\t"<<endl;
	cout<<"输入想买的书ISBN"<<endl;
	cin>>a;
	int i;
	i = 0;
	while(!isempty(i))
	{
		if (books[i].ISBN()==a)
		{break;}
		i++;
	}\
	if (isempty(i))
	{
		cout<<"书库里没有这本书"<<endl;
		pause();
		blockchoose();
	}
	if (!books[i].isexist)
	{
		cout<<"卖光了T_T  看看别的吧"<<endl;
		 pause();
		blockchoose();
		return;
	}
	cout<<"日期："<<__DATE__<<endl;
	cout<<"库存数量\tISBN号\t书名\t单价"<<endl;
	cout<<books[i].qtyOnHand()<<"\t"<<books[i].ISBN()<<"\t"<<books[i].bookTitle()<<"\t"<<books[i].retail()<<"元\t"<<endl;
	cout<<"数量\tISBN号\t书名\t单价\t金额"<<endl;
	cin>>b;
	if (b<0)
	{
		cout<<"error:请输入正整数"<<endl;
		b=0;
		cash_managing();

	}
	if (b>books[i].qtyOnHand())
	{
		cout<<"库存不足T_T看看别的？"<<endl;
		cash_managing();
		return;
	}
	double b1 = b*(books[i].retail());
	cout<<"\t"<<books[i].ISBN()<<"\t"<<books[i].bookTitle()<<"\t"<<books[i].retail()<<"元\t"<<b1<<"元\t"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"销售合计:RMB "<<b1<<endl;
	cout<<"零售税"<<std::fixed<<std::setprecision(2)<<b1*0.06<<endl;
	cout<<"应付金额"<<std::fixed<<std::setprecision(2)<<b1*1.06<<endl;
	cout<<"\n\n谢谢光临！";
	books[i]-b;
	pause();
	 blockchoose();
}
void Bookinfo(BookData& book)
{
	cout<<"--------------------------------------------------------------------";
	cout<<"\n\tnuaa图书管理系统\t\n\t\t书的资料\t\nISBN号："<<book.ISBN()<<"\n书 名："<<book.bookTitle()<<"\n库存量："<<book.qtyOnHand()<<"\n零售价："<<book.retail()<<"\n作者："<<book.bookauthor()<<endl;
	cout<<"--------------------------------------------------------------------";
}
void LookUpBook(string a)
{
//	Bookinfo(books[0]);
	int i=0;
	while(!isempty(i))
	{
		if (books[i].bookTitle() == a)
		{
			break;
         	}
		i++;
	}
//	cout<<i<<endl;
	if (!books[i].isexist)
	{
		cout<<"没这本书0.0看看别的"<<endl;
		return;
	}//剩下的都是在馆的（理论上

	Bookinfo(books[i]);
}

bool make_sure(void)
{
	string a;
	cout<<"输入1代表确认"<<endl;

	cin>>a;
	if (a=="1")
		return 1;
	else return 0;
}//输入1确认

BookData operator -(BookData& book,int a)
{
	book.setQty(book.qtyOnHand()-a);
	if (book.qtyOnHand()<=0)
	{
		book.isexist=false;
		//book.bookTitle[0]='\0';
	}
	return book;
}//库存减少
void read_file(void)
{
	string title;
	string author;
	int qtyOnHand;
	double retail;
	string isbn;
	std::ifstream basic_ifstream("D://code//clion//book regulating system//bookfile.txt");
	int i=0;
	if (!basic_ifstream)
	{
		cout<<"读取书库失败"<<endl;
		return ;
	}getline(basic_ifstream,title);
	while (basic_ifstream>>title>>isbn>>author>>qtyOnHand>>retail)
	{
		books[i].setTitle(title);
		books[i].setAuthor(author);
		books[i].setQty(qtyOnHand);
		books[i].setISBN(isbn);
		books[i].setRetail(retail);
		books[i].isexist=true;
		i++;
	}//读取书库
	basic_ifstream.close();//关闭文件输入流
}//读取书库
