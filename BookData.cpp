//
// Created by Lenovo on 24-12-17.
//

#include "BookData.h"

#include <iostream>
#include <ostream>
#include <string>
extern bool isempty(int);
extern BookData books[50];
std::string operator+(const std::string& a,int b)
{
    std::string s=a;
    s[s.length()-1]+=b;
    if (s[s.length()-1]>'9')
    {
        s[s.length()-1]=s[s.length()-1]-10;
        s[s.length()-2]+=1;
    }
    return s;
}//字符串加int自动加在最后一位,可进1位
BookData::BookData()
{
    this->isexist=false;//初始化认为书不存在
};
//~BookData()=default;
void BookData::setTitle(std::string& title)
{
    if (!doubleused_title(title))
    this->booktitle =title;
    else
        std::cout << "Title already set!" << std::endl;
}
void BookData::setAuthor(std::string& author)
{
    this->bookAuthor = author;
}
void BookData:: setQty(int qty)
{
    this->QtyOnHand = qty;
}
void BookData:: setISBN(std::string& isbn)
{
    std::string s=(isbn+1);
    if (!doubleused_isbn(isbn))
    this->isbn=isbn;//
    else
        BookData::setISBN(s);
}
void BookData:: setRetail(double retail)
{
    this->Retail = retail;
}

std::string BookData:: bookTitle(void)
{
    return booktitle;
}
char BookData:: bookTitle(int i)
{
    return booktitle[i];
}
std::string BookData:: ISBN(void)
{
    return isbn;
}
std::string BookData:: bookauthor(void)
{
    return bookAuthor;
}
int BookData:: qtyOnHand(void)
{
    return QtyOnHand;
}
double BookData:: retail(void)
{
    return this -> Retail;
}
bool doubleused_title(std::string& a)
{
    int i=0;
    while(!isempty(i))
    {
        if (books[i].bookTitle() == a)
        {
            break;
        }
        i++;
    }
    return books[i].isexist;
}

bool doubleused_isbn(std::string& a)
{
    int i=0;
    while(!isempty(i))
    {
        if (books[i].ISBN() == a)
        {
            break;
        }
        i++;
    }
    return books[i].isexist;
}