#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    // Допустим, что введённый адрес верен.
    bool result = true;
    // Количество чисел в адресе.
    int numbers = 0;
    // Очередное число в адресе.
    string n;
    // Последовтельно перебираем все символы из введённой строки.
    // Для упрощения алгоритма добавляем в конец строки ещё одну точку.
    for (auto c : s + '.') {
        // Если очередной символ цифра,
        if (c >= '0' && c <= '9')
            // то 'добавляем' её к текущему числу.
            n += c;
        // Если очередной символ точка, то проверяем число расположенное
        // перед этой точной.
        else if (c == '.') {
            // Если число пусто (например, в строке идут две точки подряд)
            // или число слишком велико,
            if (n.empty() || stoi(n) > 255) {
                // то считаем адрес неверным и завершаем цикл.
                result = false;
                break; }
            else {
                // Иначе (если число корректно) увеличиваем колчество
                // найденных в адресе чисел и очищаем переменную
                // n для следующего числа.
                numbers += 1;
                n = ""; } }
        // Если очередной символ не является ни цифрой ни точкой,
        else {
            // то считаем адрес неверным и завершаем цикл.
            result = false;
            break; } }
    // Если количесво чисел в адресе не равно 4,
    if (numbers != 4)
        // то считаем адрес неверным.
        result = false;
    // Выводим результат.
    cout << (result ? "YES" : "NO");
    return 0; }