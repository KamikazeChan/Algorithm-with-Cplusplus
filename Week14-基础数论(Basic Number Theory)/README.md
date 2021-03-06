# 基础数论
### 斐波那契数（Fibonacci数）
> $f(1) = 1, f(0) = 0.$   
$f(n) = f(n-1) + f(n+2)$   
  
**Note:** **`f(n)%n`** is a periodic sequence.  
  
**To Find The Index Of A Given Fibonacci Number:**  
```c++
// Formula based Method: 
// Fibs = [0, 1, 1, 2, 3, 5, 8, 13, ...]
// n = round { 2.078087 * log(Fn) + 1.672276 }
#include<bits/stdc++.h> 
  
int findIndex(int Fn) { 
    float fibo = 2.078087 * log(Fn) + 1.672276; 
    return round(fibo); 
} 

int main() { 
    int Fn = 55; 
    cout << findIndex(Fn); 
} 

// Output: 10
```
 
### 卡特兰数（Catalan数）
$C_0 = 1, C_{n+1} = \sum_{i=0}^n C_iC_{n-i}(n>=0)$  **-Or-**  $C(n) = \frac{2n(2n-1)}{(n+1)n}C(n-1)$ **-Or-** $C(n+1) = \frac{2(2n+1)}{n+2}C(n)$  
**Top10:** $C_0 = 1, C_1 = 1, C_2 = 2, C_3 = 5, C_4 = 14, C_5 = 42, C_6 = 132, C_7 = 429, C_8 = 1430, C_9 = 4862, C_{10} = 16796$
Read more about catalan number: [wikipedia](https://en.wikipedia.org/wiki/Catalan_number)

### 组合计数
$C_n^m = {n \choose m} = \frac{n!}{(n-m)!m!}$  
$2^N = C_N^0 + C_N^1 + C_N^2 + \dots + C_N^N$  
  
Calculate "Combination Number Formula" in DP(O(n^2)).  
$C(n, 0) = C(n, n) = 1 $  
$C(n, k) = C(n-1, k-1) + C(n-1, k)$

**板子：**  
```c++
// Pascal Triangle

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e3 + 10;
const int MAXR = 2e3 + 10 + 10;
const int MODN = 1e9 + 7;  // 当数字比较大这里需要模一下
int l[MAXN][MAXR] = {0};

void initialize() {
    l[0][0] = 1;
    for(int i = 1; i < MAXN; ++i) {
        l[i][0] = 1;
        for(int j = 0; j < i + 1; ++j) {
            l[i][j] = (l[i-1][j-1] + l[i-1][j]) % MODN;
        }
    }
}

// Function to return the value of nCr 
int nCr(int n, int r) {
    return l[n][r];  // Return nCr 
}
```

### 取模运算(c++)
1. (a + b) % s = (a%s + b%s) % s
2. (a - b) % s = (a%s - b%s + s) % s
3. (a * b) % s = (a%s) * (b%s) % s
4. (a / b) % s = (a*(b^(s-2)) % s (only when s is prime number)

### 基础知识
1. 什么是质数，什么是合数
2. 如何检验一个数是不是质数
* naive
* O(sqrt(n))
* O(sqrt(n)/ln(sqrt(n))
3. 找出一个数的所有质因子  
[primes.cpp](https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week14-%E5%9F%BA%E7%A1%80%E6%95%B0%E8%AE%BA/primes.cpp)

### 最大公约数(GCD)
```c++
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
// consider using __gcd in c++
```

### 最小公倍数(lcm)
```c++
iny lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
```

### 解决线性丢番图方程
* 解决如下问题：`ａ*x + b*y = c`, 其中`a,b,c`已知，`ｘ,y`为所需要求的量。其中要求`x,y`是整数解。
* 所需知识：拓展欧几里得
* 方程有解，当且仅当 `c % (gcd(a, b)) == 0`
* 方程通解为：　　  
`d = gcd(a, b)`  
`X = x0 + b/d * n`  
`Y = y0 - a/d * n`

```c++
int x, y, d;  // store x, y, d as global varibales
void extendEuclid(int a, int b) {
    if(b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }  // base case
    extendEuclid(b, a % b);  // similar as the original gcd
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
```

**习题：**  
* **[**[UVa948:Fibonaccimal Base](https://vjudge.net/problem/UVA-948)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa10689:Yet another Number Sequence](https://vjudge.net/problem/UVA-10689)**]** **[**[Solution(C++)][2]**]**
* **[**[UVa991:Safe Salutations](https://vjudge.net/problem/UVA-991)**]** **[**[Solution(C++)][3]**]**
* **[**[UVa10007:Count the Trees](https://vjudge.net/problem/UVA-10007)**]** **[**[Solution(Python)][4]**]**

[1]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week14-%E5%9F%BA%E7%A1%80%E6%95%B0%E8%AE%BA/UVa948_Fibonaccimal%20Base.cpp
[2]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week14-%E5%9F%BA%E7%A1%80%E6%95%B0%E8%AE%BA/UVa10689_Yet%20another%20Number%20Sequence.cpp
[3]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week14-%E5%9F%BA%E7%A1%80%E6%95%B0%E8%AE%BA/UVa991_Safe%20Salutations.cpp
[4]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week14-%E5%9F%BA%E7%A1%80%E6%95%B0%E8%AE%BA/UVa10007_Count%20the%20Trees.py
