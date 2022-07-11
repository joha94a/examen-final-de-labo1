#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "rlutil.h"
#include "funciones.h"



int numeroAlAzar()
{

    int numero;

    numero = (rand()% 6) +1;

    return numero;
}


/*Funcion para ver que jugador comienza*/
void VerQuienComienza (_cerdo1, _cerdo2)
{
    string _cerdo1, _cerdo2, cerdoQueComienza, cerdoSegundo;
    bool repetir = true;
    int tirada1 = 0, tirada2 = 0, dado1, dado2, dado3, dado4;

    //entra una vez y pone la bandera en false
    while(repetir == true)
    {
        repetir = false;

        cout << _cerdo1 << endl << "... Tira los dados" << endl << endl;
        rlutil::anykey();

        dado1 = numeroAlAzar();
        dado2 = numeroAlAzar();

        tirada1= dado1 + dado2;

        cout << " [ " << dado1 << " ] ";
        cout << " [ " << dado2 << " ] " << endl;

        cout << endl << "Hiciste " << tirada1 << " puntos" << endl << endl;


        cout << endl << _cerdo2 <<", tu turno: " << endl << endl;
        rlutil::anykey();

        dado3 = numeroAlAzar();
        dado4 = numeroAlAzar();

        tirada2= dado3 + dado4;

        cout << " [ " << dado3 << " ] ";
        cout << " [ " << dado4 << " ] " << endl;

        cout << endl << "Hiciste " << tirada2 << " puntos" << endl << endl;

        //analisis de las tiradas del jugador 1 y 2

        if(tirada1 == tirada2)
        {
            if(dado1 == dado3 || dado1 == dado4 && dado2 == dado3 || dado2 == dado4)
            {
                repetir = true;
                cout << "Empataron, vuelven a tirar" << endl << endl;
            }

            else if(dado1 > dado3 || dado1 > dado4 && dado2 > dado3 || dado2 > dado4)
            {

                cerdoQueComienza = _cerdo1;
                cerdoSegundo = _cerdo2;

                cout << endl << "Comienza: " << cerdoQueComienza << endl << " Mucha Suerte!" << endl;

                rlutil::anykey();
                system("cls");
            }

            else
            {
                cerdoQueComienza = _cerdo2;
                cerdoSegundo = _cerdo1;

                cout << endl << "Comienza: " << cerdoQueComienza << endl << " Mucha Suerte!" << endl;

                rlutil::anykey();
                system("cls");
            }

        }
        else if(tirada1 > tirada2)
        {
            cerdoQueComienza = _cerdo1;
            cerdoSegundo = _cerdo2;

            cout << endl << "Comienza: " << cerdoQueComienza << endl << " Mucha Suerte!" << endl;

            rlutil::anykey();
            system("cls");
        }
        else
        {
            cerdoQueComienza = cerdo2;
            cerdoSegundo = cerdo1;

            cout << endl << "Comienza: " << cerdoQueComienza << endl << " Mucha Suerte!" << endl;

            rlutil::anykey();
            system("cls");
        }

    }

}


void JugarRondas()
{
    //comienzan las rondas
    bool hundido = false, SigueJugando= true;
    int TrufasTotales_C1 = 0, TrufasTotales_C2 = 0, TrufasActuales_C1, TrufasActuales_C2;

    for(int i=0; i < 5; i++)
    {
        cout << "Ronda numero: " << i+1 << endl << "_____________________________" << endl << endl;
        //mientras se den estas condiciones juegan con dos dados
        while(hundido== false || (TrufasTotales_C1 <= 50 && TrufasTotales_C2 <= 50))
        {
            //jugador 1
            while(SigueJugando == true)
            {
                SigueJugando = false;

                dado1 = numeroAlAzar();
                dado2 = numeroAlAzar();

                TrufasActuales_C1= dado1 + dado2;

                cout << " [ " << dado1 << " ] ";
                cout << " [ " << dado2 << " ] " << endl << endl;

                SigueJugando= analizarJugada(dado1,dado2);

                if(SigueJugando == true)
                {
                    cout << "Te toca tirar otra vez" << endl;
                    rlutil::anykey();
                }
                else
                {
                    cout << "Perdes tu turno" << endl;
                    rlutil::anykey();
                }

            }

            //jugador 2

            SigueJugando == true;
            while(SigueJugando == true)
            {

                dado1 = numeroAlAzar();
                dado2 = numeroAlAzar();

                TrufasActuales_C1= dado1 + dado2;

                cout << " [ " << dado1 << " ] ";
                cout << " [ " << dado2 << " ] " << endl << endl;

                SigueJugando= analizarJugada(dado1,dado2);

                if(SigueJugando == true)
                {
                    cout << "Te toca tirar otra vez" << endl;
                    rlutil::anykey();
                }
                else
                {
                    cout << "Perdes tu turno" << endl;
                    rlutil::anykey();
                }
            }
        }


    }

}


/*Funcion que comienza el juego*/
void ComenzarJuego ()
{
    string cerdo1, cerdo2, cerdoQueComienza, cerdoSegundo;



    //Se ingresan los nombres de los jugadores

    cout << "Ingresa el nombre del jugador/a 1: " << endl;
    cin >> cerdo1;
    cout << endl << "Ingresa el nombre del jugador/a 2: " << endl;
    cin >> cerdo2;

    system("cls");

    cout << "Jugador 1: " << cerdo1 <<             "Jugador 2: " << cerdo2 << endl << "-----------------------------"<< endl;


    VerQuienComienza(string cerdo1, string cerdo2);
    JugarRondas();



}



/*string MostrarPantalla()
{
    cout << "Jugador 1: " << nombre1 <<             "Jugador 2: " << nombre2 << endl << "-----------------------------"<< endl;

    cout << "Ronda N°: " << ronda+1 <<  endl <<  "-----------------------------"<< endl << endl;


}

//condicionesDados(dado1,dado2);

    //cout << resultadoTrufas;
} */

bool preguntarSiSigue ()
{

    string quiereJugar;

    cout << "Queres seguir jugando?: S/N" << endl << endl;
    cin >> quiereJugar;


    if(quiereJugar == "s")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool analizarJugada(int dado1, int dado2)
{

    int TrufasActuales = 0, oink = 0, TrufasTotales;
    bool SigueJugando = false, hundido= false, respuesta=true;

    //si los dados son distintos y ninguno es uno
    if(dado1 != dado2 && dado1 != 1 && dado2 != 1)
    {
        //suma los dos dados y pregunta si quiere tirar otra vez
        TrufasActuales = dado1 + dado2;
        respuesta = preguntarSiSigue();
        return respuesta;

    }

    else if(dado1 == dado2 && dado1 != 1)
    {
        //suma oink y duplica el puntaje
        oink++;
        TrufasActuales = (dado1 + dado2) * 2 ;
        SigueJugando = true;

        return true;
    }

    else if(dado1 == 1 || dado2 == 1)
    {
        TrufasActuales = 0;
        SigueJugando = false;

        return false;
    }

    else if(dado1 == 1 && dado2 == 1)
    {
        TrufasActuales = 0;
        TrufasTotales = 0;
        hundido = true;
        SigueJugando = false;

        return false;
    }

}
