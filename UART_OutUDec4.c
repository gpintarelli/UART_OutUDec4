// By GBPintarelli
// 05/08/2016
// Turn the decimal value from the ADC to individual chars (and send then true UART)
// UARTCharPut Funciton: Sends  a char through UART
			  
void UART_OutUDec4(unsigned int n){		// n is the input 0 to 9999
	UARTCharPut(UART0_BASE, 0x30+n/1000);	// hundreds digit
	n = n%1000;								// 0 to 99
	UARTCharPut(UART0_BASE, 0x30+n/100);	// hundreds digit
	n = n%100;								// 0 to 99
	UARTCharPut(UART0_BASE, 0x30+n/10);		// tens digit
	n = n%10;								// 0 to 9
	UARTCharPut(UART0_BASE, 0x30+n);		// ones digit
	//UARTCharPut( UART0_BASE, '\r' );  //new line
	//UARTCharPut( UART0_BASE, '\n' );
