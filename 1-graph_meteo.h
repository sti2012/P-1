#include <stdlib.h>
#include <graphics.h>

// http://electrosofts.com/cgraphics/index.html
// http://www.latindevelopers.com/forum/introduccion-a-graphics-h-t303.html

//////////////////////////////////////////////////////////////////////
//																	//
//			PROYECTO C: PREVISION METEOROLOGICA						//
//																	//
//			NOMBRE DE LA CIUDAD 				DIA PREVISION		//
//																	//
//				TEMPERATURA											//
//				   ACTUAL							HUMEDAD			//
//																	//
//			DIBUJO DE LA CONDICION									//
//			ACTUAL (GRANDE)							VIENTO			//
//			SOLEADO NUBLADO ETC...									//
//																	//
//////////////////////////////////////////////////////////////////////
//																	//
//			  DIA X		  DIA X		  DIA X		  DIA X				//
//																	//
//			MINIMA		MINIMA		MINIMA		MINIMA				//
//				/			/			/			/				//
//				MAXIMA		MAXIMA		MAXIMA		MAXIMA			//
//																	//
//			CONDICION	CONDICION	CONDICION	CONDICION			//
//			(+DIBUJO?)	(+DIBUJO?)	(+DIBUJO?)	(+DIBUJO?)			//
//																	//
//////////////////////////////////////////////////////////////////////

int dibuja(void)
{
	// extern struct tiempo;     (?)

	// SIN TERMINAR | FALTA

	int gd=DETECT, gm=VGAMAX;
	initgraph(&gd, &gm, 0);
	moveto(0, 0);
	setbkcolor(BLACK);

	setcolor(RED); 
	circle(300,250,50); 
	setcolor(BLUE);
	rectangle(50,50,500,200);


	//TITULO
		moveto(0, 0);
		setcolor(BLUE);
		outtextxy(75,170, "PROYECTO C: PREVISION METEOROLOGICA");


	//CIUDAD
		moveto(0, 0);
		setcolor(BLUE);
		outtextxy(75,170, "CIUDAD: %s", ciudad->tiempo);


	//DIA
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "FECHA: %S", fecha->tiempo);

	//TEMP ACTUAL
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "TEMPERATURA ACTUAL");
		outtextxy(75,170, "%s", temperatura->tiempo);

	//DIBUJO COND
		moveto(0, 0);
		setcolor(RED); 
		//outtextxy(75,170, "Circle");

		/*
		if...		dibujo sol
		else if...	dibujo nubes
		...
		*/


	//HUMEDAD
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "%s", humedad->tiempo);

	//VIENTO
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "%s", viento->tiempo);

//////////////////////////////////////////////////////////////////////

	// DIA 1
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "%s", dia1->tiempo);

		outtextxy(75,170, "%s", low1->tiempo);
		outtextxy(75,170, "/");
		outtextxy(75,170, "%s", high1->tiempo);


		//DIBUJO COND
			moveto(0, 0);
			setcolor(RED); 
			outtextxy(75,170, "%s", condicion1->tiempo);

	// DIA 2
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "%s", dia2->tiempo);

		outtextxy(75,170, "%s", low2->tiempo);
		outtextxy(75,170, "/");
		outtextxy(75,170, "%s", high2->tiempo);


		//DIBUJO COND
			moveto(0, 0);
			setcolor(RED); 
			outtextxy(75,170, "%s", condicion2->tiempo);

	// DIA 3
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "%s", dia3->tiempo);

		outtextxy(75,170, "%s", low3->tiempo);
		outtextxy(75,170, "/");
		outtextxy(75,170, "%s", high3->tiempo);


		//DIBUJO COND
			moveto(0, 0);
			setcolor(RED); 
			outtextxy(75,170, "%s", condicion3->tiempo);

	// DIA 4
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "%s", dia4->tiempo);

		outtextxy(75,170, "%s", low4->tiempo);
		outtextxy(75,170, "/");
		outtextxy(75,170, "%s", high4->tiempo);


		//DIBUJO COND
			moveto(0, 0);
			setcolor(RED); 
			outtextxy(75,170, "%s", condicion4->tiempo);


	while (!kbhit());
	closegraph();
	return 0;
}