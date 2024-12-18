//
// Created by Lenovo on 24-12-18.
//

#include "sheeting.h"

#include <iostream>
#include <ostream>

#include "BookData.h"
extern void blockchoose(void);//主页面模块选择
extern void pause(void);//按下任意键继续
extern BookData books[50];
const char* menu_insheeting="nuaa图书管理系统\n\t\t\t报表模块\n1.书库列表\n2.零售价列表\n3.返回到主菜单\n输入选择";
void Show_Menu_InSheeting(void)
{
    std::cout<<"\n"<<menu_insheeting<< std::endl;
}
void Sheeting(void)
{
    Show_Menu_InSheeting();
    std::string a;
    std::cin>>a;
   switch(a[0])
   {
       case '1':
           BookfileList();
           break;
       case '2':
           RetailList();
           break;
       case '3':
           //pause();
           blockchoose();
       break;
       default:std::cout<<"Wrong Input"<<std::endl;
       blockchoose();
       break;
   }

}
void BookfileList(void)
{
    int i=0;
    std::cout<<"书名\tisbn\t\t作者\t库存\t售价"<<std::endl;
    while (books[i].isexist)
    {

        std::cout<<i+1<<"."<<books[i].bookTitle()<<"\t"<<books[i].ISBN()<<"\t"<<books[i].bookauthor()<<"\t"<<books[i].qtyOnHand()<<"\t"<<books[i].retail()<<std::endl;
        i++;
    }
    pause();
    Sheeting();
}
void RetailList(void)
{
    int i=0;
    std::cout<<"书名\t售价"<<std::endl;
    while (books[i].isexist)
    {

        std::cout<<i+1<<"."<<books[i].bookTitle()<<"\t"<<books[i].retail()<<std::endl;
        i++;
    }
    pause();
    Sheeting();
}
