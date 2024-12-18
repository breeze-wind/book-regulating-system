//
// Created by Lenovo on 24-12-18.
//

#ifndef SYSTEM_H
#define SYSTEM_H
#include<iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "BookData.h"
#include <windows.h>
extern BookData books[50];
BookData operator -(BookData& book,int a);
bool isempty(int a);
void LookUpBook(void);//输出相应提示词，存书名并调lookupbook（string）
void blockchoose(void);//主页面模块选择
void LookUpBook(std::string);//查找书名并调用bookinfo
void cash_managing(void);//收银模块
void system_exit(void);//退出并记录在书库文件
void pause(void);//按下任意键继续
void Edit_Book(const BookData&);
bool make_sure(void);//输入1返回1
void read_file(void);//读取书库


#endif //SYSTEM_H
