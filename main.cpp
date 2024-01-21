#include <iostream>

// #include<stdio.h>  c++支持c语言的以.h结尾的头文件
using namespace std;  //命名空间

namespace std1  //作用：变量隔离
{
int a = 5;
void test()
{
    cout <<"1111" <<"要输出的内容2"<<endl<<10<<endl;   //c out可连续输出 endl回车换行
}
}

namespace std1  //同一个命名空间可以分开定义，会合并
{
int b = 5;
}

namespace std2
{
int a = 3;
}

struct str1
{   //相对于c,c++允许定义结构体中定义函数
    int a;
    void hello()
    {
        cout << "hello....."<<endl;

    };
};

void swap1(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
void swap2(int &a,int &b)
{
    int c;
    c=a;
    a=b;
    b=c;
}

int &add(int &a,int &b)
{
    static int c;  //引用的局部变量不能随着随着函数运行完消失，所以采用静态变量
    c=a+b;
    return c;
}

//宏定义
#define display(count){\
int i;\
    for(i=0;i<count;i++)\
    cout << i<< endl;\
}

//内联函数
inline void display1(int count){
    int i;
    for(i=0;i<count;i++)
        cout << i<< endl;
}

void regist(char *name,char *cls=(char*)"dz1b"){
    cout <<name<<endl<<cls<<endl;
}
//extern "C"   //在c++中用c的编译器，具体再学，没听懂

//程序唯一入口
int main()
{
    //    //1、命名空间中成员的引用
    //    std1::test();  //  ::作用域标识符
    //    cout <<std1::a<<endl;

    //    using namespace std1;  //引用命名空间，里面的东西可直接访问，但是可能会用冲突，不太安全
    //    cout <<a<<endl<<std2::a<<endl;

    //    //c out可连续输出，endl回车换行，可输出字符、数字、变量的值，都会转换成字符串输出
    //    cout <<"1111" <<"要输出的内容2"<<endl<<10<<endl;

    //    //cin输入
    //    int bca; //char等其他类型
    //    cin >> bca;
    //    cout<<bca<<endl;
    //    cout << bca<<"输入的是：";

    //    //结构体的引用
    //    str1 t;
    //    t.hello();


    //    //bool类型为一个字节占2位，true（值为一），false（值为零），赋其他值为一
    //    bool b;
    //    b=true;
    //    cout<<b<<endl<<sizeof(b);

    //    //引用  优点：相对于指针，别名不占内存，而且更安全
    //    int a=10,b=20;
    //    swap1(&a,&b); //c语言中取地址的方法
    //    cout <<"a="<<a<<endl<<"b="<<b<<endl;
    //    int &c=a; //引用，c是a的别名，同地址，定义时必须初始化（赋值）
    //    c=100;
    //    cout<<a<<endl<<&c<<endl<<&a<<endl;

    //    swap2(a,b);   //引用的方法
    //    cout<<a<<endl<<b<<endl;
    //    int &d = c;  //二次引用
    //    d=50;
    //    cout << a;

    //    //引用进阶
    //    int a=10,b=8;
    //    int &t=add(a,b);
    //    cout <<t;

    //    //常引用，一旦定义就不能修改
    //    const int &t=10;

    //    //宏定义，在预处理阶段完成，将定义的函数复制过来，而不用像定义函数那样需要先保存main函数数据再去调用子函数，减轻cpu负担；缺点：因为是复制，编译出来的程序大
    //    display(10);
    //    //内联函数，在编译阶段完成，宏定义的升级版,是不是内联函数有编译器决定，不是加了inline就是内联
    //    //不出现循环、递归调用、静态变量、对函数取地址、过多的条件判断语句，加了inline大多会编译成内联
    //    //内联函数要救比较简短
    //    display1(10);

    //    函数重载（重名），同函数名而参数位置、类型或数量不同，在c++中由函数名和参数共同标识一个函数，因编译时会根据参数类型和数量对函数名重命名。

    //    //函数的默认参数，有些大部分参数值都一样的情况下，我们可以使用默认参数老减少传参的工作量。
    //    regist((char*)"ds");   //可以省略的默认参数必须放在非默认参数后面，声明和定义都可以指定默认参数，但是不能同时指定默认参数。
    //    regist((char*)"ds",(char*)"dsds");  //自己指定参数
    //    //当省略默认参数的函数与重载函数重名，会不知道选哪个函数，应避免

    //    //占位参数void ere(int a ,int){},后面的参数没法使用，但是调用的时候要传入2个参数。
    //    //占位参数支持默认值，可以不传void ere(int a ,int =5){}   没有啥意义

    //    extetn "C"
}
