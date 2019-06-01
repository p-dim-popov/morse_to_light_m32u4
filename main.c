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
#include "lightf.h"


int main(void)
{	
	char inputMorse[128] = ".... . .-.. .-.. --- / .-- --- .-. .-.. -.. -.-.--"; //Hello world!
	
	lightf(inputMorse);		
}