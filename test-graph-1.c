#include <stdlib.h>
#include "graphics.h"

int main(void)
{
	int gd=DETECT, gm=VGAMAX;
	initgraph(&gd, &gm, 0);
	moveto(0, 0);
	rectangle(50,50,500,200);
	while (!kbhit());
	closegraph();
	return 0;
}