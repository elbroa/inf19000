/*
 *
 *
 *Nom du fichier : probleme1.cpp
 *Section : 01
 *Equipe : 08
 *Auteurs : Jeremy Perreault (1903274), Eloise Brosseau (2011037) et Douaa Bergheul (2006583)
 *
 */

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

/*************************************************************************/ /**
*  Déterminer si le bouton-poussoir sur D2 a été appuyé et
* relâché \return  \c true si le bouton-poussoir a été appuyé
* et relaĉhé.
*/
bool isD2Pressed()
{
    if ((PIND & (1 << PIND2)))
    {
        _delay_ms(10);
        if (!(PIND & (1 << PIND2)))
        {
            _delay_ms(10);
            return (!(PIND & (1 << PIND2)));
        }
    }
    return false;
}

int main()
{
    DDRA = 0xff;
    DDRB = 0xff;
    DDRD = 0x00;

    const uint8_t rouge = 0x01;
    //const uint8_t vert = 0x02;
    //const uint8_t eteint = 0x00;

    //bool etat = true;

    while (true)
    {
        if(isD2Pressed())
        {
            PORTA = rouge;
            PORTB = rouge;
            /*
            for (int i = 100; i > 0; i--)
            {
                
                for (int j = 0; j < i; j++)
                {
                    _delay_ms(1);
                }
                PORTA = eteint;
                PORTB = eteint;
                for (int j = 0; j < 100 - i; j++)
                {
                    _delay_ms(1);
                }
            }*/
        }
        /*if(isD2Pressed() && !etat)
        {
            for(int i = 100; i > 0; i--)
            {    
                PORTA = vert;
                PORTB = vert;
                for(int j = 0; j < i; j++)
                {
                    _delay_ms(1);
                }
                PORTA = eteint;
                PORTB = eteint;
                for (int j = 0; j < 100 - i; j++)
                {
                    _delay_ms(1);
                }
            }
        etat = true;
        }*/
    }
    return 0;
}
