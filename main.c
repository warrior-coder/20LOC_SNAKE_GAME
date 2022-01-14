#include <windows.h>
#include <time.h>
#include <stdio.h>

void main()
{
	srand(time(NULL));
	const int WIDTH = 20, HEIGHT = 20, DELAY = 5000;
	struct { int x, y; } body[0x100], apple;
	int size, dir, timer;
	char buf[20 * 20 + 1];

	system("mode con cols=20 lines=20 & color 0F & title Snake Game");
	CONSOLE_FONT_INFOEX cfi = { sizeof(CONSOLE_FONT_INFOEX), NULL, { 20, 20 }, NULL, FW_BOLD, L"Consolas" };
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfi);

	for (BOOL game; TRUE;)
	{
		dir = 2;
		size = 4;
		timer = 0;

		for (int i = 0; i < size; ++i)
		{
			body[i].x = WIDTH / 2 - i;
			body[i].y = HEIGHT / 2;
		}
		apple.x = rand() % WIDTH;
		apple.y = rand() % HEIGHT;
		for (game = TRUE; game; timer++)
		{
			if (_kbhit())
				if (_getch() == 224)
					switch (_getch())
					{
					case 72: if (dir != 3) dir = 0; break; // UP
					case 75: if (dir != 2) dir = 1; break; // LEFT
					case 77: if (dir != 1) dir = 2; break; // RIGHT
					case 80: if (dir != 0) dir = 3; break; // DOWN
					}
			if (timer > DELAY)
			{
				for (int i = size - 1; i > 0; --i) body[i] = body[i - 1];

				switch (dir)
				{
				case 0: body[0].y--; break;
				case 1: body[0].x--; break;
				case 2: body[0].x++; break;
				case 3: body[0].y++; break;
				}

				if (body[0].x < 0 || body[0].y < 0 || body[0].x >= WIDTH || body[0].y >= HEIGHT) game = FALSE;
				if (body[0].x == apple.x && body[0].y == apple.y)
				{
					body[size].x = 0;
					body[size++].y = HEIGHT;
					apple.x = rand() % WIDTH;
					apple.y = rand() % HEIGHT;
				}
				memset(buf, ' ', sizeof(char) * WIDTH * HEIGHT);

				buf[apple.y * WIDTH + apple.x] = '*';
				buf[body[0].y * WIDTH + body[0].x] = '@';
				for (int i = 1; i < size; i++)
				{
					if (body[0].x == body[i].x && body[0].y == body[i].y) game = FALSE;
					buf[body[i].y * WIDTH + body[i].x] = '#';
				}
				buf[WIDTH * HEIGHT] = '\0';

				if (game) printf("%s", buf);
				timer = 0;
			}
		}
	}
}