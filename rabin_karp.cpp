#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

const int d = 256;
const int q = 101;

void rabinKarp(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m == 0)
    {
        cout << "Empty pattern matches at index 0\n";
        return;
    }

    if (m > n)
    {
        cout << "Pattern not found\n";
        return;
    }

    int p = 0;
    int t = 0;
    int h = 1;
    bool found = false;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            int j = 0;

            while (j < m && text[i + j] == pattern[j])
                j++;

            if (j == m)
            {
                cout << "Pattern found at index " << i << "\n";
                found = true;
            }
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }

    if (!found)
        cout << "Pattern not found\n";
}

int main()
{
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    auto startTime = chrono::system_clock::now();
    auto start = chrono::steady_clock::now();

    rabinKarp(text, pattern);

    auto end = chrono::steady_clock::now();
    auto endTime = chrono::system_clock::now();

    time_t startTimestamp = chrono::system_clock::to_time_t(startTime);
    time_t endTimestamp = chrono::system_clock::to_time_t(endTime);
    cout << "Start time: " << ctime(&startTimestamp);
    cout << "End time: " << ctime(&endTimestamp);
    cout << "Execution time: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds\n";

    return 0;
}