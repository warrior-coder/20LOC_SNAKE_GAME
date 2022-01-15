#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main(int c, char* v[]) {
    for (CONSOLE_FONT_INFOEX cfi = { sizeof(cfi), 0, { 24, 24 }, 0, 0, L"Consolas" }; SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfi);) {
        DWORD t1, t2; int game = 1, size = 0b11, dir = 77, _ch = dir, tmp, W = 20, H = W, delay = c == 1 ? 128 : atoi(1[v]);
        system((srand((int)(t1 = GetTickCount())), "mode con cols=20 lines=20 & title Snake Game & color F0 & cls"));
        for (struct { short x, y; } body[0x100] = { {10, 10}, {9, 10}, {8, 10} }, apple = { 1 + t1 % W, 1 + (t1 >> 4) % H }; game;) {
            if ((t2 = GetTickCount()), _kbhit()) if (_getch() == 0xE0) _ch = _getch();
            if ((int)(t2 - t1) > delay) {
                printf("\x1B[107m\x1B[%d;%dH \x1B[41m\x1B[%d;%dH ", body[size - 1].y, body[size - 1].x, apple.y, apple.x);
                for (int i = size - 1; i > 0; i--) *(body + i) = *(body + i - 1);
                (dir = abs(dir - _ch) != 2 && abs(dir - _ch) != 8 ? _ch : dir) % 2 ? (body->x += dir - 77 ? -1 : 1) : (body->y += dir - 80 ? -1 : 1);
                body->x < 1 ? body->x = W : body->x > W ? body->x = 1 : (body->y = body->y < 1 ? H : body->y > H ? 1 : body->y);
                if (body->x == apple.x && body->y == apple.y) memcpy(body + size, body + size - 1, (sizeof(*body))), \
                    memcpy((++size, &apple), ((tmp = (1 + rand() % H) << sizeof(short) * 8 | (1 + rand() % W)), &tmp), sizeof(apple));
                for (int i = ((t1 = GetTickCount()), 3); i < size; i++) if (body->x == body[i].x && body->y == body[i].y) game = 0;
                printf("\x1B[102m\x1B[%d;%dH \x1B[42m\x1B[%d;%dH \x1B[20;20H\x1B[107m", body[1].y, body[1].x, body->y, body->x);
            }
        }
    }
}