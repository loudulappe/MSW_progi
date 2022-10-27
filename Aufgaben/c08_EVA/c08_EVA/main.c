/*
 * c08_EVA.c
 *
 * Created: 27.10.2022 09:55:40
 * Author : e1Derung
 */
#include "ADtreiber.h"


int main(void)
{    
    uint8_t ilights=0;
    
    uint8_t imwohnzimmer=0x01;
    uint8_t imbad=0x04;
    uint8_t imOG=0x10;
    uint8_t imOGG=0x20;
    uint8_t imEG=0x40;
    uint8_t imLS=0x80;
    
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
    
    uint8_t omwohnzimmer=0x01;
    uint8_t ombad=0x02;
    uint8_t omspiegel=0x04;
    uint8_t omOG=0x80;
    uint8_t omEG=0x40;
    initBoard();
    while (1) 
    {
        ilights = SwitchReadAll();
        iwohnzimmer = ilights&imwohnzimmer;
        ibad = ilights&imbad;
        iOG = ilights&imOG;
        iOGG = ilights&imOGG;
        iEG = ilights&imEG;
        iLS = ilights&imLS;
        
        if ((iOG||iOGG||iEG)&&(!iLS))
        {
            oOG=omOG|omEG;
            oEG=omOG|omEG;
        } 
        else
        {
            oOG=0;
            oEG=0;
        }
        if (ibad)
        {
            obad=ombad;
            ospiegel=omspiegel;
        } 
        else
        {
            obad=0;
            ospiegel=0;
        }
        if (iwohnzimmer)
        {
            owohnzimmer=omwohnzimmer;
        } 
        else
        {
            owohnzimmer=0;
        }
        
        ledWriteAll(owohnzimmer|obad|ospiegel|oOG|oEG);
    }
}

