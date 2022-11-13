//
// Created by Hacker X on 2022/11/13.
//

#ifndef CPPSTD2_TEST2_H
#define CPPSTD2_TEST2_H


class Test2 {
public:
    Test2();
    Test2(int a,int b);
    //禁止隐藏转换构造
    explicit Test2(int a,int b,int c);
};


#endif //CPPSTD2_TEST2_H
