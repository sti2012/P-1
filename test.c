#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>

// http://electrosofts.com/cgraphics/index.html
// http://www.latindevelopers.com/forum/introduccion-a-graphics-h-t303.html
// http://www.programmingsimplified.com/c/graphics.h

//////////////////////////////////////////////////////////////////////		rectangle(2,2,__640__,__400__); (?)
//																	//
//			PROYECTO C: PREVISION METEOROLOGICA						//		90,30
//																	//
//		   __NOMBRE DE LA CIUDAD__				DIA PREVISION		//		
//																	//
//			>	 TEMPERATURA	<									//
//			>	    ACTUAL		<					HUMEDAD			//
//																	//
//			DIBUJO DE LA CONDICION									//
//			ACTUAL (GRANDE)							VIENTO			//
//			SOLEADO NUBLADO ETC...									//
//																	//
//////////////////////////////////////////////////////////////////////		line (0,250 , 640,250);
//																	//
//			  DIA X		  DIA X		  DIA X		  DIA X				//		90,280		210,280		330,280		450,280
//																	//
//			MINIMA		MINIMA		MINIMA		MINIMA				//		80,320		200,320		320,320		440,320
//				/			/			/			/				//		90,340		210,340		330,340		450,340
//				MAXIMA		MAXIMA		MAXIMA		MAXIMA			//		100,360		220,360		340,360		460,360
//																	//
//			CONDICION				CONDICION						//
//						CONDICION				CONDICION			//		60,440		180,460		300,440		420,460
//																	//
//////////////////////////////////////////////////////////////////////

struct meteo{
	char ciudad;
	char fecha;
	char temperatura;
	char humedad;
	char viento;
	char dia1;
	char low1;
	char high1;
	char condicion1;
	char dia2;
	char low2;
	char high2;
	char condicion2;
	char dia3;
	char low3;
	char high3;
	char condicion3;
	char dia4;
	char low4;
	char high4;
	char condicion4;
}Tiempo;


int main(void)
{
	// extern struct tiempo;	// (?)
	// SIN TERMINAR | FALTA
	//	Tiempo.ciudad = 'test';

	int salir = 1;

	char ciudad[20] = "abc TEST 123";
	char ciudadgraph[40];
	char fecha[15] = "2012-05-26";
	char fechagraph[30];
	char temperatura[4]= "-23";
	char humedad[20];
	char viento[30];
	char dia1[4];
	char low1[4];
	char high1[4];
	char condicion1[30];
	char dia2[4];
	char low2[4];
	char high2[4];
	char condicion2[20];
	char dia3[4];
	char low3[4];
	char high3[4];
	char condicion3[20];
	char dia4[4];
	char low4[4];
	char high4[4];
	char condicion4[20];

	int gd=DETECT, gm=VGAMAX;
	initgraph(&gd, &gm, 0);
	moveto(0, 0);
	setbkcolor(0);

/*
	setcolor(RED); 
	circle(300,250,50); 
	setcolor(BLUE);
	rectangle(50,50,500,200);
*/

	// Aspecto
	/*
		BLACK:		0 
		BLUE:		1 
		GREEN:		2
		CYAN:		3 
		RED:                       4 
		MAGENTA:            5 
		BROWN:                 6
		LIGHTGRAY:         7 
		DARKGRAY:          8
		LIGHTBLUE:           9
		LIGHTGREEN:       10 
		LIGHTCYAN:         11
		LIGHTRED:            12 
		LIGHTMAGENTA: 13
		YELLOW:               14
		WHITE:                   15
	*/
	setcolor(1);
	bar(2, 250, 637, 300);
	setcolor(8);
	for (int i = 0; i < 5; ++i)
		line(2,250+i,637,250+i);
	for (int i = 0; i < 5; ++i)
		rectangle(2+i,2+i,637-i,477-i);
	for (int i = 0; i < 5; ++i)
		line(160+i,250,160+i,477);
	for (int i = 0; i < 5; ++i)
		line(320+i,250,320+i,477);
	for (int i = 0; i < 5; ++i)
		line(480+i,250,480+i,477);





	//settextstyle(,,24);
	/*enum font_names 
	{ 
		DEFAULT_FONT,
		TRIPLEX_FONT,
		SMALL_FONT,
		SANS_SERIF_FONT,
		GOTHIC_FONT, 
		SCRIPT_FONT, 
		SIMPLEX_FONT, 
		TRIPLEX_SCR_FONT,
		COMPLEX_FONT, 
		EUROPEAN_FONT, 
		BOLD_FONT 
	};
	void settextstyle(DEFAULT_FONT, 0, 2 );*/

	// TITULO

		setcolor(BLUE);
		outtextxy(180,30, "PROYECTO C: PREVISION METEOROLOGICA");


	// CIUDAD
	
		setcolor(BLUE);
		sprintf(ciudadgraph, "CIUDAD: %s", ciudad);
		outtextxy(90,70, ciudadgraph);


	// DIA

		setcolor(RED);
		sprintf(fechagraph, "FECHA: %s", fecha);
		outtextxy(400,70, fechagraph);


	// TEMP ACTUAL

		setcolor(WHITE);
		outtextxy(70,120, "TEMPERATURA");
		outtextxy(115,140, "ACTUAL");
		for (int i = 0; i < 5; ++i)
		{
			line(170,170+i,210,98+i);
			line(173,170+i,213,98+i);
		}
		for (int i = 0; i < 5; ++i)
			rectangle(30+i,170+i,300-i,100-i);
		outtextxy(240,130, temperatura);


	// DIBUJO COND
/*
		setcolor(RED);
		//outtextxy(75,170, "%s",condicion->tiempo);

		
		// if...		dibujo sol
		// else if...	dibujo nubes
		// ...
		


	// HUMEDAD

		setcolor(RED); 
		outtextxy(75,170, "%s", humedad->tiempo);

	// VIENTO

		setcolor(RED); 
		outtextxy(75,170, "%s", viento->tiempo);

//////////////////////////////////////////////////////////////////////

	// DIA 1

		setcolor(RED); 
		outtextxy(75,170, "%s", dia1->tiempo);

		outtextxy(75,170, "%s", low1->tiempo);
		outtextxy(75,170, "/");
		outtextxy(75,170, "%s", high1->tiempo);


		// COND

			setcolor(RED); 
			outtextxy(75,170, "%s", condicion1->tiempo);

	// DIA 2

		setcolor(RED); 
		outtextxy(75,170, "%s", dia2->tiempo);

		outtextxy(75,170, "%s", low2->tiempo);
		outtextxy(75,170, "/");
		outtextxy(75,170, "%s", high2->tiempo);


		//COND

			setcolor(RED); 
			outtextxy(75,170, "%s", condicion2->tiempo);

	// DIA 3

		setcolor(RED); 
		outtextxy(75,170, "%s", dia3->tiempo);

		outtextxy(75,170, "%s", low3->tiempo);
		outtextxy(75,170, "/");
		outtextxy(75,170, "%s", high3->tiempo);


		// COND

			setcolor(RED); 
			outtextxy(75,170, "%s", condicion3->tiempo);

	// DIA 4

		setcolor(RED); 
		outtextxy(75,170, "%s", dia4->tiempo);

		outtextxy(75,170, "%s", low4->tiempo);
		outtextxy(75,170, "/");
		outtextxy(75,170, "%s", high4->tiempo);


		// COND

			setcolor(RED); 
			outtextxy(75,170, "%s", condicion4->tiempo);
*/

	while (!kbhit());//
		{
		

		}


	//while(1);
	//	if (/* condition */)
	//	{
	//		return 0;
	//	}
	closegraph();
	return 0;
}