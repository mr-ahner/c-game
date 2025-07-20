#include <iostream>
#include <conio.h>
#include <windows.h>
enum Direction { UP, DOWN, LEFT, RIGHT };
const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;
class Player {
public:
    int x = 0;
    int y = 0;

    void move(Direction dir) {
        switch (dir) {
            case UP:    y--; break;
            case DOWN:  y++; break;
            case LEFT:  x--; break;
            case RIGHT: x++; break;
        }
        std::cout << "Player moved to (" << x << ", " << y << ")\n";
    }
};
void drawMap(const Player& player)
{
	system("cls");
	for(int y = 0; < MAP_HEIGHT; ++y)
	{
		for(int x = 0; x < MAX_WIDTH; ++x)
		{
			if(x == player.x && y == player.y)
				std::cout << "@ ";
			else
				std::cout << ". ";
		}
		std::cout << "/n";
	}
}
int main() {
    Player player;
    char ch;
    bool running = true;

    std::cout << "Welcome to SBG (press 'q' or ESC to quit)\n";
	drawMap(player);
    while(running) 
	{
		if(kbhit()) 
		{
				ch = getch();
				switch(ch)
				{
					case 'w': player.move(UP); break;
					case 's': player.move(DOWN); break;
					case 'a': player.move(LEFT); break;
					case 'd': player.move(RIGHT); break;
					case 27:
					case 'q':
					std::cout << "Quit..\n";
					running = false;
					continue;
				}
				drawMap(player)
		}
		_sleep(100);
	}

    return 0;
}
