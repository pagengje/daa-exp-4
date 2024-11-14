#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Brute force multiplication
long long multiply_brute(int a, int b) {
    int x = max(a, b);
    int y = min(a, b);
    long long ans = 0;
    for (int i = 1; i <= y; i++) {
        ans += x;
    }
    return ans;
}

// Divide and conquer multiplication
long long multiply_divide_conquer(long long a, long long b) {
    if (a < 10 || b < 10) {
        return a * b;
    }

    int n1 = to_string(a).length();
    int n2 = to_string(b).length();
    int n = min(n1, n2) / 2;

    long long power_of_10_n = 1;
    for (int i = 0; i < n; ++i) {
        power_of_10_n *= 10;
    }

    long long a1 = a / power_of_10_n;
    long long a0 = a % power_of_10_n;
    long long b1 = b / power_of_10_n;
    long long b0 = b % power_of_10_n;

    long long p = multiply_divide_conquer(a1, b1);
    long long q = multiply_divide_conquer(a0, b0);
    long long r = multiply_divide_conquer(a1 + a0, b1 + b0) - p - q;

    return p * power_of_10_n * power_of_10_n + r * power_of_10_n + q;
}

int main() {
    long long a, b;

    cout << "Enter two integers to multiply: ";
    cin >> a >> b;

    cout << "Brute Force Multiplication Result: " << multiply_brute(a, b) << endl;
    cout << "Divide and Conquer Multiplication Result: " << multiply_divide_conquer(a, b) << endl;

    return 0;
}
