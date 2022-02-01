#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main(int c, char* v[]) {
    for (CONSOLE_FONT_INFOEX cfi = { sizeof(cfi), 0, { 24, 24 }, 0, 0, L"Consolas" }; SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfi);) {
        DWORD t1, t2; int gm = 1, len = 0b11, dir = 77, ch = dir, tmp, W = 20, H = W, dt = c == 1 ? 128 : atoi(1[v]); 
        system((srand((int)(t1 = GetTickCount())), "mode con cols=20 lines=20 & title Snake Game & color F0 & cls"));
        for (struct { short x, y; } bd[0x100] = { {10, 10}, {9, 10}, {8, 10} }, ap = { 1 + t1 % W, 1 + (t1 >> 4) % H }; gm;) {
            if ((t2 = GetTickCount()), _kbhit()) if (_getch() == 0xE0) ch = _getch();
            if ((int)(t2 - t1) > dt) {
                printf("\x1B[107m\033[%d;%dH \x1B[41m\033[%d;%dH ", bd[len - 1].y, bd[len - 1].x, ap.y, ap.x);
                for (int i = len - 1; i > 0; --i) *(bd + i) = *(bd + i - 1);
                (dir = abs(dir - ch) != 2 && abs(dir - ch) != 8 ? ch : dir) % 2 ? (bd->x += dir - 77 ? -1 : 1) : (bd->y += dir - 80 ? -1 : 1);
                bd->x < 1 ? bd->x = W : bd->x > W ? bd->x = 1 : (bd->y = bd->y < 1 ? H : bd->y > H ? 1 : bd->y);
                if (bd->x == ap.x && bd->y == ap.y) memcpy(&ap, ((bd[len++] = bd[len - 1]), (tmp = (1 + rand() % H) << 16U | (1 + rand() % W)), &tmp), 4U);
                for (int i = ((t1 = GetTickCount()), 3); i < len; i++) if (bd->x == bd[i].x && bd->y == bd[i].y) gm = 0;
                printf("\x1B[102m\033[%d;%dH \x1B[42m\033[%d;%dH \033[20;20H", bd[1].y, bd[1].x, bd->y, bd->x);
            }
        }
    }
}