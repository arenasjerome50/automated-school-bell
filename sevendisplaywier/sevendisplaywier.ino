/*const byte numerals[10] = {	// bytes for the seven seg. positioning Leds to each number
  B11000000,B11111001, B10100100, B10110000, B10011001, B10010010, B10000010, B11111000, B10000000, B10010000
};
const byte clearDisplay = B11111111;
const byte dash = B10111111;

/*
	this function displays number with two significant digits.
	for displaying minute.
*/
/*
void showNumber_wZero(int number,int digitArr[], int duration)
{
  if(number == 0){	// if the number is zero.
    showDigit( 0 , digitArr, nbrDigits - 2, duration);
    showDigit( 0, digitArr, nbrDigits - 1, duration);}
  else
  {
    for( int digit = 0; digit < nbrDigits; digit++)	// iterate for each digit position
    {
        showDigit( number % 10,digitArr, digit, duration); // getting the first position by getting the remainder of the number.
														// for example you want to display 12, so 12 % 10 = 2 the pass it to the showDigit fx(the first digit position is always begin
														// at the right). Then 12 / 10 = 1(since dividing integers wont get those decimal remainder, this will be the second position of the number).
        number = number / 10;
    }
  }
}

/*
	this function display number in seven seg without zeroes.
	great for displaying hour.
*/
/*
void showNumber(int number, int digitArr[], int duration)
{
  if(number == 0){
    showDigit( 0 , digitArr, nbrDigits - 2, duration);
  }
  else if( number >= 0 && number <= 9){
    showDigit( number, digitArr, nbrDigits - 2, duration);
   }
  else{
    for( int digit = 0; digit < nbrDigits; digit++)
    {
      showDigit( number % 10, digitArr, digit, duration);
      number = number / 10; 
    }
  }
}

void showDash(int digitArr[],int duration)
{
  for(int digit; digit < 2; digit++){
  digitalWrite(digitArr[digit], HIGH);
  shiftOut(SER, CLK, MSBFIRST, dash);
  delayMicroseconds(duration);
  digitalWrite(digitArr[digit], LOW);
  shiftOut(SER, CLK, MSBFIRST, clearDisplay);
  }
}

/*
	this is the core function of showNumber and showNumber_wZero.
	this function displays number on seven seg in real time.
*/
/*
void showDigit( int number , int digitArr[], int digit, int duration ){
  digitalWrite(digitArr[digit], HIGH);		// Set the cathode to high, im using Common Cathode displays
  shiftOut(SER, CLK, MSBFIRST, numerals[number]);	// setting the led to be lit up base on the number and its corresponding byte
  delayMicroseconds(duration);				// wait a bit
  digitalWrite(digitArr[digit], LOW);	// turn off the digit pin
  shiftOut(SER, CLK, MSBFIRST, clearDisplay);
}
*/
