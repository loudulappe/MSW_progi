/*
 * array.c
 *
 * Created: 02.02.2023 15:56:57
 * Author : e1Derung
 */
// 1)       
//      for (uint16_t i=0; i<SIZE; i=i+1)
//      {
//          if (zufallszahlen[i]==7)
//          {
//              ledWriteAll(0xffff);
//          }
//      } 
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
//      for (uint16_t i=0; i<SIZE; i=i+1)
//      {
//          if (zufallszahlen[i]==15)
//          {
//              counter=i;
//          }
//      }
// 
//      //ausgabe
//      ledWriteAll(counter);
//      break;
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
//6)      
//         counter=0;
//         for (uint16_t i=0; i<SIZE; i=i+1)
//         {
//          if (counter<(zufallszahlen[i]))
//          {
//          counter=zufallszahlen[i];
//          place=i;
//          }
//      }
//
#include "ADtreiber.h"
#define systemtakt      30
#define SIZE            100
#pragma GCC optimize 0

int main(void)
{
    initBoard();
    uint16_t testArray[SIZE] =
    {
        43281, 22997, 41494, 34816, 12464,  3561, 43247, 23766, 19368,  7613,
        35475, 41126, 21888, 28764, 23863, 25549, 46667, 61837, 32188, 63352,
        14076, 12714, 40745, 27126, 12280, 29764, 12883, 63651, 16275,  4568,
         5510, 29348, 20128,  4002, 36525,  9829, 39160, 46921,  4640, 58713,
        27752, 14700, 63101,  9603, 16441,  6517, 20308, 44992, 10797, 57575,
        18275, 53024, 18787, 63561,  8630, 37153, 34816, 15937, 17232, 30198,
        55355, 57460,  5127, 36927, 15777,  4002, 32450, 18189,  8480, 16396,
        27911, 11533, 16461, 40099, 31239, 53667, 39818,  2253, 62228,  2284,
         5797, 65271,  1783, 61756, 23743, 26248,  2212,  4002, 31030, 47946,
        11933, 22958, 61231, 57095, 39850, 39160, 47316, 53204, 20357,  2753
    };
    uint16_t Ergebnis[SIZE] ={0};
    uint16_t counter=0;
    uint16_t border=0;
    uint16_t stelle=0;
    uint16_t zwischenspeicher2=0;
    uint16_t limit=0;
    uint16_t zifferkontrolle=0;
    ledWriteAll(0);
    for (uint16_t i=0; i<SIZE; i=i+1)
        {
        if (testArray[i]>limit)
        {
            limit=testArray[i];
        }
    }
    for (uint16_t i=0; i<=limit; i=i+1)
    {

        for (uint16_t j=0; j<SIZE; j=j+1)
        {
            if (testArray[j]==i)
            {
                counter=counter+1;
            }
        }
        border=stelle+counter;
        while (stelle<border)
        {
            Ergebnis[stelle]=i;
            stelle=stelle+1;
        }
        counter=0;
    }
    ledWriteAll(0xffff);
}

