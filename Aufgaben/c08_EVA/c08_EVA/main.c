/*
 * c08_EVA.c
 *
 * Created: 27.10.2022 09:55:40
 * Author : e1Derung
 */
#include "ADtreiber.h"

#define IMWOHNZIMMER 0x01
#define IMBAD 0x04
#define IMOG 0x10
#define IMOGG 0x20
#define IMEG 0x40
#define IMLS 0x80
   
#define OMWOHNZIMMER 0x01
#define OMBAD 0x02
#define OMSPIEGEL 0x04
#define OMOG 0x80
#define OMEG 0x40

int main(void)
{    
    uint8_t ilights=0;
    
    #define IMWOHNZIMMER 0x01
    #define IMBAD 0x04
    #define IMOG 0x10
    #define IMOGG 0x20
    #define IMEG 0x40
    #define IMLS 0x80
     
    #define OMWOHNZIMMER 0x01
    #define OMBAD 0x02
    #define OMSPIEGEL 0x04
    #define OMOG 0x80
    #define OMEG 0x40
    
    uint8_t iwohnzimmer=0;
    uint8_t ibad=0;
    uint8_t iOG=0;
    uint8_t iOGG=0;
    uint8_t iEG=0;
    uint8_t iLS=0;   
    
    uint8_t owohnzimmer=0;
    uint8_t obad=0;
    uint8_t ospiegel=0;
    uint8_t oOG=0;
    uint8_t oEG=0;

    initBoard();
    while (1) 
    {
        ilights = SwitchReadAll();
        iwohnzimmer = ilights & OMWOHNZIMMER;
        ibad = ilights & IMBAD;
        iOG = ilights & IMOG;
        iOGG = ilights & IMOGG;
        iEG = ilights & IMEG;
        iLS = ilights & IMLS;
        
        if ((iOG||iOGG||iEG)&&(!iLS))
        {
            oOG= OMOG|OMEG;
            oEG=OMOG|OMEG;
        } 
        else
        {
            oOG=0;
            oEG=0;
        }
        if (ibad)
        {
            obad=OMBAD;
            ospiegel=OMSPIEGEL;
        } 
        else
        {
            obad=0;
            ospiegel=0;
        }
        if (iwohnzimmer)
        {
            owohnzimmer=OMWOHNZIMMER;
        } 
        else
        {
            owohnzimmer=0;
        }
        
        ledWriteAll(owohnzimmer|obad|ospiegel|oOG|oEG);
    }
}

