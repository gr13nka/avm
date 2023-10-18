#include <dos.h>
#include <conio.h>
#include <stdio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int delay_time = 100;
int key_escape = 27;
struct star {
	int cur_x, cur_y,dx,dy;
};

static void show_star(const struct star *s)
{
	gotoxy(s->cur_x, s->cur_y);
	insline();
	cprintf("# im at %d , %d", s->cur_x, s->cur_y);
}

static void hide_star(const struct star *s)
{
	gotoxy(s->cur_x, s->cur_y);
	delline();
	cprintf(" ");
}

static void check(int *coord, int min, int max)
{
	if(*coord < min)
		*coord += max-min; //not to
	else
	if(*coord > max)
		*coord -= max-min;
}

static void move_star(struct star *s,int x1, int y1, int x2, int y2)
{
	hide_star(s);

	s->cur_x += s->dx;
	check(&s->cur_x, x1, x2);

	s->cur_y += s->dy;
	check(&s->cur_y, y1, y2);

	show_star(s);
}

static void set_direction(struct star *s, int dx, int dy)
{
	s->dx = dx;
	s->dy = dy;
}

int main() {
	int x1 = 25;
	int x2 = 55;
	int y1 = 8;
	int y2 = 18;
	//INT16
	int key;
	struct star s;
	s.cur_x = x2-x1;
	s.cur_y = y2-y1;
	clrscr();

	window(x1,x2,y1,y2);
	gotoxy(2,3);
	/*
	for(int i = x1;i<x2;i++)
	{
	 for(int j = y1;j<y2;j++)
	 {
	   gotoxy(i,j);
	   insline();
	   cprintf("#");
	 }
	}
	  */
	while((key = getch()) != key_escape)
	{
		switch (key) {
			case KEY_UP:
				set_direction(&s, 0, -1);
				move_star(&s,x1, y1, x2, y2);
				break;
			case KEY_DOWN:
				set_direction(&s, 0, 1);
				move_star(&s,x1, y1, x2, y2);
				break;
			case KEY_LEFT:
				set_direction(&s, -1, 0);
				move_star(&s,x1,y1, x2, y2);
				break;
			case KEY_RIGHT:
				set_direction(&s, 1, 0);
				move_star(&s,x1,y1, x2, y2);
				break;
		}

	}

	return 0;
}