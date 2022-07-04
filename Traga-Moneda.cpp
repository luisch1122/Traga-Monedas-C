#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int f1;
int f2;
int f3;
int inten;
int din;
int win;
int din1;
void operaciones();
void creditosch();
void maquinajg_();
void palanca();
void intentos();
void dinero();
void fin_();
void gotoxy ( int x, int y )
{
 COORD coord;
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

void intentos()
{
    char num[10];
    printf("Indique las veces que quiere jugar: ");
    scanf("%s" , num);
        inten=atoi(num);
    if(inten<=0)
    {
    printf("no es un numero\n");
    system ("cls");
    intentos();
    }
}

void dinero()
{
    char num[10];
    printf("\nIndique el dinero que utilizara");
    printf("\nApuesta minima de 10");
    printf("\nApuesta maxima de 900\n");
    scanf("%s" , num);
        din=atoi(num);
    if(din<=0)
    {
    printf("no es un numero\n");
    }
    if((din<10)||(din>900))
        {
        printf("la cantidad de dinero no es valida");
        dinero();
        }
    din1=din;
}

void maquinajg_()
{
    //la base del juego
    
    int i=1, d;
    char fruta1[7]={'C','A','M','P','A','N','A'};
    char fruta2[7]={'P','A','T','I','L','L','A'};
    char fruta3[6]={'C','A','M','B','U','R'};
    srand(time(NULL));
    //momento random
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
    while(i<4)
    {
        f1 = rand()%3+1;
        f2 = rand()%3+1;
        f3 = rand()%3+1;
    i++;
    }
    if (f1== 1){
        printf("°\t%s\t°", fruta1);
    }
        if (f1==2)
        {
            printf("°\t%s\t°", fruta2);
        }
            if (f1==3)
            {
                printf("°\t%s\t°", fruta3);    
            }
    if (f2== 1){
        printf("°\t%s\t°", fruta1);
    }
        if (f2==2)
        {
            printf("°\t%s\t°", fruta2);
        }
            if(f2==3)
            {
                printf("°\t%s\t°", fruta3);        
            }    
    if (f3== 1){
        printf("°\t%s\t°", fruta1);
    }
        if (f3==2)
        {
            printf("°\t%s\t°", fruta2);
        }
            if(f3==3)
            {
                printf("°\t%s\t°", fruta3);    
            }
    printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
    
        gotoxy(0,3); printf("°Movimiento°  %d  °", inten);
        gotoxy(17,3); printf("° Dinero °%d   °°", din1);
        gotoxy(33,3); printf("° Ganancia °%d    °", win);
        gotoxy(0,4); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
        gotoxy(0,5); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
        gotoxy(0,6); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
        gotoxy(0,7); printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
        gotoxy (48,3); printf("°  °");
        gotoxy (48,4); printf("° ° ");
    gotoxy (48,5); printf("°°");
    gotoxy (48,6); printf("°");
    gotoxy (48,7); printf("°");
    
    if((f1==f2)&&(f1==f3))
    {
        printf("\n\t\t\tganaste");
        win = din1*2;
    }
    else 
    {
        printf("\n\t\t\tperdiste");
    } 
    operaciones();
}
    
void operaciones()
{        
    int sin;
    char num[10];
    printf("\nSi quiere volver a jugar precione 1, para salir, precione 2\n");
    scanf("%s" , num);
        sin=atoi(num);
    if(sin==0)
    {
    printf("ERROR entrada no valida\n");
    operaciones();
    }
    if(sin==1)
    {
        inten-=1;
        din1=din1/2;
            if(inten<=0)
        {
                creditosch();
        }
        if(din1==0)
        {
                creditosch();
        }
            if((inten>0)&&(din1>0))
        {
        palanca();
            system ("cls");
            maquinajg_();    
        }
    }
    if(sin==2)
    {
        creditosch();
    }
    return;
}
void creditosch()
{  
    system ("cls");
    fin_();
    printf("Crador\n");
    printf("Alberto Chacon");
    printf ("\t\t En el juego usted gano %d", win);
    
}
void palanca()
{
    //coordenadas en donde seran escritas esta funcion
    gotoxy (48,3); printf("°       ");
      gotoxy (48,4); printf("°  ");
    gotoxy (48,5); printf("°");
    gotoxy (48,6); printf("° °");
    gotoxy (48,7); printf("°  ° ");
    Sleep(100);
}

main()
{
    int inicio, i;
    char num[10];
    printf("Bienvenido al tragaperras 3000\n");
    printf("Para iniciar presione 1 para iniciar el juego\n");
    scanf("%s" , num);
        inicio=atoi(num);
    if(inicio==0)
    {
    printf("no es un numero\n");
    system ("cls");
    main();
    }
        if (inicio == 1)
            {
            intentos();
            dinero();
            if(inten > 0)
            {
                if(din>0)
                {
                
                    system ("cls");
                    inten -=1;
                    din1=din1/2;
                    maquinajg_();
                }
            }
        }
        else {
            creditosch();
        }
}
void fin_()
{
    FILE *fiche;
    int alm;
    system ("cls");
    alm = din - win;
    fiche = fopen("juego.txt", "a");
    fprintf(fiche,"El dinero apostado es: %d, el dinero ganado es: %d, ", din, win);
    fprintf(fiche,"el dinero que quedo en el juego es: %d\n", alm);    
        
    fclose(fiche); 
}

