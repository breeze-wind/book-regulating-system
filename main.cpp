#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
class BookData
{
public:
    BookData()
    {
        isexist=false;//初始化认为书不存在
    };
    //~BookData()=default;
    void setTitle(string& title)
    {
        this->booktitle =title;
    }
    void setAuthor(string& author)
    {
       this->bookAuthor = author;
    }
    void setQty(int qty)
    {
        this->QtyOnHand = qty;
    }
    void setISBN(string& isbn)
    {
            this->isbn=isbn;//
    }
    void setRetail(double retail)
    {
        this->Retail = retail;
    }
    bool isexist;//标记书存不存在（关系到最后要不要写回去） 
    string bookTitle(void)
    {
    	return booktitle;
	}
	char bookTitle(int i)
    {
    	return booktitle[i];
    }
	string ISBN(void)
    {
    	return isbn;
	}
	string bookauthor(void)
    {
	    return bookAuthor;
    }
	int qtyOnHand(void)
    {
	    return QtyOnHand;
    }
	double retail(void)
    {
	    return this -> Retail;
    }
private:
    string booktitle;
    string isbn;
    int QtyOnHand;
    double Retail;
    string bookAuthor;

};//定义书籍信息类
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
BookData books[50];//书库容器
bool isempty(int i)
{
 if (books[i].bookTitle(0)=='\0')
 {return true;}
	return false;
}
void lookUpBook(void);
void blockchoose(void);
void bookfile_managing(void);
void deleteBook(void);
void addBook(void);
void editBook(void);
void  lookUpBook(string);
void Bookinfo(BookData&);
void cash_managing(void);
void sheeting(void);
void system_exit(void);


string operator+(const string& a,int b)
{
	string s=a;
	s[s.length()-1]+=b;
	return s;
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
	while(isempty(i))
	{
		if (books[i].ISBN()==a)
			break;
		i++;
	}
	if (!books[i].isexist)
	{
		cout<<"卖光了T_T  看看别的吧"<<endl;
		 cash_managing();
		return;
	}
	cout<<"日期："<<__DATE__<<endl;
	cout<<"库存数量\tISBN号\t书名\t单价"<<endl;
	cout<<books[i].qtyOnHand()<<"\t"<<books[i].ISBN()<<"\t"<<books[i].bookTitle()<<"\t"<<books[i].retail()<<"元\t"<<endl;
	cout<<"数量\tISBN号\t书名\t单价\t金额"<<endl;
	cin>>b;
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
void lookUpBook(string a)
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
	 	case 1:lookUpBook();
	 	break;
	 	case 2:addBook();
	 	break;
	 	case 3:editBook();
	 	break;
	 	case 4:deleteBook();
	 	break;
	 	case 5:blockchoose();
	 	break;
	 	default:cout<<"error：请输入1-5之间的数"<<endl;
	 	bookfile_managing();
	 	return;
	 }
	  

}//书库管理系统 

int main()
{
 //BookData books[200];//书库容器
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
        return 0;
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
		bookfile_managing();
	}

}

void editBook(void)
{

}
void lookUpBook(void)
{
	cout<<"输入书名"<<endl;
	string title;
	cin>>title;
	lookUpBook(title);
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
	int a=0;
	cin>>a;
	while(a<1||a>4)
	{
		cout<<"error:请输入1-4内数字"<<endl;
		cin>>a;

	}
	switch(a)
	{
	case 1:
		cash_managing();
		break;
	case 2:
		bookfile_managing();
		break;
	case 3:
		//sheeting();
			break;
	case 4:
		system_exit();
			break;
	}

}//