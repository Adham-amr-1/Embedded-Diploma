#include "ADC.h"

void ADC_vInit(){
	// Enable The ADC
	SET_BIT(ADCSRA,ADEN);
	ADC_Vref();
	ADC_CLK();
}

u16 ADC_u16Read(){
	u16 RETURN_VALUE;
	// Choose the pin where the Sensor is connected to
	#if ACCURACY
	// With Accuracy ( ADLAR = 0 )
	// Set the Right adjust register ( Least 8-bits stored in ADCL )
	CLEAR_BIT(ADMUX,ADLAR);
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC));
	RETURN_VALUE = ADCL;
	RETURN_VALUE |= ( ADCH<<EIGHT ) ;
	
	#else 
	// Without Accuracy ( ADLAR = 1 )
	// Set the Left adjust register ( Most 8-bits stored in ADCH )
	SET_BIT(ADMUX,ADLAR);
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC));
	RETURN_VALUE = ( ADCH<<TWO );
	#endif
	
	return RETURN_VALUE;
}

void ADC_Vref(){
	// Selecting the Vref of the ADC
	// Turn off Internal Resistance ( Default )
	// Vref from the Aref PIN
	#if VREF_FROM_AREF_PIN
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
	// Internal Vref = 2.56 v
	#elif VREF_IS_INTERNAL
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
	// Vref from Avcc with connecting 10 u Cap to Aref Pin
	#elif VCC_AND_CAP
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
	#endif
}

void ADC_CLK(){
	#if DIVISON_BY_2 
	// If MC Freq = 8 MHZ , ADC Freq = 4 MHZ
	SET_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
	#elif DIVISON_BY_4
	// If MC Freq = 8 MHZ , ADC Freq = 2 MHZ
	CLEAR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
	#elif DIVISON_BY_8
	// If MC Freq = 8 MHZ , ADC Freq = 1 MHZ
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
	#elif DIVISON_BY_16
	// If MC Freq = 8 MHZ , ADC Freq = 500 KHZ
	CLEAR_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#elif DIVISON_BY_32
	// If MC Freq = 8 MHZ , ADC Freq =  250 KHZ
	SET_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#elif DIVISON_BY_64
	// If MC Freq = 8 MHZ , ADC Freq = 125 KHZ
	CLEAR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#elif DIVISON_BY_128
	// If MC Freq = 8 MHZ , ADC Freq = 62.5 KHZ
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#endif
}

void ADC_Interrupt(){
	// Set Interrupt of ADC ( Set I-Bit at first )
	SET_BIT(ADCSRA,ADIE);
}

void ADC_PinRead(u8 PIN_NO){
	switch(PIN_NO){
		case PIN_NO_0 :
		CLEAR_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		break;
		case PIN_NO_1 :
		SET_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		break;
		case PIN_NO_2 :
		CLEAR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		break;
		case PIN_NO_3 :
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		break;
		case PIN_NO_4 :
		CLEAR_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		break;
		case PIN_NO_5 :
		SET_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		break;
		case PIN_NO_6 :
		CLEAR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		break;
		case PIN_NO_7 :
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		break;
	}
}