#include <stdio.h>
#include <wchar.h>
#include <locale.h>

void bubble_sort(wchar_t *s) {
    int n = wcslen(s);
    if (n == 0) return; 

    wchar_t temp;
    wchar_t s_temp[n + 1];
    wcscpy(s_temp, s);

    wprintf(L"%ls\n", s);
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (s[j] < s[j - 1]) {
                temp = s[j];
                s[j] = s[j - 1];
                s[j - 1] = temp;
            }

            
            for (int k = 0; k < n; k++) {
                if (k < i) {
                    wprintf(L"\033[30m%lc\033[0m", s[k]); // Черный 
                } else if (k == j || k == j - 1) {
                    if (s_temp[j] < s_temp[j - 1]) {
                        wprintf(L"\033[4m%lc\033[0m", s[k]); // Подчеркнутый
                    } else {
                        wprintf(L"\033[32m%lc\033[0m", s[k]); // Зеленый
                    }
                } else {
                    wprintf(L"\033[30m%lc\033[0m", s[k]); // Черный 
                }
            }
            wprintf(L"\n");
        }
        for (int k = 0; k < n; k++) {
            wprintf(k < i + 1 ? L"\033[34m%lc\033[0m" : L"%lc", s[k]); // Синий
        }
        wprintf(L"\n");
    }
}

int main() {
    //"Зелёный - символы которые были поменяны местами в текущем шаге"
    //"Синий- уже отсортированный символ"
    //"Почеркивание - выделения символов, которые были выбраны для сравнения в текущем шаге"
    setlocale(LC_ALL, "");
    wchar_t str[] = L"НГУЕНЗУЙ";
    bubble_sort(str);
    return 0;
}