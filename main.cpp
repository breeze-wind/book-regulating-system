
#include"system.h"
#include "bookfile_managing.h"
using namespace std;

BookData books[50];//书库容器
//---------------------------------------------------------

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	read_file();
    blockchoose();//进入模块选择
}

