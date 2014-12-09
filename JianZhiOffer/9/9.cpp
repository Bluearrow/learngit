/* 9.cpp 斐波那契（Fibonacci）数列
 * @题目：
 * 给定正整数n，输出Fibonacci数组的第n项。
 */

#include <iostream>
using namespace std;

/* 根据定义，采用迭代的方法 */
long long Fibonacci(unsigned int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

/* 采用时间复杂度更低的循环方法 */
long long Fibonacci1(unsigned int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
    {
        long long fa = 0;
        long long fb = 1;
        long long fc = 0;
        for(unsigned int i = 2; i <= n; i++)
        {
            fc = fa + fb;
            fa = fb;
            fb = fc;
        }
        return fc;
    }
}

void Test()
{
    cout << Fibonacci(10) << endl;
    cout << Fibonacci1(10) << endl;
}

int main()
{
    Test();

    return 0;
}
