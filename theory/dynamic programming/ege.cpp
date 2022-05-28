#include <iostream>
#include <vector>

using namespace std;

/*Пример3. У исполнителя Утроитель две команды, которым присвоены номера:
1. прибавь 2
2. умножь на 3
Первая из них увеличивает число на экране на 1,вторая — утраивает его.
Программа для Утроителя — это последовательность команд. Сколько есть
программ, которые число 2 преобразуют в число 20?*/

int main()
{
    // Обратный порядок
    vector<int> dp(21);
    dp[2] = 1;
    for (int i = 2; i < 19; i += 2)
    {
        dp[i + 2] += dp[i];
        if (i * 3 <= 20)
            dp[i * 3] += dp[i];
    }
    cout << dp[20] << " ";

    // Прямой порядок
    vector<int> dp2(21);
    dp2[2] = 1;
    for (int i = 4; i <= 20; i += 2)
    {
        dp[i] = dp[i - 2];
        if (i % 3 == 0)
            dp[i] += dp[i / 3];
    }
    cout << dp[20];
}
