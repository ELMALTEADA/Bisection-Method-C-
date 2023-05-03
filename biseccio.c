
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main ()
{
	system ("COLOR 0B");
	printf("\n Por favor elija que METODO NUMERICO va a utilizar: \n1 = Biseccion \n2 = Newton Raphson \n3 = Por secante \n4 = Secante modificado \n5 = Newton-Raphson Modificado\n");
    int d1;
    scanf("%d",&d1);
    switch(d1)
    {
        case 1: //biseccion
            {
                printf("METODO DE BISECCION : Consiste en acercarse a la raiz de la funcion a traves de 2 Intervalos\n");
                printf("Por favor elija que funcion desea evaluar:\n 1 = Paracaidista  \n2 = (e^-x)-x \n");
                int d2;
                scanf("%d",&d2);
                switch(d2)
                {
                case 1:
                    {// COMIENZA PARACAIDISTA
                    float g=9.81, m=68.1, e=2.7182, t=10.0,v=40.0; // constantes de funcion
                    float c=-20, fc;
                    //funcion = (((g*m)/c)*((1-pow(e,-((c/m)*t)))))-v
                    printf("Tabularemos la funcion para encontrar sus raices\n");
                    printf("     c                |     f(c)      ");
                    while(c<20) //Comienza tabulacion
                    {
                        fc= (((g*m)/c)*((1-pow(e,-((c/m)*t)))))-v;
                    printf("\n%f",c);
                    printf("                  %f", fc);
                        c=c+1;
                    }
                    printf("\n Existe una raiz dentro de los intervalos? \n 1 = Si \n2 = No\n");
                    int d3;
                    scanf("%d",&d3);
                    switch(d3)
                    {
                    case 1:
                        {
                            printf("\nc1 = ");
                            float c1, c2;
                            scanf("%f",&c1);
                            printf("\nc2 = ");
                            scanf("%f",&c2);
                            //verificaremos que el intervalo sea correcto
                            float fc1, fc2, fc3, fxrn;
                            fc3 = ((((g*m)/c1)*((1-pow(e,-((c1/m)*t)))))-v)*((((g*m)/c2)*((1-pow(e,-((c2/m)*t)))))-v);
                            if (fc3<0)
                            {
                                printf("\nEl intervalo es correcto, procederemos a realizar los calculos");
                                printf("\n Por favor ingresa el error porcentual aceptado\n");
                                float ep;
                                float xrn, xrv = 0,error2, error;
                                scanf("%f",&ep);
                                printf("|   c1        |        Xr        |       f(c1)      |        f(c2)       |       Error       |");
                                do
                                {
                                    xrn = (c1 + c2)/2;
                                    fc1=((((g*m)/c1)*((1-pow(e,-((c1/m)*t)))))-v);
                                    fc2=((((g*m)/c2)*((1-pow(e,-((c2/m)*t)))))-v);
                                    fxrn=((((g*m)/xrn)*((1-pow(e,-((xrn/m)*t)))))-v);
                                    error = (xrn - xrv)/xrn*100;
                                    if (error<0) // Por si el error sale negativo y no tener iteraciones infinitas
                                    {
                                        error2 = error*(-1);
                                    }
                                    else
                                    {
                                        error2 = error;
                                    }
                                    printf("\n%f          %f           %f            %f            %f\n",c1,xrn,fc1,fc2,error);
                                    //Calculamos hacia donde se dirigen los intervalos
                                    float y;
                                    y = (fc1)*(fxrn);
                                    if(y>0)
                                    {
                                        c1 = xrn;
                                        c2 = c2;
                                    }
                                    xrv = xrn;
                                } while (error2>=ep); //Hasta que sea menor o igual que el error
                            }
                               else
                                {

                                }

                            break;
                        }
                    }
                    break;
                    }// TERMINA PARACAIDISTA
                    case 2: //COMIENZA EULER MENOS X
                        {

                    float e=2.7128;
                    float x=-20, fx;
                    //funcion = (pow(e, -x))-x;
                    printf("Tabularemos la funcion para encontrar sus raices\n");
                    printf("     x                |     f(x)      ");
                    while(x<20) //Comienza tabulacion
                    {
                        fx= (pow(e, -x))-x;
                    printf("\n%f",x);
                    printf("                  %f", fx);
                        x=x+1;
                    }
                    printf("\n Existe una raiz dentro de los intervalos? \n 1 = Si \n2 = No\n");
                    int d3;
                    scanf("%d",&d3);
                    switch(d3)
                    {
                    case 1:
                        {
                            printf("\nx1 = ");
                            float x1, x2;
                            scanf("%f",&x1);
                            printf("\nx2 = ");
                            scanf("%f",&x2);
                            //verificaremos que el intervalo sea correcto
                            float fx1, fx2, fx3, fxrn;
                            fx3 = ((pow(e, -x1))-x1)*((pow(e, -x2))-x2);
                            if (fx3<0)
                            {
                                printf("\nEl intervalo es correcto, procederemos a realizar los calculos");
                                printf("\n Por favor ingresa el error porcentual aceptado\n");
                                float ep;
                                float xrn, xrv = 0,error2, error;
                                scanf("%f",&ep);
                                printf("|   x1        |        Xr        |       f(x1)      |        f(x2)       |       Error       |");
                                do
                                {
                                    xrn = (x1 + x2)/2;
                                    fx1=((pow(e, -x1))-x1);
                                    fx2=((pow(e, -x2))-x2);
                                    fxrn=((pow(e, -xrn))-xrn);
                                    error = (xrn - xrv)/xrn*100;
                                    if (error<0) // Por si el error sale negativo y no tener iteraciones infinitas
                                    {
                                        error2 = error*(-1);
                                    }
                                    else
                                    {
                                        error2 = error;
                                    }
                                    printf("\n%f          %f           %f            %f            %f\n",x1,xrn,fx1,fx2,error2);
                                    //Calculamos hacia donde se dirigen los intervalos
                                    float y;
                                    y = (fx1)*(fxrn);
                                    if(y>0)
                                    {
                                        x1 = xrn;
                                        x2 = x2;
                                    }
                                    else
                                    {
                                        x1=x1;
                                        x2=xrn;
                                    }
                                    xrv = xrn;
                                } while (error2>=ep); //Hasta que sea menor o igual que el error
                            }
                               else
                                {

                                }

                            break;
                        }
                    }

                    break;
                        }
                }
break;
            }//TERMINA BISECCION
                    case 2: //COMIENZA NEWTON RAPHSON
                        {
                printf("METODO DE NEWTON-RAPHSON : Consiste en acercarse a la raiz de la funcion a traves de la derivada de la funcion\n");
                printf("Por favor elija que funcion desea evaluar:\n 1 = Paracaidista  \n2 = (e^(-x^2))-x \n");
                int d2;
                scanf("%d",&d2);
                switch(d2)
                        {
                        case 2:
                            {//COMIENZA LA DE EULER MENOS X
                            printf("\n Primero tabularemos la funcion para encontrar su raices");
                            float x=-20,e=2.7128, fx; /* (pow(e,(-pow(x,2))))-x  derivada = (-2*x*(pow(e,(-pow(x,2)))))-1        */
                            printf("\n     x               |         f{x)\n");
                            while(x<20)
                            {
                                fx=(pow(e,(-pow(x,2))))-x;
                                printf("     %f     |         %f\n",x,fx);

                                x=x+1;
                            }
                            printf("Existe algun cambio de signo en la tabulacion?\n \n 1 = Si \n 2 = No\n");
                            int d3;
                            scanf("%d",&d3);
                            switch(d3)
                            {
                            case 1:
                                {
                                    printf("Cuales son?\n");
                                    float xa, xb;
                                     printf("xa = ");
                                    scanf("%f",&xa);
                                    printf("\nxb = ");
                                    scanf("%f",&xb);
                                    printf("\nCon que error trabajaremos? ");
                                    float ep;
                                    scanf("%f",&ep);
                                    float fxa, fdxa, xv=0, xn, error, error2, exp, e=2.7128;
                                    printf("\n Procederemos a realizar calculos\n");
                                    printf("     Xi     |     f(x)     |     f'(x)    |    Xi+1     |      Ep       |\n");
                                    do
                                    {
                                    exp = (-1)*(pow(xa,2));
                                    fxa = (pow(e,exp))-xa;
                                    fdxa = ((-2)*xa*(pow(e,exp)))-1;
                                    xn = xa - ((fxa)/fdxa);
                                    error = ((xn-xa)/xn)*100;
                                    if(error<0)
                                    {
                                        error2=error*(-1);
                                    }
                                    else
                                        {
                                            error2=error;
                                        }
                                    printf("%f         %f       %f       %f      %f       \n", xa, fxa, fdxa, xn, error2);

                                    xa = xn;


                                    } while(error2>=ep);
                                    break;
                                }

                            }
                            break;
                          }//TERMINA EULER MENOS X
                        } //TERMINA
                         break;
                        } // TERMINA NEWTON-RAPHSON
                            case 3: //SECANTE
                                {
                                    printf("\n El metodo de la secante consiste en acercarse a la raiz de la funcion simulando un circulo\n y una recta que toca 2 puntos de la circunferencia\n");
                                    printf("\n Por favor elija que funcion desea evaluar? \n1 =  (e^-x)-x\n2 =  (x^10)-1\n 3 = cos(x)-x\n 4 = ");

                                    break;
                                }
	}//TERMINA ELECCION DE METODO






	return 0;
}
