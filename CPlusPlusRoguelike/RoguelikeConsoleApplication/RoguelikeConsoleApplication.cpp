// RoguelikeConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameManager.h"
#include "GenerateMap.h"
#include <random>
#include <cwchar>
#include <windows.h>

using namespace Roguelike;
using namespace Roguelike::Generation;

template<int W, int H>
void printGameManager(const GameManager<W, H>& gameManager) {
    std::string s = "";
    for (int i = 0, count = gameManager.Width * gameManager.Height; i < count; i++) {
        switch (gameManager.Tiles[i]) {
            case Tile::Ground:
                s += ' ';
                break;
            case Tile::Wall:
                s += '#';
                break;
            default:
                s += 'E';
                break;
        }
        if (((i + 1) % gameManager.Width) == 0)
            s += '\n';
    }
    std::cout << s;
}

inline void setup() {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 8;                  // Width of each character in the font
    cfi.dwFontSize.Y = 12;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");    // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    srand(time(NULL));
}

int main() {
    setup();

    time_t start, end;
    time(&start);
    constexpr int w = 80, h = 40;
    GameManager<w, h>* gameManager = new GameManager<w, h>();
    Generator<w, h>(*gameManager).Generate();
    time(&end);
    printGameManager(*gameManager);
    delete gameManager;

    double time_taken = double(end - start);
    std::cout << "Time taken by program is : " << std::fixed << time_taken << std::cout.precision(8);
    std::cout << " sec " << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
