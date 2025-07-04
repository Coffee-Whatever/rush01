#include <stdlib.h> // for malloc()
#include <unistd.h> // for write()

void	display(int *grid)
{
	int y;
	int x;
	int	display_char;
	int	skip_new_line;

	y = 0;
	x = 0;
	skip_new_line = 1;
	display_char = 48;
	//display_char has value of 48 + x because 48 is ASCII decimal code for 0
	//so shifting it by x results in ASCII code for x
	//assuming that x is a digit from 0 to 9
	while (y < 4)
	{
		x = 0;
		if (!skip_new_line) {
			write(1, &"\n", 1);
		}
		skip_new_line = 0;
		while (x < 4)
		{
			display_char = 48 + grid[(4 * y) + x];
			//4*y because indexes look like this:
			// 0  1  2  3
			// 4  5  6  7
			// 8  9  10 11
			// 12 13 14 15
			// so x goes from 0-1-2-3 and y goes 0-4-8-12
			write(1, &display_char, 1);
			x++;
		}
		y++;
	}
}

void	fill_it_with_crap(int *grid)
{
	int y;
	int x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			//grid[(y * 4) + x] = 0;
			grid[(y * 4) + x] = (y + x) % 3;
			// (y+x)%3 so the display shows more than zeros for now
			x++;
		}
		y++;
	}
}

int main(void)
{
	int	*grid;

	grid = malloc(4*4*4); // x*y*sizeof(int)
	//ints are 4 bytes long, and we need a grid of them 4x4
	//that's why we need a (4*4)*4 pointer;
	fill_it_with_crap(grid);
	display(grid);
	return 0;
}