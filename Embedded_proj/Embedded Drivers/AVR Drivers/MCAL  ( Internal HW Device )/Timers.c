#include "Timers.h"

/*====================================================================================*/
/* Timer0 Funtions */
/*====================================================================================*/

void Timer0_Set_Clk(){
	#if TIMER0_NO_CLK
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	#elif TIMER0_DIVIDE_CLK_BY_1
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	#elif TIMER0_DIVIDE_CLK_BY_8
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	#elif TIMER0_DIVIDE_CLK_BY_64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	#elif TIMER0_DIVIDE_CLK_BY_256
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#elif TIMER0_DIVIDE_CLK_BY_1024
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#endif
}
void Timer0_Pin_T0_Sense(){
	#if TIMER0_EXTERNAL_FALLING_EDGE
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#elif TIMER0_EXTERNAL_RISING_EDGE
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#endif
}
void Timer0_Set_OverFlow_Mode(){
	/* Set the Timer Mode to overflow mode */
	CLEAR_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	/* Set the Timer Clk */
	Timer0_Set_Clk();
	/* Set Global Interrupt */
	Set_Global_Interrupt();
	/* Set TOIE0 BIT */
	SET_BIT(TIMSK,TOIE0);
}
void Timer0_Set_CTC_Mode(u8 OCRO_VALUE){
	/* Set the Timer Mode to CTC mode */
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0 = OCRO_VALUE;
	/* Set the Timer Clk */
	Timer0_Set_Clk();
	/* Set Global Interrupt */
	Set_Global_Interrupt();
	/* Set OCIE0 BIT */
	SET_BIT(TIMSK,OCIE0);
}
void Timer0_CTC_Generate_Signal(u8 OCRO_VALUE){
	DIO_Set_Pin_Direction(PORT_B,PIN_NO_3,OUTPUT);
	/* Set the Timer Mode to CTC mode */
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0 = OCRO_VALUE;
	/* Set the Timer Clk */
	Timer0_Set_Clk();
	/* Set Signal to be Toggle at Compare Match*/
	/* Pin PB3 ( OCO ) */
	SET_BIT(TCCR0,COM00);
	CLEAR_BIT(TCCR0,COM01);

}
void Timer0_Set_FastPWM_Mode(u8 OCRO_VALUE){
	DIO_Set_Pin_Direction(PORT_B,PIN_NO_3,OUTPUT);
	/* Set the Timer Mode to Fast PWM mode */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0 = OCRO_VALUE;
	/* Set the Timer Clk */
	Timer0_Set_Clk();
	/* Set PWM On / Off  */
	#if TIMER0_SET_OCO_ON_BOTTOM
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#elif TIMER0_SET_OCO_ON_COMPARE_MATCH
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#endif
}
void PWM_Timer0_Generate(u8 SPEED_PERCENT){
	Timer0_Set_FastPWM_Mode((SPEED_PERCENT * 2.56));
}
void Timer0_Set_PhaseCorrect_PWM_Mode(u8 OCRO_VALUE){
	DIO_Set_Pin_Direction(PORT_B,PIN_NO_3,OUTPUT);
	/* Set the Timer Mode to Phase Correct PWM mode */
	SET_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0 = OCRO_VALUE;
	/* Set the Timer Clk */
	Timer0_Set_Clk();
	#if TIMER0_SET_OCO_ON_DownCounting
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#elif TIMER0_SET_OCO_ON_UpCounting
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#endif
}

/*====================================================================================*/
/* Timer 1 Functions*/
/*====================================================================================*/

void Timer1_Set_Clk(){
	#if TIMER1_NO_CLK
	CLEAR_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	#elif TIMER1_DIVIDE_CLK_BY_1
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	#elif TIMER1_DIVIDE_CLK_BY_8
	CLEAR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	#elif TIMER1_DIVIDE_CLK_BY_64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	#elif TIMER1_DIVIDE_CLK_BY_256
	CLEAR_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	#elif TIMER1_DIVIDE_CLK_BY_1024
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	#endif
}
void Timer1_Pin_T1_Sense(){
	#if TIMER1_EXTERNAL_FALLING_EDGE
	CLEAR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	#elif TIMER1_EXTERNAL_RISING_EDGE
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	#endif
}
void Timer1_Set_OverFlow_Mode(){
	/* Set the Timer Mode to overflow mode */
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set Global Interrupt */
	Set_Global_Interrupt();
	/* Set TOIE0 BIT */
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_Set_OCRA_CTC_Mode(u16 OCR1A_VALUE){
	/* Set the Timer Mode to CTC A mode */
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	/* load a value in OCR0 */
	OCR1A = OCR1A_VALUE;
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set Global Interrupt */
	Set_Global_Interrupt();
	/* Set OCIE0 BIT */
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_Set_ICR_CTC_Mode(u16 ICR1_VALUE){
	/* Set the Timer Mode to CTC ICR mode */
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR0 */
	ICR1 = ICR1_VALUE;
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set Global Interrupt */
	Set_Global_Interrupt();
	/* Set OCIE0 BIT */
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_Set_OCRB_CTC_Mode(u16 OCR1B_VALUE){
	/* Set the Timer Mode to CTC B mode */
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	/* load a value in OCR0 */
	OCR1B = OCR1B_VALUE;
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set Global Interrupt */
	Set_Global_Interrupt();
	/* Set OCIE0 BIT */
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_CTC_OCRA_Generate_Signal(u16 OCR1A_VALUE){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_5,OUTPUT);
	/* Set the Timer Mode to CTC mode */
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	/* load a value in OCR0 */
	OCR1A = OCR1A_VALUE;
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set Signal to be Toggle at Compare Match*/
	/* Pin PB3 ( OCO ) */
	SET_BIT(TCCR1A,COM1A0);
	CLEAR_BIT(TCCR1A,COM1A1);

}
void Timer1_CTC_OCRB_Generate_Signal(u16 OCR1B_VALUE){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_4,OUTPUT);
	/* Set the Timer Mode to CTC mode */
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	/* load a value in OCR0 */
	OCR1B = OCR1B_VALUE;
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set Signal to be Toggle at Compare Match*/
	/* Pin PB3 ( OCO ) */
	SET_BIT(TCCR1A,COM1B0);
	CLEAR_BIT(TCCR1A,COM1B1);
}
void Timer1_Set_OCA_FastPWM_Mode(u16 OCR1A_VALUE){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_5,OUTPUT);
	/* Set the Timer Mode to Fast PWM mode */
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR0 */
	OCR1A = OCR1A_VALUE;
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set PWM On / Off  */
	#if TIMER1_SET_OC1A_ON_BOTTOM
	CLEAR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#elif TIMER1_SET_OC1A_ON_COMPARE_MATCH
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#endif
}
void Timer1_Set_OCB_FastPWM_Mode(u16 OCR1B_VALUE){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_4,OUTPUT);
	/* Set the Timer Mode to Fast PWM mode */
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR0 */
	OCR1B = OCR1B_VALUE;
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set PWM On / Off  */
	#if TIMER1_SET_OC1B_ON_BOTTOM
	CLEAR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#elif TIMER1_SET_OC1B_ON_COMPARE_MATCH
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#endif
}
void Timer1_Set_OCA_FastPWM_Mode_Using_Bits(){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_5,OUTPUT);
	/* Set the Timer Mode to Fast PWM mode */
	#if FAST_PWM_8_BIT
	SET_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#elif FAST_PWM_9_BIT
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#elif FAST_PWM_10_BIT
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#endif
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set PWM On / Off  */
	#if TIMER1_SET_OC1A_ON_BOTTOM
	CLEAR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#elif TIMER1_SET_OC1A_ON_COMPARE_MATCH
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#endif
}
void Timer1_Set_OCB_FastPWM_Mode_Using_Bits(){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_4,OUTPUT);
	/* Set the Timer Mode to Fast PWM mode */
	#if FAST_PWM_8_BIT
	SET_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#elif FAST_PWM_9_BIT
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#elif FAST_PWM_10_BIT
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#endif
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set PWM On / Off  */
	#if TIMER1_SET_OC1B_ON_BOTTOM
	CLEAR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#elif TIMER1_SET_OC1B_ON_COMPARE_MATCH
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#endif
}
void PWM_Timer1A_Generate(u16 SPEED_PERCENT){
	Timer1_Set_OCA_FastPWM_Mode((SPEED_PERCENT * 655.35));
}
void PWM_Timer1B_Generate(u16 SPEED_PERCENT){
	Timer1_Set_OCB_FastPWM_Mode((SPEED_PERCENT * 655.35));
}
void Timer1_Set_ICU_Rising_Edge(){
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	SET_BIT(TCCR1B,ICNC1);
	SET_BIT(TCCR1B,ICES1);
}
void Timer1_Set_ICU_Falling_Edge(){
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	SET_BIT(TCCR1B,ICNC1);
	CLEAR_BIT(TCCR1B,ICES1);
}
void Clear_ICF1_BIT(){
	SET_BIT(TIFR,ICF1);
}
void Timer1_Set_OCA_PhaseCorrect_PWM_Mode_Using_Bits(){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_5,OUTPUT);
	/* Set the Timer Mode to Fast PWM mode */
	#if PHASE_CORRECT_PWM_8_BIT
	SET_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#elif PHASE_CORRECT_PWM_9_BIT
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#elif PHASE_CORRECT_PWM_10_BIT
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#endif
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set PWM On / Off  */
	#if TIMER1_SET_OCRA_ON_DownCounting
	CLEAR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#elif TIMER1_SET_OCRA_ON_UpCounting
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#endif
}
void Timer1_Set_OCB_PhaseCorrect_PWM_Mode_Using_Bits(){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_4,OUTPUT);
	/* Set the Timer Mode to Fast PWM mode */
	#if PHASE_CORRECT_PWM_8_BIT
	SET_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#elif PHASE_CORRECT_PWM_9_BIT
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#elif PHASE_CORRECT_PWM_10_BIT
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	#endif
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	/* Set PWM On / Off  */
	#if TIMER1_SET_OCRB_ON_DownCounting
	CLEAR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#elif TIMER1_SET_OCRB_ON_UpCounting
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#endif
}
void Timer1_Set_OCA_PhaseCorrect_PWM_Mode(u16 OCR1A_VALUE){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_5,OUTPUT);
	/* Set the Timer Mode to Phase Correct PWM mode*/
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR0 */
	OCR1A = OCR1A_VALUE;
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	#if TIMER1_SET_OCRA_ON_DownCounting
	CLEAR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#elif TIMER1_SET_OCRA_ON_UpCounting
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#endif
}
void Timer1_Set_OCB_PhaseCorrect_PWM_Mode(u16 OCR1B_VALUE){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_5,OUTPUT);
	/* Set the Timer Mode to Phase Correct PWM mode*/
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR0 */
	OCR1B = OCR1B_VALUE;
	/* Set the Timer Clk */
	Timer1_Set_Clk();
	#if TIMER1_SET_OCRB_ON_DownCounting
	CLEAR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#elif TIMER1_SET_OCRB_ON_UpCounting
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#endif
}

/*====================================================================================*/
/* Timer 2 Functions*/
/*====================================================================================*/

void Timer2_Clk_Select(){
	#if TIMER2_EXTERNAL
	SET_BIT(ASSR,AS2);
	#elif TIMER2_INTERNAL
	CLEAR_BIT(ASSR,AS2);
	#endif
}
void Timer2_Set_Clk(){
	// Select the source of CLK
	Timer2_Clk_Select();
	#if TIMER2_NO_CLK
	CLEAR_BIT(TCCR2,CS20);
	CLEAR_BIT(TCCR2,CS21);
	CLEAR_BIT(TCCR2,CS22);
	#elif TIMER2_DIVIDE_CLK_BY_1
	SET_BIT(TCCR2,CS20);
	CLEAR_BIT(TCCR2,CS21);
	CLEAR_BIT(TCCR2,CS22);
	#elif TIMER2_DIVIDE_CLK_BY_8
	CLEAR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLEAR_BIT(TCCR2,CS22);
	#elif TIMER2_DIVIDE_CLK_BY_32
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLEAR_BIT(TCCR2,CS22);
	#elif TIMER2_DIVIDE_CLK_BY_64
	CLEAR_BIT(TCCR2,CS20);
	CLEAR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	#elif TIMER2_DIVIDE_CLK_BY_128
	SET_BIT(TCCR2,CS20);
	CLEAR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	#elif TIMER2_DIVIDE_CLK_BY_256
	CLEAR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	#elif TIMER2_DIVIDE_CLK_BY_1024
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	#endif
}
void Timer2_Set_OverFlow_Mode(){
	/* Set the Timer Mode to overflow mode */
	CLEAR_BIT(TCCR2,WGM20);
	CLEAR_BIT(TCCR2,WGM21);
	/* Set the Timer Clk */
	Timer2_Set_Clk();
	/* Set Global Interrupt */
	Set_Global_Interrupt();
	/* Set TOIE0 BIT */
	SET_BIT(TIMSK,TOIE2);
}
void Timer2_Set_CTC_Mode(u8 OCR2_VALUE){
	/* Set the Timer Mode to CTC mode */
	CLEAR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	/* load a value in OCR2 */
	OCR2 = OCR2_VALUE;
	/* Set the Timer Clk */
	Timer2_Set_Clk();
	/* Set Global Interrupt */
	Set_Global_Interrupt();
	/* Set OCIE0 BIT */
	SET_BIT(TIMSK,OCIE2);
}
void Timer2_CTC_Generate_Signal(u8 OCR2_VALUE){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_7,OUTPUT);
	/* Set the Timer Mode to CTC mode */
	CLEAR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	/* load a value in OCR2 */
	OCR2 = OCR2_VALUE;
	/* Set the Timer Clk */
	Timer2_Set_Clk();
	/* Set Signal to be Toggle at Compare Match*/
	/* Pin PB3 ( OCO ) */
	SET_BIT(TCCR2,COM20);
	CLEAR_BIT(TCCR2,COM21);
}
void Timer2_Set_FastPWM_Mode(u8 OCR2_VALUE){
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_7,OUTPUT);
	/* Set the Timer Mode to Fast PWM mode */
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	/* load a value in OCR0 */
	OCR2 = OCR2_VALUE;
	/* Set the Timer Clk */
	Timer2_Set_Clk();
	/* Set PWM On / Off  */
	#if TIMER2_SET_OC2_ON_BOTTOM
	CLEAR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#elif TIMER2_SET_OC2_ON_COMPARE_MATCH
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#endif
}
void PWM_Timer2_Generate(u8 SPEED_PERCENT){
	Timer2_Set_FastPWM_Mode((SPEED_PERCENT * 2.56));
}
void Timer2_Set_PhaseCorrect_PWM_Mode(u8 OCR2_VALUE){
	DIO_Set_Pin_Direction(PORT_B,PIN_NO_3,OUTPUT);
	/* Set the Timer Mode to Phase Correct PWM mode */
	SET_BIT(TCCR2,WGM20);
	CLEAR_BIT(TCCR2,WGM21);
	/* load a value in OCR2 */
	OCR2 = OCR2_VALUE;
	/* Set the Timer Clk */
	Timer2_Set_Clk();
	#if TIMER2_SET_OC2_ON_DownCounting
	CLEAR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#elif TIMER2_SET_OC2_ON_UpCounting
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#endif
}

/*====================================================================================*/
/* WatchDog Timer Functions*/
/*====================================================================================*/

void WatchDog_Set_Clk(){
	#if 0
	#endif
}
void WatchDog_Sleep(){
	WatchDog_Set_Clk();
}























/*====================================================================================*/
