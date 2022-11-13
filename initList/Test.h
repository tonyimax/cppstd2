//
// Created by Hacker X on 2022/11/13.
//

#ifndef CPPSTD2_TEST_H
#define CPPSTD2_TEST_H
#include <iostream>
using namespace std;

class Test {
public:
    Test();//默认构造
    Test(int a,int b);//使用固定个数参数构造
    Test(initializer_list<int>);//使用初始化列表构造
};


#endif //CPPSTD2_TEST_H
