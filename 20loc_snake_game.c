#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main(int c, char* v[]) {
    for (CONSOLE_FONT_INFOEX cfi = { sizeof(cfi), 0, { 24, 24 }, 0, 0, L"Consolas" }; SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfi);) {
        DWORD t1, t2; int game = TRUE, size = 0b11, dir = 77, _ch = 77, tmp, W = 20, H = W, DELAY = c == 1 ? 80 : atoi(1[v]);
        system((srand((int)(t1 = GetTickCount())), "mode con cols=20 lines=20 & title Snake Game & color F0 & cls"));
        for (struct { short y, x; } body[0x100] = { {10, 10}, {9, 10}, {8, 10}, {7, 10}, 0 }, apple = { rand() % W, apple.y = rand() % H }; game;) {
            if ((t2 = GetTickCount()), _kbhit()) if (_getch() == 0xE0) _ch = _getch();
            if ((int)(t2 - t1) >= DELAY) {
                printf("\x1B[107m\x1B[%d;%dH%c\x1B[41m\x1B[%d;%dH%c", body[size - 1].y + 1, body[size - 1].x + 1, 0, apple.y + 1, apple.x + 1, 0);
                for (int i = size - 1; i > 0; --i) *(body + i) = *(body + i - 1);
                (dir = abs(dir - _ch) != 2 && abs(dir - _ch) != 8 ? _ch : dir) % 2 ? (body->x += dir - 77 ? -1 : 1) : (body->y += dir - 80 ? -1 : 1);
                body->x < 0 ? body->x = W - 1 : body->x >= W ? body->x = 0 : (body->y = body->y < 0 ? H - 1 : body->y >= H ? 0 : body->y);
                if (body->x == apple.x && body->y == apple.y) memcpy(body + size, body + size++ - 1, sizeof(short) * 2U), \
                    memcpy(&apple, ((tmp = rand() % W | rand() % H << sizeof(short) * 8U), &tmp), sizeof(short) * 2U);
                for (int i = ((t1 = GetTickCount()), 3); i < size; i++) if (body->x == body[i].x && body->y == body[i].y) game = FALSE;
                printf("\x1B[102m\x1B[%d;%dH%c\x1B[42m\x1B[%d;%dH%c\x1B[m\x1B[20;20H", body[1].y + 1, body[1].x + 1, 0, body->y + 1, body->x + 1, 0);
            }
        }
    }
}