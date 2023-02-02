/*
 * array.c
 *
 * Created: 02.02.2023 15:56:57
 * Author : e1Derung
 */
// 1)       
// for (uint16_t i=0; i<SIZE; i=i+1)
// {
//     if (zufallszahlen[i]==7)
//     {
//         ledWriteAll(0xffff);
//     }
// } 
// 2)
//         for (uint16_t i=0; i<SIZE; i=i+1)
//         {
//             if (!zufallszahlen[i])
//             {
//                 counter=counter+1;
//             }
//         }
// 
//         //ausgabe
//         ledWriteAll(counter);
//         break;
// 3)
//         for (uint16_t i=0; i<SIZE; i=i+1)
//         {
//             if (zufallszahlen[i]==15)
//             {
//                 counter=i;
//                 break;
//             }
//         }
// 
//         //ausgabe
//         ledWriteAll(counter);
//         break;
// 4)        counter=0;
// for (uint16_t i=0; i<SIZE; i=i+1)
// {
//     if (zufallszahlen[i]==15)
//     {
//         counter=i;
//     }
// }
// 
// //ausgabe
// ledWriteAll(counter);
// break;
// 5)
//         counter=0;
//         for (uint16_t i=0; i<SIZE; i=i+1)
//         {
//             if (counter<(zufallszahlen[i]))
//             {
//                 counter=zufallszahlen[i];
//             }
//         }
// 
//         //ausgabe
//         ledWriteAll(counter);
//         break;


#include "ADtreiber.h"
#define systemtakt      30
#define SIZE            200

int main(void)
{
    initBoard();
    uint16_t zufallszahlen [SIZE] = {
        10,  2, 11,  7,  3,  3,  7,  9,  3,  6,
        13,  5, 12, 14,  0,  0, 12,  8,  5, 15,
        15,  3,  0, 14,  0,  0,  0, 13,  0,  8,
        7, 13,  5, 10,  8, 15,  1,  0,  6,  7,
        2,  8,  0,  8, 12, 10,  8, 10, 13,  0,
        0,  9,  2,  1,  4, 15,  9, 14,  6,  1,
        3,  7,  0,  4,  8, 14,  7, 13, 14,  2,
        2,  8,  0,  8, 12, 10,  8, 10, 13,  0,
        8,  0, 11, 13,  1,  0,  0,  9,  8,  0,
        6,  5, 10, 10,  6, 11,  8, 11,  7,  3,
        13,  5,  4,  3,  2, 11, 13, 10, 15,  2,
        2,  8,  0,  8, 12, 10,  8, 10, 13,  0,
        11,  6,  4,  5,  7,  0, 13,  5,  2, 10,
        11, 15, 11,  8, 10, 14,  9,  8,  7,  3,
        13,  9,  5, 10,  5,  8,  0, 13,  8,  7,
        4, 11, 10, 14,  8, 11,  4, 12,  6, 11,
        15, 14, 13,  0,  8, 11,  8,  0,  5, 12,
        12, 15,  7, 12,  4, 13, 12,  1,  4,  1,
        5,  7,  9,  8,  3,  3,  7, 12,  1,  2,
        6,  8,  9,  7,  0,  3,  8,  6,  6, 11};
        uint16_t counter=0;
        uint16_t place=0;
     
    while (1) 
    {
//eingabe

        
//verarbeitung
        counter=0;
        for (uint16_t i=0; i<SIZE; i=i+1)
        {
            if (counter<(zufallszahlen[i]))
            {
                counter=zufallszahlen[i];
                place=i;
            }
        }

//ausgabe
        ledWriteAll(place);
        break;
    }
}

