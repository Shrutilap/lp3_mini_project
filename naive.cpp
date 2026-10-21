#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

void naiveSearch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    bool found = false;

    for (int i = 0; i <= n - m; i++)
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

    naiveSearch(text, pattern);

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