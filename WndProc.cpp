//
// Created by user on 31.01.2020.
//
#include "main.h"
#include <utility>
#include <string>
char* StringToCharArr(const string& x){
    int size = x.length();
    char* answer = new char[size + 1];
    strcpy(answer, x.c_str());
    return answer;
}

LONG WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    static HWND HBtn;
    static HWND HAnswer;
    static HWND HEquation;
    static HWND HMessege;
    HINSTANCE hInst;

    static pair<int, pair<int, int>> operands = CreateEquation();
    TCHAR StrA[20];
    char* equation;
    string question;

    switch(msg)
    {
        case WM_CREATE: {
            hInst = ((LPCREATESTRUCT)lParam)->hInstance;

            HBtn = CreateWindow(
                    "button",
                    "Answer",
                    WS_CHILD | WS_VISIBLE | WS_BORDER,
                    250, 400, 100, 50, hwnd,
                    reinterpret_cast<HMENU>(1), hInst, nullptr
            );
            ShowWindow(HBtn, SW_SHOWNORMAL);
            HAnswer = CreateWindow(
                    "EDIT",
                    nullptr,
                    WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                    250, 350, 100, 20, hwnd,
                    nullptr, hInst, nullptr
            );
            ShowWindow(HAnswer, SW_SHOWNORMAL);
            question = to_string(operands.second.first) + "*" + to_string(operands.second.second);
            equation = StringToCharArr(question);
            HEquation = CreateWindow(
                    "Static",
                    equation,
                    WS_CHILD | WS_VISIBLE | ES_CENTER,
                    250, 200, 100, 20, hwnd,
                    nullptr, hInst, nullptr
            );
            delete equation;
            ShowWindow(HEquation, SW_SHOWNORMAL);
            HMessege = CreateWindow(
                    "Static",
                    "Insert Answer",
                    WS_CHILD | WS_VISIBLE | ES_CENTER,
                    250, 100, 100, 20, hwnd,
                    nullptr, hInst, nullptr
            );
            ShowWindow(HMessege, SW_SHOWNORMAL);
            return 0;
            break;
        }
        case WM_COMMAND :
            {
            if (lParam == (LPARAM)HBtn){
                    int Len = GetWindowTextA(HAnswer, StrA, 20);
                    int answer = StrToInt(StrA);
                    if(answer == operands.first) {
                        SetWindowText(HMessege, "Right");
                        operands = CreateEquation();
                        question = to_string(operands.second.first) + "*" + to_string(operands.second.second);
                        equation = StringToCharArr(question);
                        SetWindowText(HEquation, equation);
                        SetWindowText(HAnswer, nullptr);
                        delete equation;
                        ///SetClassLong(HMessege, GCL_HBRBACKGROUND, (LONG) CreateSolidBrush(5));
                    }
                    else {
                        SetWindowText(HMessege, "Wrong");
                        SetWindowText(HAnswer, nullptr);
                    }
            }
                return 0;
            }

        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
/*LONG WINAPI WndProc(HWND hwnd, UINT Message,
                    WPARAM wparam, LPARAM lparam) {
    HDC hdc;
    HINSTANCE hInst;
    PAINTSTRUCT ps;
    static HWND hBtn; // дескриптор кнопки
    static HWND hEdt1, hEdt2; // дескрипторы полей редактирования
    static HWND hStat; // дескриптор статического текста
    TCHAR StrA[20];
    int a, b, sum, Len;
    switch (Message) {
        case WM_CREATE: // сообщение создания окна
            hInst = ((LPCREATESTRUCT)lparam)->hInstance; // дескриптор приложения
            // Создаем и показываем первое поле редактирования
            hEdt1 = CreateWindow("edit", "0",
                                 WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 50, 50, 60, 20,
                                 hwnd, 0, hInst, NULL);
            ShowWindow(hEdt1, SW_SHOWNORMAL);
            // Создаем и показываем второе поле редактирования
            hEdt2 = CreateWindow("edit", "0",
                                 WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 150, 50, 60,
                                 20, hwnd, 0, hInst, NULL);
            ShowWindow(hEdt2, SW_SHOWNORMAL);
            // Создаем и показываем кнопку
            hBtn = CreateWindow("button", "Рассчитать",
                                WS_CHILD | WS_VISIBLE | WS_BORDER,
                                50, 100, 120, 30, hwnd, 0, hInst, NULL);
            ShowWindow(hBtn, SW_SHOWNORMAL);
            // Создаем и показываем поле текста для результата
            hStat = CreateWindow("static", "0", WS_CHILD | WS_VISIBLE,
                                 150, 180, 120, 20, hwnd, 0, hInst, NULL);
            ShowWindow(hStat, SW_SHOWNORMAL);
            break;
        case WM_COMMAND:  // сообщение о команде
            if (lparam == (LPARAM)hBtn)    // если нажали на кнопку
            {
                Len = GetWindowText(hEdt1, StrA, 20);
                a = StrToInt(StrA); // считываем число из первого поля
                Len = GetWindowText(hEdt2, StrA, 20);
                b = StrToInt(StrA); // считываем число из второго поля
                sum = a + b;  // находим сумму двух чисел
                SetWindowText(hStat, IntToStr(sum)); // выводим результат в статическое поле
            }
            break;
        case WM_PAINT: // перерисовка окна
            hdc = BeginPaint(hwnd, &ps); // начало перерисовки
            TextOut(hdc, 50, 20, "Введите два числа", 18); // вывод текстовых сообщений
            TextOut(hdc, 50, 180, "Результат:", 10);
            EndPaint(hwnd, &ps); // конец перерисовки
            break;
        case WM_DESTROY: // закрытие окна
            PostQuitMessage(0);
            break;
        default: // обработка сообщения по умолчанию
            return DefWindowProc(hwnd, Message, wparam, lparam);
    }
    return 0;
}*/