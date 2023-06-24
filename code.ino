#include <LiquidCrystal.h> 

#include <Keypad.h>

#include <string.h> 

#include <math.h>

const byte ROWS = 4; // Four rows

const byte COLS = 6; // Three columns

// Define the Keymap

char keys[ROWS][COLS] = {

  {'C', '7', '8', '9', 'M', 'D'},

  {'p', '4', '5', '6', 'S', 'Q'},

  {'P', '1', '2', '3', 'A', 'L'},

  {'R', '0', '.', '=', 'a', 'E'}

};

byte rowPins[ROWS] = { 0, 1, 2, 3 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.

byte colPins[COLS] = { 4, 5, 6, 7, 14, 15 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; //Pins to which LCD is connected

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


long Num1, Num2;
float Number;

char key;
char action[5];

boolean result = false;



void setup() {

  lcd.begin(16, 2); //We are using a 16*2 LCD display

  lcd.print(" Calculator"); //Display a intro message

  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1

  lcd.print("ON"); //Display a intro message

  delay(2000); //Wait for display to show info

  lcd.clear(); //Then clean it

}

void loop() {



  key = kpd.getKey(); //storing pressed key value in a char

  if (key != NO_KEY)

    DetectButtons();

  if (result == true)

    CalculateResult();

  DisplayResult();

}



void DetectButtons()

{

  lcd.clear(); //Then clean it

  if (key == 'C') //If cancel Button is pressed

  {
    Serial.println ("Button Cancel");
    Number = Num1 = Num2 = 0;
    result = false;
  }
 
  if (key == 'R')
  {
    Serial.println("Button Square Root");
    Num1=1;
    Num2 = Number;
    strcpy(action, "sqrt");
    result = true;
  }

   if (key == 'Q')
  {
    Serial.println("Button SINE");
    Num1=1;
    Num2 = Number;
    strcpy(action, "sine");
    result = true;
  }

  if (key == 'L')
  {
    Serial.println("Button log");
    Num1=1;
    Num2 = Number;
     strcpy(action, "log");;
    result = true;
  }


 if (key == 'E')
  {
    Serial.println("Button exp");
    Num1=1;
    Num2 = Number;
    strcpy(action, "exp");;
    result = true;
  }
  
  if (key == '1') //If Button 1 is pressed

  { Serial.println ("Button 1");

    if (Number == 0)

      Number = 1;

    else

      Number = (Number * 10) + 1; //Pressed twice

  }



  if (key == '4') //If Button 4 is pressed

  { Serial.println ("Button 4");

    if (Number == 0)

      Number = 4;

    else

      Number = (Number * 10) + 4; //Pressed twice

  }



  if (key == '7') //If Button 7 is pressed

  { Serial.println ("Button 7");

    if (Number == 0)

      Number = 7;

    else

      Number = (Number * 10) + 7; //Pressed twice

  }



  if (key == '0')

  { Serial.println ("Button 0"); //Button 0 is Pressed

    if (Number == 0)

      Number = 0;

    else

      Number = (Number * 10) + 0; //Pressed twice

  }



  if (key == '2') //Button 2 is Pressed

  { Serial.println ("Button 2");

    if (Number == 0)

      Number = 2;

    else

      Number = (Number * 10) + 2; //Pressed twice

  }



  if (key == '5')

  { Serial.println ("Button 5");

    if (Number == 0)

      Number = 5;

    else

      Number = (Number * 10) + 5; //Pressed twice

  }



  if (key == '8')

  { Serial.println ("Button 8");

    if (Number == 0)

      Number = 8;

    else

      Number = (Number * 10) + 8; //Pressed twice

  }

  if (key == '3')

  { Serial.println ("Button 3");

    if (Number == 0)

      Number = 3;

    else

      Number = (Number * 10) + 3; //Pressed twice

  }



  if (key == '6')

  { Serial.println ("Button 6");

    if (Number == 0)

      Number = 6;

    else

      Number = (Number * 10) + 6; //Pressed twice

  }



  if (key == '9')

  { Serial.println ("Button 9");

    if (Number == 0)

      Number = 9;

    else

      Number = (Number * 10) + 9; //Pressed twice

  }

  
    if (key == '=')

    {Serial.println ("Button Equal"); 

    Num2=Number; 

    result = true;

    }

  if (key == 'A' || key == 'a' || key == 'S' || key == 'D' || key == 'M' || key == 'P' ||key == 'p' ) //Detecting Buttons on Column 4

  {

    Num1 = Number;

    Number = 0;

    if (key == 'p')
  {
    Serial.println("Button power");
    strcpy(action, "^");
  }

    if (key == 'A')

    {
      Serial.println ("Addition");
       strcpy(action, "+");
    }

    if (key == 'a')

    {
      Serial.println ("Addition");
       strcpy(action, "+");
    }

    if (key == 'S')

    {
      Serial.println ("Subtraction");
       strcpy(action, "-");
    }

    if (key == 'D')

    {
      Serial.println ("Division");
       strcpy(action, "/");
    }

    if (key == 'M')

    {
      Serial.println ("Multiplication");
       strcpy(action, "*");
    }

    if (key == 'P')

    {
      Serial.println ("Percentage");
       strcpy(action, "%");;
    }

    delay(100);

  }

}

void CalculateResult()

{

  if (strcmp(action, "+") == 0)

    Number = Num1 + Num2;

  if (strcmp(action, "-") == 0)

    Number = Num1 - Num2;

  if (strcmp(action, "*") == 0)

    Number = Num1 * Num2;

  if (strcmp(action, "/") == 0)
  {
    if (Num2 != 0)
      Number = (float)Num1 / Num2;
    else
      Number = 0;
  }

  if (strcmp(action, "%") == 0)
  {
    if (Num2 != 0)
      Number = (((float)Num1 / Num2)*100);
    else
      Number = 0;
  }
  if (strcmp(action, "sqrt") == 0)

    Number = sqrt(Num2);

  if (strcmp(action, "log") == 0)

    Number = log(Num2);

if (strcmp(action, "exp") == 0)

    Number = exp(Num2);

 if (strcmp(action, "sine") == 0)

    Number = sin(Num2);;

 if (strcmp(action, "^") == 0)

    Number = pow(Num1,Num2);
}

void DisplayResult()

{

  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1

  lcd.print(Num1); lcd.print(action); lcd.print(Num2);



  if (result == true)

  {
    lcd.print(" =");  //Display the result
    lcd.print(Number);
  }



  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1

  lcd.print(Number); //Display the result

}

