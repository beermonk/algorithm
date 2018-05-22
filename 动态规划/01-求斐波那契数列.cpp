//
// Created by mengjiale on 2018/5/15.
//
#include <iostream>
#include <vector>

class Fibonacci {
private:
    std::vector<int> temp;
public:
    int fib(int n)
    {
        for (int i = 0; i < n; i++) {
            temp.push_back(-1);
        }

    }
};
