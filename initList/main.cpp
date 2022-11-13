#include <iostream>

#ifndef C++11
#define C++11
#endif
#ifdef C++11
#define __cplusplus 201103L //C++11 标准定义
#endif
#ifdef C98
#define __cplusplus 199711L //C98/03标准定义
#endif

#include <list>
#include <vector>
#include "Test.h"
#include "Test2.h"
using namespace std;
//初始化列表做为参数测试
void initList(initializer_list<int> _init_list){
    for (auto item:_init_list) {
        cout<<item<<endl;
    }
}
//类对象做为引用测试
void func(const Test2&){

}
int main() {
    cout << "Hello, World!\n" << __cplusplus <<  endl;
    vector<list<int> > a;//支持所有C++版本
    vector<list<float>> b;//只支持C++11或者更高版本,C++11后去掉了空格
    string * c = nullptr;//空指针,指向一个空值,不会被转化为整数,取代0与NULL
    cout <<c<<endl;
    //类型自动推导,自动推导类型的对象必须初始化
    auto d = 999;//自动推导整形
    auto e = b;//自动推导vector<list<float>>
    static auto  PI = 3.141159;//添加额外的限定符指定为静态自动推导变量
    auto listIterator = a.begin();//自动推导迭代器
    //自动推导Lambda表达式
    auto lambda = [](int x)->int {
        return x * x;
    };
    //使用推导的Lambda表达式
    cout<<lambda(5)<<endl;
    //一致性初始化,使用{}进行初始化时会进行类型检查
    int intArray[] = {1,3,5,7,9};//初始化数组
    vector<int> g= {1,2,3,4,5};//初始化动态数组容器vector
    vector<string> h = {"hello","world"};//初始化动态数组容器vector
    int x;//x未定义,因为未初始化
    int y{};//y=0,因为y使用了{}进行类型初始化,int的默认值为0
    int* z;//z未定义,因为未指向任何内存地址
    int* z1{};//z1=nullptr,因为z1使用了{}进行了指针初始化,指向了一人nullptr空指针
    //int zz{1.0};//整形不能使用浮点类型来初始化,初始化类型检查时会报错的
    //非{}初始化,不会进行类型检查,会进行窄化,精度被降低
    int zzz = 8.9;//窄化后zzz=8
    //vector<int> j = {1,2,3,4,5,6.3};//无法初始化成功,因为进行类开检查时,6.3是浮点,无法通过
    char c1{9};//可以初始化通过,因为9是字符
    //char c2{999};//无法通过初始化,因为999是整形,不是字符类型
    //通过用户初始化列表初始化
    initList({1,3,5,7,9});
    Test t1(1,2);//通过函数参数形式构造
    Test t2({3,4});//通过初始化列表形式构造
    Test t3({5,6,7,8});//通过初始化列表形式构造
    //隐匿转换
    Test2 t4 = {66,99};//可以隐藏转换
    //Test2 t5 = {77,88,99};//使用了explicit关键字,禁止隐匿转换
    //测试类对象做为引用时初始化
    func({77,88});//隐藏构造Test2
    //func({77,88,99});//使用了explicit关键字,禁止隐匿转换
    return 0;
}
