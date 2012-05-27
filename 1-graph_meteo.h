#include <stdlib.h>
#include <graphics.h>

// http://electrosofts.com/cgraphics/index.html
// http://www.latindevelopers.com/forum/introduccion-a-graphics-h-t303.html

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

typedef struct tiempo {
	int ciudad = ;
	int fecha = ;
	int temperatura = ;
	int humedad = ;
	int viento = ;
	int dia1 = ;
	int low1 = ;
	int high1 = ;
	int condicion1 = ;
	int dia2 = ;
	int low2 = ;
	int high2 = ;
	int condicion2 = ;
	int dia3 = ;
	int low3 = ;
	int high3 = ;
	int condicion3 = ;
	int dia4 = ;
	int low4 = ;
	int high4 = ;
	int condicion4 = ;
} tiempo;


int dibuja(void)
{
	// extern struct tiempo;
	extern tiempo;											// (?)
	// SIN TERMINAR | FALTA

	int gd=DETECT, gm=VGAMAX;
	initgraph(&gd, &gm, 0);
	moveto(0, 0);
	setbkcolor(BLACK);

/*
	setcolor(RED); 
	circle(300,250,50); 
	setcolor(BLUE);
	rectangle(50,50,500,200);
*/

	// TITULO
		moveto(0, 0);
		setcolor(BLUE);
		outtextxy(75,170, "PROYECTO C: PREVISION METEOROLOGICA");


	// CIUDAD
		moveto(0, 0);
		setcolor(BLUE);
		outtextxy(75,170, "CIUDAD: %s", ciudad->tiempo);


	// DIA
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "FECHA: %s", fecha->tiempo);

	// TEMP ACTUAL
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "TEMPERATURA ACTUAL");
		outtextxy(75,170, "%s", temperatura->tiempo);

	// DIBUJO COND
		moveto(0, 0);
		setcolor(RED); 
		//outtextxy(75,170, "%s",condicion->tiempo);

		/*
		if...		dibujo sol
		else if...	dibujo nubes
		...
		*/


	// HUMEDAD
		moveto(0, 0);
		setcolor(RED); 
		outtextxy(75,170, "%s", humedad->tiempo);

	// VIENTO
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


		// COND
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


		//COND
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


		// COND
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


		// COND
			moveto(0, 0);
			setcolor(RED); 
			outtextxy(75,170, "%s", condicion4->tiempo);


	while (!kbhit());//
/*		{


		}
*/
	closegraph();
	return 0;
}