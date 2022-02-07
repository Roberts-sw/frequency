//in hardware.c zetten???
uint32_t micros(void);              //(from cpu.h)
uint32_t READfreq (void) 
{   //for now: test just 1 pulse, determine frequency from 1 complete cycle
    uint8_t startlevel=FASE1pulse;
    while(FASE1pulse==startlevel)   ;   //wait until pulse level changes
    uint32_t res=micros();              //remember start time
    while(FASE1pulse!=startlevel)   ;   //wait until pulse level changes
    while(FASE1pulse==startlevel)   ;   //wait until pulse level changes
    res=micros()-res;                   //== time difference for complete pulse
    res=10ul*M_(1)/res;                 //convert from [us] to [0,1Hz]
    return res;
}
