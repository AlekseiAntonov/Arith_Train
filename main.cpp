#include <windows.h>
#include <random>
#include <ctime>
#include "main.h"
using namespace std;


#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

// Основная функция - аналог int main() в консольном приложении:
int WINAPI WinMain(HINSTANCE hInstance, // дескриптор экземпляра приложения
                   HINSTANCE hPrevInstance, // в Win32 не используется
                   LPSTR lpCmdLine, // нужен для запуска окна в режиме командной строки
                   int nCmdShow) // режим отображения окна
{
    // Функция вывода окна с кнопкой "ОК" на экран (о параметрах позже)
    HWND hMainWnd;
    MSG msg{};

    WNDCLASSEX wc{sizeof(WNDCLASSEX)}; // создаём экземпляр, для обращения к членам класса WNDCLASSEX
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    wc.lpszMenuName  = nullptr;
    wc.lpszClassName = "MyAss";

    if(!RegisterClassEx(&wc))
    {
        MessageBox(nullptr, "Window Registration Failed!", "Error!",
                   MB_ICONEXCLAMATION | MB_OK);
        return EXIT_FAILURE;
    }

    if(hMainWnd = CreateWindow(wc.lpszClassName, "Arithmetics training", WS_OVERLAPPEDWINDOW, 0, 0, 600, 600, nullptr, nullptr,
                               wc.hInstance,
                               nullptr); hMainWnd ==INVALID_HANDLE_VALUE){
        return EXIT_FAILURE;
    }
    ShowWindow(hMainWnd, nCmdShow);
    UpdateWindow(hMainWnd);
    while (GetMessage(&msg, nullptr, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }
    //MessageBox(NULL, reinterpret_cast<LPCSTR>("x!!!"), reinterpret_cast<LPCSTR>("Rs"), MB_OK);
    return EXIT_SUCCESS; // возвращаем значение функции
}