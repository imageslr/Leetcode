#include <iostream>

using namespace std;

class Solution
{
public:
    int maximum(int a, int b)
    {
        // 主要问题在于：由于可能会溢出，所以异号的情况下不能直接做减法
        int diffSign = !!((a >> 31) ^ (b >> 31)); // 判断符号是否不同
        // k 是一个系数，k 为 1 时选 a，k 为 0 时选 b
        // 这里计算 b-a 时强制转为 long，是因为 Leetcode 的编译器在 int 溢出时会报错
        // 但我们确实依赖了溢出检测，我本机上的编译器是允许溢出的，就可以不加 long
        int k = (diffSign & b >> 31) | ((!diffSign) & ((long(b) - long(a)) >> 63));
        // 上面的代码相当于：
        // if diffSign {
        //     k = b>>31 // a、b 异号，如果 b 符号位为 1，则 b 是负数，a > 0 > b
        // } else {
        //     k = (b-a)>>31 // a、b 同号，直接做减法也不会溢出，如果 b-a 符号位为 1，则 a > b
        // }
        return a * k + b * (k ^ 1);
    }
};

int main()
{
    Solution s;
    cout << s.maximum(1, 2) << endl;
    cout << s.maximum(2, 1) << endl;
    cout << s.maximum(1, -2) << endl;
    cout << s.maximum(-2, 1) << endl;
    cout << s.maximum(2147483647, -2147483648) << endl;
    return 0;
}
