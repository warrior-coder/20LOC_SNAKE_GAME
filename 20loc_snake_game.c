#include <windows.h>
#include <stdio.h>
void main(int c, char** v) {
    for (CONSOLE_FONT_INFOEX cfi = { 84UL, 0, { 24, 24 }, 0, 0, L"Consolas" }; SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfi);) {
        long long freq, t1, t2 = 0LL; int game = TRUE, size = 0b11, dir = 77, _ch = 77, tmp; const W = 20, H = 20, DELAY = c == 1 ? 128 : atoi(1[v]);
        srand((QueryPerformanceFrequency(&freq), QueryPerformanceCounter(&t1), t1));
        system("mode con cols=20 lines=20 & title Snake Game & color F0 & cls");
        for (struct { short y, x; } body[0x100] = { {10, 10}, {9, 10}, {8, 10}, {7, 10}, 0 }, apple = { rand() % W, apple.y = rand() % H }; game;) {
            if (_kbhit(QueryPerformanceCounter(&t2))) if (_getch() == 224) _ch = _getch();
            if ((int)(1000.0 * (t2 - t1) / freq) >= DELAY) {
                printf("\x1B[107m\x1B[%d;%dH%c\x1B[41m\x1B[%d;%dH%c", body[size - 1].y + 1, body[size - 1].x + 1, 0, apple.y + 1, apple.x + 1, 0);
                for (int i = size - 1; i > 0; --i) *(body + i) = *(body + i - 1);
                (dir = abs(dir - _ch) != 2 && abs(dir - _ch) != 8 ? _ch : dir) % 2 ? (body->x += dir - 77 ? -1 : 1) : (body->y += dir - 80 ? -1 : 1);
                body->x < 0 ? body->x = W - 1 : body->x >= W ? body->x = 0 : (body->y = body->y < 0 ? H - 1 : body->y >= H ? 0 : body->y);
                if (body->x == apple.x && body->y == apple.y) memcpy(body + size, body + size++ - 1, sizeof(short) * 2U),\
                    memcpy(&apple, ((tmp = rand() % W | rand() % H << sizeof(short) * 8U), &tmp), sizeof(short) * 2U);
                for (int i = (QueryPerformanceCounter(&t1), 3); i < size; i++) if (body->x == body[i].x && body->y == body[i].y) game = FALSE;
                printf("\x1B[102m\x1B[%d;%dH%c\x1B[42m\x1B[%d;%dH%c\x1B[m\x1B[20;20H", body[1].y + 1, body[1].x + 1, 0, body->y + 1, body->x + 1, 0);
            }
        }
    }
}