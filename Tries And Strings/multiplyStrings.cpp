#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2)
{
    int n = num1.length(), m = num2.length();
    if (num1 == "0" || num2 == "0")
        return "0";

    vector<int> dp(n + m, 0);
    int i = m - 1;
    int pf = 0;

    while (i >= 0)
    {
        int val1 = num2[i] - '0';
        i--;

        int j = n - 1, carry = 0;
        int k = (n + m - 1) - pf;

        while (j >= 0 || carry != 0)
        {
            int val2;
            if (j >= 0)
                val2 = num1[j] - '0';
            else
                val2 = 0;
            j--;

            int s = val1 * val2 + carry + dp[k];
            dp[k] = s % 10;
            carry = s / 10;
            k--;
        }
        pf++;
    }

    string ans = "";
    bool flag = false;

    for (int i : dp)
    {
        if (i == 0 && flag == false)
            continue;
        else
        {
            flag = true;
            char ch = i+'0';
            ans.push_back(ch);
        }
    }

    return ans;
}

int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    cout << multiply(num1, num2) << endl;
}