/*
 * morse_to_light_m32u4.c
 * Morse Code to Light
 * Created: 5/30/2019 2:53:52 PM
 * Author : PJS
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include "lightfAndMore.h"


int main(void)
{	
	DDRB |= (1 << DDB0);
	DDRD |= (1 << DDD0)|(1 << DDD1)|(1 << DDD4); 
	

while(1)
	{
	char inputMorse[128] = {0};//".... . .-.. .-.. --- / .-- --- .-. .-.. -.. -.-.--"; //Hello world!
	short orderN = 0;
	short MSECONDS = 5000;
	if (PIND0&0b00000001 || PIND1&0b00000010 || PIND4&0b00010000)
	{
		while (orderN < 128 && waitTime(MSECONDS))
		{
			if (PIND0&0b00000001)
			{
				inputMorse[orderN++] = '.';
				MSECONDS = 5000;
			}
			else if (PIND1&0b00000010)
			{
				inputMorse[orderN++] = '-';
				MSECONDS = 5000;
			}
			else if (PIND4&0b00010000)
			{
				inputMorse[orderN++] = ' ';
				MSECONDS = 5000;
			}
		}
	}
}
	
	lightf(inputMorse);		
}