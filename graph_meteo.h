#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h> // Libreria necesaria para los graficos

//////////////////////////////////////////////////////////////////////
//																	//
//				  PROYECTO C: PREVISION METEOROLOGICA				//
//																	//
//																	//
//		   __NOMBRE DE LA CIUDAD__				DIA PREVISION		//
//																	//
//			>	 TEMPERATURA	<									//
//			>		ACTUAL		<				HUMEDAD				//
//			_____________________									//
//												VIENTO				//
//			CONDICION ACTUAL										//
//																	//
//////////////////////////////////////////////////////////////////////
//																	//
//		DIA 	  MINIMA	MAXIMA		CONDICION ATMOSFERICA 		//
//																	//
//		 X			12 	 /	 34 		Parcialmente nublado 		//
//		 X			12 	 /	 34 		Soleado 					//
//		 X			12 	 /	 34 		Parcialmente nublado 		//
//		 X			12 	 /   34 		Soleado 					//
//																	//
//////////////////////////////////////////////////////////////////////
	

int dibuja(void)
{
	extern char *ciudad; // Obtiene los datos de las variables externas contenidas en xml_meteo.h
	extern char *fecha;
	extern char *condicion;
	extern char *temperatura;
	extern char *humedad;
	extern char *viento;
	extern char *dia1;
	extern char *low1;
	extern char *high1;
	extern char *condicion1;
	extern char *dia2;
	extern char *low2;
	extern char *high2;
	extern char *condicion2;
	extern char *dia3;
	extern char *low3;
	extern char *high3;
	extern char *condicion3;
	extern char *dia4;
	extern char *low4;
	extern char *high4;
	extern char *condicion4;
	char ciudadgraph[40];
	char fechagraph[30];
	char condgraph[60];

	if (ciudad == NULL)
	{
		printf("* ------------------------------------------------------------------------- *\n");
		printf("*   ERROR: Comprueba que has escrito el nombre de la ciudad correctamente   *\n");
		printf("* ------------------------------------------------------------------------- *\n");
		return 0;
	}

	int gd=DETECT, gm=VGAMAX; // Se inician las caracteristicas de la pantalla de graficos
	initgraph(&gd, &gm, 0); // Iniciamos los graficos
	moveto(0, 0);	// No es necesario
	setbkcolor(0);	// Cambia el color de fondo a 0 = BLACK

	setcolor(4); // Cambia al color 4 = RED
	bar(2, 20, 637, 50);	// Crea una barra para el titulo
	setcolor(1); // Cambia al color 1 = BLUE
	bar(2, 250, 637, 290);	// Crea una barra para las condiciones de los 4 proximos dias

	setcolor(8); // Cambia al color 8 = GRAY
	for (int i = 0; i < 5; ++i)
		line(2,250+i,637,250+i);
	for (int i = 0; i < 5; ++i)
		rectangle(2+i,2+i,637-i,477-i);

	for (int i = 0; i < 5; ++i)
	{
		line(180,190+i,220,118+i);
		line(183,190+i,223,118+i);
	}
	for (int i = 0; i < 5; ++i)
		rectangle(30+i,190+i,300-i,120-i);

///////////////////////////////////////////////////////////////////////////////

	// TITULO
		outtextxy(180,30, "PROYECTO C: PREVISION METEOROLOGICA");

	// CIUDAD
		sprintf(ciudadgraph, "CIUDAD:  %s", ciudad);
		outtextxy(40,85, ciudadgraph);

	// FECHA
		sprintf(fechagraph, "FECHA:  %s", fecha);
		outtextxy(400,90, fechagraph);

	// TEMP ACTUAL
		outtextxy(70,140, "TEMPERATURA");
		outtextxy(115,160, "ACTUAL");
		outtextxy(240,150, temperatura);

	// COND
		sprintf(condgraph, "CIELO:  %s", condicion);
		outtextxy(40,220, condgraph);

	// HUMEDAD
		outtextxy(400,140, humedad);

	// VIENTO
		outtextxy(400,180, viento);


///////////////////////////////////////////////////////////////////////////////

	// MENU
		outtextxy(40,270, "DIA");
		outtextxy(130,270, "MINIMA");
		outtextxy(200,270, "/");
		outtextxy(230,270, "MAXIMA");
		outtextxy(360,270, "CONDICION ATMOSFERICA");

	// DIA 1
		outtextxy(40,320, dia1);
		outtextxy(145,320, low1);
		outtextxy(200,320, "/");
		outtextxy(255,320, high1);
		// COND
			outtextxy(360,320, condicion1);

	// DIA 2
		outtextxy(40,360, dia2);
		outtextxy(145,360, low2);
		outtextxy(200,360, "/");
		outtextxy(255,360, high2);
		//COND
			outtextxy(360,360, condicion2);

	// DIA 3
		outtextxy(40,400, dia3);
		outtextxy(145,400, low3);
		outtextxy(200,400, "/");
		outtextxy(255,400, high3);
		// COND
			outtextxy(360,400, condicion3);

	// DIA 4
		outtextxy(40,440, dia4);
		outtextxy(145,440, low4);
		outtextxy(200,440, "/");
		outtextxy(255,440, high4);
		// COND
			outtextxy(360,440, condicion4);

///////////////////////////////////////////////////////////////////////////////

			getchar();
			restorecrtmode();
	/*
	while (!kbhit()); // Mantiene el grafico abierto hasta que se pulsa una tecla (ENTER)
	closegraph();	// Cierra el grafico
	return 0;		// Volvemos a meteo.c
	*/
}