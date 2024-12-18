//
// Created by Lenovo on 24-12-18.
//

#include "bookfile_managing.h"
#include"system.h"
#include <iostream>
extern void pause(void);
extern BookData books[50];
extern bool make_sure(void);
using std::string;
using std::cout;
using std::endl;
using std::cin;

void addBook(void)
{
    std::string a;
    std::cout<<"想加哪本书，输入书名：";
    std::cin>>a;//存一下书名
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
        std::string isbn=(books[i-1].ISBN())+1;
        books[i].setISBN(isbn);
        std::cout<<"输入作者：";
        std::cin>>a;//正好string再存一下作者
        books[i].setAuthor(a);
        std::cout<<"\n输入售价：";
        double sj;
        std::cin>>sj;
        books[i].setRetail(sj);
        books[i].isexist=true;
        std::cout<<"有几本？";
        int qty;
        std::cin>>qty;
        books[i].setQty(qty);
        pause();
        bookfile_managing();
    }
    else
    {
        std::cout<<"已经有这本书了"<<std::endl;
        Bookinfo(books[i]);
        pause();
        bookfile_managing();
    }
}
void deleteBook()
{
    std::cout<<"要删除哪本书？"<<std::endl;
    std::string a;
    std::cin>>a;
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
        std::cout<<"确认删除这本书吗"<<std::endl;
        if (make_sure())
            books[i].isexist=false;
        else
        {
            std::cout<<"已取消删除"<<std::endl;
        }

    }
    else
    {
        std::cout<<"书库里没有这本书"<<std::endl;

    }
    pause();
    bookfile_managing();
}

void Edit_Book(void)
{
    std::cout<<"要编辑哪本书？"<<std::endl;
    std::string a;
    std::cin>>a;
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
        std::cout<<"确认修改这本书吗"<<std::endl;
        if (make_sure())
        {
            Edit_Book(books[i]);
        }
        else
            std::cout<<"已取消修改"<<std::endl;
    }
    else
    {
        std::cout<<"书库里没有这本书"<<std::endl;
        pause();
        bookfile_managing();
    }
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
        bookfile_managing();
        break;
    default:
        cout<<"请输入1-5之间数“"<<endl;
        break;
    }
    pause();
    Edit_Book(book);
    return;
}
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