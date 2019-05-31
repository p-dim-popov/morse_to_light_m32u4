/*
 * Input to Light Function
 * 
 * Created: 5/30/2019
 * Author : PJS
 */ 
void lightf (char morseCode[128])
{
	short morseUnit = 75;
	
	//PORTB |= (1 << PORTB0); //Turns off the diode.
	//PORTB &= ~(1 << PORTB0); //Turns on the diode.
	
	for (short j = 0; j < strlen(morseCode); j++)
	{
		if (morseCode[j] == '.')
		{
			PORTB &= ~(1 << PORTB0);
			_delay_ms(morseUnit);
			
			PORTB |= (1 << PORTB0);
			_delay_ms(morseUnit);
		}
		else if (morseCode[j] == ' ')
		_delay_ms(2*morseUnit);
		else if (morseCode[j] == '/')
		_delay_ms(3*morseUnit);
		else if (morseCode[j] == '-')
		{
			PORTB &= ~(1 << PORTB0);
			_delay_ms(3*morseUnit);
			PORTB |= (1 << PORTB0);
			_delay_ms(morseUnit);
		}
	}
}
