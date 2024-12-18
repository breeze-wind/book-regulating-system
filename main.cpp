#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "BookData.h"
#include <windows.h>
using namespace std;

BookData books[50];//书库容器
bool isempty(int i)
{
 if (books[i].bookTitle(0)=='\0')
 {return true;}
	return false;
}//判断文件名第一个字符空不空，空说明未曾写入（与isexist不同）
void LookUpBook(void);//输出相应提示词，存书名并调lookupbook（string）
void blockchoose(void);//主页面模块选择
void bookfile_managing(void);//书库信息管理
void deleteBook(void);//书记删除
void addBook(void);//添加书籍
void Edit_Book(void);//书籍信息编辑
void LookUpBook(string);//查找书名并调用bookinfo
void Bookinfo(BookData&);//书籍信息展示
void cash_managing(void);//收银模块
void sheeting(void);//报表模块
void system_exit(void);//退出并记录在书库文件
void pause(void);//按下任意键继续
void Edit_Book(BookData&);
bool make_sure(void);//输入1返回1
void read_file(void);//读取书库

BookData operator -(BookData& book,int a);



//---------------------------------------------------------

int main()
{
	SetConsoleOutputCP(CP_UTF8);
 //BookData books[200];//书库容器
	read_file();

    blockchoose();//进入模块选择
    
}
void addBook(void)
{string a;
	cout<<"想加哪本书，输入书名：";
	cin>>a;//存一下书名
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
		books[i].setTitle(a);
		string isbn=(books[i-1].ISBN())+1;
		books[i].setISBN(isbn);
		cout<<"输入作者：";
		cin>>a;//正好string再存一下作者
		books[i].setAuthor(a);
		cout<<"\n输入售价：";
		double sj;
		cin>>sj;
		books[i].setRetail(sj);
		books[i].isexist=true;
		cout<<"有几本？";
		int qty;
		cin>>qty;
		books[i].setQty(qty);
		pause();
		bookfile_managing();
	}
  else
  {
  	cout<<"已经有这本书了"<<endl;
  	Bookinfo(books[i]);
  	pause();
  	bookfile_managing();
  }
}
void deleteBook()
{
	cout<<"要删除哪本书？"<<endl;
	string a;
	cin>>a;
	int i=0;
	while(!isempty(i))
	{
		if (books[i].bookTitle() == a)
		{
			break;
		}
		i++;
	}
	if (books[i].isexist)
	{
		Bookinfo(books[i]);
		cout<<"确认删除这本书吗"<<endl;
		if (make_sure())
		books[i].isexist=false;
		else
		{
			cout<<"已取消删除"<<endl;
		}

	}
	else
	{
		cout<<"书库里没有这本书"<<endl;

	}
	pause();
	bookfile_managing();
}

void Edit_Book(void)
{
	cout<<"要编辑哪本书？"<<endl;
    string a;
	cin>>a;
	int i=0;
	while(!isempty(i))
	{
		if (books[i].bookTitle() == a)
		{
			break;
		}
		i++;
	}
	if (books[i].isexist)
	{
		Bookinfo(books[i]);
		cout<<"确认修改这本书吗"<<endl;
		if (make_sure())
		{
			Edit_Book(books[i]);
		}
	}
	else
	{
		cout<<"书库里没有这本书"<<endl;
		pause();
		bookfile_managing();
	}
}
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
	ofstream fout("D://code//clion//book regulating system//bookfile.txt");
	if (!fout)
	{
		cout<<"读取书库失败,无法保存书库修改"<<endl;
		blockchoose();
		return;
	}
	int i=0;
	fout<<"书名\tisbn\t\t作者\t库存\t售价"<<endl;
	while (books[i].isexist)
	{

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
	while(a<"1"||a>"4")
	{
		cout<<"error:请输入1-4内数字"<<endl;
		cin>>a;

	}
	switch(a[0])
	{
	case '1':
		cash_managing();
		break;
	case '2':
		bookfile_managing();
		break;
	case '3':
		//sheeting();
			break;
	case '4':
		system_exit();
			break;
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
	if (b>=books[i].qtyOnHand())
	{
		cout<<"库存不足T_T看看别的？"<<endl;
		cash_managing();
		return;
	}
	double b1 = b*(books[i].retail());
	cout<<"\t"<<books[i].ISBN()<<"\t"<<books[i].bookTitle()<<"\t"<<books[i].retail()<<"元\t"<<b1<<"元\t"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"销售合计:RMB "<<b1<<endl;
	cout<<"零售税"<<fixed<<setprecision(2)<<b1*0.06<<endl;
	cout<<"应付金额"<<fixed<<setprecision(2)<<b1*1.06<<endl;
	cout<<"\n\n谢谢光临！";
	books[i]-b;
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
// void sheeting(void)//报表模块
// {
// 	 cout<<"\t\t\tnuaa图书管理系统\t\t\n\t\t\t报表模块\t\t\n\n1.书库列表\n2.零售价列表\n3.返回到主菜单"<<endl;
// 	 cout<<"输入选择";
// 	 int a=0;
// 	 cin>>a;
// 	 switch(a)
// 	 {
// 	 	case 1:
// 	 }
//
// }

void bookfile_managing(void)
{
     cout<<"\t\t\tnuaa图书管理系统\t\t\n\t\t\t 书库管理模块\t\t\n\n1.查找某本书的信息\n2.增加书\n3.修改书的信息\n4.删除书\n5.返回到主菜单"<<endl;
	 cout<<"输入选择";
	 int a=0;
	 cin>>a;
	 switch(a)
	 {
	 	case 1:LookUpBook();
	 	break;
	 	case 2:addBook();
	 	break;
	 	case 3:Edit_Book();
	 	break;
	 	case 4:deleteBook();
	 	break;
	 	case 5:blockchoose();
	 	break;
	 	default:cout<<"error：请输入1-5之间的数"<<endl;
	 	a=0;
	 	pause();
	 	bookfile_managing();
	 	return;
	 }


}//书库管理系统
bool make_sure(void)
{
	string a;
	cout<<"输入1代表确认"<<endl;

	cin>>a;
	if (a=="1")
		return 1;
	else return 0;
}
void Edit_Book(BookData& book)
{
	cout<<"\n\t书籍编辑界面\t\n1.修改标题\n2.修改isbn\n3.修改作者\n4.修改售价\n5.修改库存\n6.返回上一级"<<endl;
	string a;
	cin>>a;
	string b;
	switch(a[0])
	{
	case '1':
		   cout<<"原标题："<<book.bookTitle()<<endl;
		   cout<<"请输入修改后的标题"<<endl;
		   ;
		   cin>>b;
		   book.setTitle(b);
		   cout<<"已修改标题为"<<book.bookTitle()<<endl;
		  break;
	case '2':
		cout<<"原isbn："<<book.ISBN()<<endl;
		cout<<"请输入修改后的isbn"<<endl;

		cin>>b;
		book.setISBN(b);
		cout<<"已修改isbn为"<<book.ISBN()<<endl;
		break;

	case '3':
		cout<<"原作者："<<book.bookauthor()<<endl;
		cout<<"请输入修改后的作者"<<endl;
		cin>>b;
		book.setAuthor(b);
		cout<<"已修改作者为"<<book.bookauthor()<<endl;
		break;
	case '4':
		cout<<"原售价："<<book.retail()<<endl;
		cout<<"请输入修改后的售价"<<endl;
		double c;
		cin>>c;
		book.setRetail(c);
		cout<<"已修改售价为"<<book.retail()<<endl;
		break;
    case '5':
    	bookfile_managing();
		return;
	case '6':
		break;
	default:
		cout<<"请输入1-5之间数“"<<endl;
		break;
	}
	pause();
	//system("clear");
	Edit_Book(book);
	return;
}
BookData operator -(BookData& book,int a)
{
	book.setQty(book.qtyOnHand()-a);
	if (book.qtyOnHand()<=0)
	{
		book.isexist=false;
		//book.bookTitle[0]='\0';
	}
	return book;
}
void read_file(void)
{
	string title;
	string author;
	int qtyOnHand;
	double retail;
	string isbn;
	ifstream basic_ifstream("D://code//clion//book regulating system//bookfile.txt");
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
}
