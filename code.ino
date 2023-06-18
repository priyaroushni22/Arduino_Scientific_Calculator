#include <Keypad.h>
#include <LiquidCrystal.h>
#include <math.h>

//used 'D' for enter

LiquidCrystal lcd(3,2,12,13,11,10);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
byte rowPins[ROWS] = {5, 4,15,14};
byte colPins[COLS] = {8, 7, 6,9};

String show_val = "";
double prev_val = 0;
bool status = false;
char oper_vector[5] = {'+','-','*','/','%'};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  operation_information();
}

void loop(){
  
  status = false;
  long enter_val = getNumber();
  Serial.print("You have chosen:");
  Serial.print(enter_val);
  Serial.println();
  lcd.clear();
  lcd.print("you have chosen:");
  lcd.setCursor(0,2);
  lcd.print(enter_val);
  delay(2000);
  if(enter_val == 15){
    BODMAS();
  }
  else{
    show_val = "";
  	prev_val = process(enter_val,status);
  
  	while(1){
      	status = true;
      	Serial.println("press only D to start new computation.");
      	show_val = "";
      	long enter_val1 = getNumber();
      	if(enter_val1==0){
       	 	Serial.println("starting new computation.");
      		break;
      	}
      	else{
        	Serial.print("you have chosen:");
        	Serial.println(enter_val);
        	lcd.clear();
        	show_val = "";
        	String myString = String(prev_val);
        	getshow_val(myString);
        	lcd.print(show_val);
        	prev_val = process(enter_val1,status);
      	}
   	}
  }
  
  delay(6000);
  lcd.clear();
  show_val = "";
}

void operation_information(){
  Serial.println("Choose the option:");
  Serial.println("1.ADD");
  Serial.println("2.SUB");
  Serial.println("3.MULT");
  Serial.println("4.DIV");
  Serial.println("5.ABS");
  Serial.println("6.SIN");
  Serial.println("7.COS");
  Serial.println("8.MOD");
  Serial.println("9.SQRT");
  Serial.println("10.Loge");
  Serial.println("11.Log10");
  Serial.println("12.exp");
  Serial.println("13.pow");
  Serial.println("14.square of number");
  Serial.println("15.BODMAS Operation");
}

String operation(int num1)
{
  String ret_val = "";
  while(1){
    if(num1==1){
      ret_val = "+";
    }
    else if(num1==2){
      ret_val = "-";
    }
    else if(num1==3){
      ret_val = "*";
    }
    else if(num1==4){
      ret_val = "/";
    }
    else if(num1==5){
      ret_val = "abs :";
    }
    else if(num1==6){
      ret_val = "sin :";
    }
    else if(num1==7){
      ret_val = "cos :";
    }
    else if(num1==8){
      ret_val = "Mod";
    }
    else if (num1==9){
      ret_val = "SQRT: ";
    }
    else if(num1==10){
      ret_val = "Loge:";
    }
    else if(num1==11){
      ret_val = "Log10:";
    }
    else if(num1==12){
      ret_val = "exp:";
    }
    else if(num1==13){
      ret_val = "pow:";
    }
    else if(num1==14){
      ret_val = "square of a number:";
    }
    break;
  }
  getshow_val(ret_val);
  return ret_val;
}

double process(int num,bool status){
  double val1 = prev_val;
  if(num==1){
    if(status==true){
    }
    else{
    	lcd.clear();
    	Serial.println("Enter the first number.");
    	val1 = (double)getNumber();
    	Serial.println(val1);
    }
    String oper = operation(num);
    lcd.clear();
    lcd.print(show_val);
  	Serial.println(oper);
  	Serial.println("Enter second number.");
  	double val2 = (double)getNumber();
 	Serial.println(val2);
  	lcd.clear();
  	lcd.print(show_val);
    lcd.setCursor(0,2);
    double result = val1 + val2;
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
    return result;
  }
  else if(num==2){
    if(status==true){
    }
    else{
       lcd.clear();
       Serial.println("Enter the first number.");
       val1 = (double)getNumber();
  	   Serial.println(val1);
    }
    String oper = operation(num);
  	lcd.clear();
  	lcd.print(show_val);
  	Serial.println(oper);
  	Serial.println("Enter second number.");
  	double val2 = (double)getNumber();
  	Serial.println(val2);
  	lcd.clear();
  	lcd.print(show_val);
    lcd.setCursor(0,2);
    double result = val1 - val2;
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
    return result;
  }
  else if(num==3){
    if(status==true){
    }
    else{
      lcd.clear();
      Serial.println("Enter the first number.");
      val1 = (double)getNumber();
  	  Serial.println(val1);
    }
    String oper = operation(num);
  	lcd.clear();
  	lcd.print(show_val);
  	Serial.println(oper);
  	Serial.println("Enter second number.");
  	double val2 = (double)getNumber();
  	Serial.println(val2);
  	lcd.clear();
  	lcd.print(show_val);
    lcd.setCursor(0,2);
    double result = val1 * val2;
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
    return result;
  }
   else if(num==4){
    if(status==true){
    }
    else{
      lcd.clear();
      Serial.println("Enter the first number.");
      val1 = getNumber();
  	  Serial.println(val1);
    }
    String oper = operation(num);
  	lcd.clear();
  	lcd.print(show_val);
  	Serial.println(oper);
  	Serial.println("Enter second number.");
  	long val2 = getNumber();
  	Serial.println(val2);
  	lcd.clear();
  	lcd.print(show_val);
    lcd.setCursor(0,2);
    double result = val1 / val2;
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
     return result;
  }
  else if(num==8){
    if(status==true){
    }
    else{
      lcd.clear();
      Serial.println("Enter the first number.");
      val1 = getNumber();
  	  Serial.println(val1);
    }
    String oper = operation(num);
  	lcd.clear();
  	lcd.print(show_val);
  	Serial.println(oper);
  	Serial.println("Enter second number.");
  	long val2 = getNumber();
  	Serial.println(val2);
  	lcd.clear();
  	lcd.print(show_val);
    lcd.setCursor(0,2);
    long result = ((long)val1) % val2;
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
    return result;
  }
   else if(num==5){
    lcd.clear();
    show_val = "";
    String oper = operation(num);
  	lcd.clear();
  	Serial.println(oper);
    if(status==true){
      String myString = String(val1);
      getshow_val(myString);
      lcd.print(show_val);
    }
    else{
      Serial.println("Enter the number.");
      val1 = (double)getNumber();
  	  Serial.println(val1);
    }
    lcd.setCursor(0,2);
    double result = abs(val1);
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
     return result;
  }
  else if(num==6){
    lcd.clear();
    show_val = "";
    String oper = operation(num);
  	lcd.clear();
  	Serial.println(oper);
    if(status==true){
      String myString = String(val1);
      getshow_val(myString);
      lcd.print(show_val);
    }
    else{
      Serial.println("Enter the number.");
      val1 = (double)getNumber();
  	  Serial.println(val1);
    }
    lcd.setCursor(0,2);
    double result = sin(val1);
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
    return result;
  }
   else if(num==7){
    lcd.clear();
    show_val = "";
    String oper = operation(num);
  	lcd.clear();
  	Serial.println(oper);
    if(status==true){
      String myString = String(val1);
      getshow_val(myString);
      lcd.print(show_val);
    }
    else{
      Serial.println("Enter the number.");
      val1 = (double)getNumber();
  	  Serial.println(val1);
    }
    lcd.setCursor(0,2);
    double result = cos(val1);
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
     return result;
  }
   else if(num==9){
    lcd.clear();
    show_val = ""; 
    String oper = operation(num);
  	lcd.clear();
  	Serial.println(oper);
    if(status==true){
      String myString = String(val1);
      getshow_val(myString);
      lcd.print(show_val);
    }
    else{
      Serial.println("Enter the number.");
      val1 = (double)getNumber();
  	  Serial.println(val1);
    }
    lcd.setCursor(0,2);
    double result = sqrt(val1);
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
     return result;
  }
  else if(num==10){
    lcd.clear();
    show_val = ""; 
    String oper = operation(num);
  	lcd.clear();
  	Serial.println(oper);
    if(status==true){
      String myString = String(val1);
      getshow_val(myString);
      lcd.print(show_val);
    }
    else{
      Serial.println("Enter the number.");
      val1 = (double)getNumber();
  	  Serial.println(val1);
    }
    lcd.setCursor(0,2);
    double result = log(val1);
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
     return result;
  }
  else if(num==11){
    lcd.clear();
    show_val = ""; 
    String oper = operation(num);
  	lcd.clear();
  	Serial.println(oper);
    if(status==true){
      String myString = String(val1);
      getshow_val(myString);
      lcd.print(show_val);
    }
    else{
      Serial.println("Enter the number.");
      val1 = getNumber();
  	  Serial.println(val1);
    }
    lcd.setCursor(0,2);
    double result = log10((double)val1);
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
     return result;
  }
  else if(num==12){
    lcd.clear();
    show_val = ""; 
    String oper = operation(num);
  	lcd.clear();
  	Serial.println(oper);
    if(status==true){
      String myString = String(val1);
      getshow_val(myString);
      lcd.print(show_val);
    }
    else{
      Serial.println("Enter the number.");
      val1 = getNumber();
  	  Serial.println(val1);
    }
    lcd.setCursor(0,2);
    double result = exp((double)val1);
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
     return result;
  }
  else if(num==14){
    lcd.clear();
    show_val = ""; 
    String oper = operation(num);
  	lcd.clear();
  	Serial.println(oper);
    if(status==true){
      String myString = String(val1);
      getshow_val(myString);
      lcd.print(show_val);
    }
    else{
      Serial.println("Enter the number.");
      val1 = getNumber();
  	  Serial.println(val1);
    }
    lcd.setCursor(0,2);
    double result = square((double)val1);
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
     return result;
  }
  if(num==13){
    if(status==true){
    }
    else{
    	lcd.clear();
    	Serial.println("Enter the first number.");
    	val1 = (double)getNumber();
    	Serial.println(val1);
    }
    String oper = operation(num);
    lcd.clear();
    lcd.print(show_val);
  	Serial.println(oper);
  	Serial.println("Enter second number.");
  	long val2 = getNumber();
 	Serial.println(val2);
  	lcd.clear();
  	lcd.print(show_val);
    lcd.setCursor(0,2);
    double result = pow(val1,(double)val2);
    lcd.print(result);
    Serial.println("Result is:");
    Serial.println(result);
    return result;
  }


}


void BODMAS(){
  String input_takers[16];
  show_val = "";
  Serial.println("Start inserting input");
  int i = 0;
  while(1){
    char Key = keypad.getKey();
    Serial.println(Key);
    if (Key != NO_KEY){
      if(Key == 'B'){
      Serial.println("stop taking input");
      break;
      }
      if(Key=='C'){
        		String prev_show1 = show_val;
      			long value = getNumber();
      			Serial.print("got the operation value");
        		show_val = prev_show1;
      			Serial.println(value);
      			if(value == 1){
       				 String myString1 = String(oper_vector[value-1]);
        			getshow_val(myString1);
        			lcd.clear();
        			lcd.print(show_val);
        			input_takers[i] = myString1;
        			i++;
      			}
      			else if(value == 2){
                  String prev_show2 = show_val;
        		String myString2 = String(oper_vector[value-1]);
                  show_val = prev_show2;
        		getshow_val(myString2);
        		lcd.clear();
        		lcd.print(show_val);
       			input_takers[i] = myString2;
        		i++;
      			}
      			else if(value == 3){
                  String prev_show3 = show_val;
        		String myString3 = String(oper_vector[value-1]);
                  show_val = prev_show3;
        		getshow_val(myString3);
        		lcd.clear();
        		lcd.print(show_val);
        		input_takers[i] = myString3;
        		i++;
      			}
      			else if(value == 4){
                 String prev_show4 = show_val;
        		String myString4 = String(oper_vector[value-1]);
                  show_val = prev_show4;
        		getshow_val(myString4);
        		lcd.clear();
        		lcd.print(show_val);
        		input_takers[i] = myString4;
        		i++;
      			}
      			else if(value == 5){
                 String prev_show5 = show_val;
        		String myString5 = String(oper_vector[value-1]);
                  show_val = prev_show5;
        		getshow_val(myString5);
        		lcd.clear();
        		lcd.print(show_val);
        		input_takers[i] = myString5;
        		i++;
      			}
    	}
      	else{
      			long value1 = getNumber();
      			Serial.print("got numeric value");
      			Serial.println(value1);
      			lcd.clear();
      			lcd.print(show_val);
      			String myString = String(value1);
      			input_takers[i] = myString;
      			i++;
    		}
      }
  }
  
    int p = 0;
  	while(p<=16){
    Serial.print(input_takers[p]);
    Serial.print(" ");
    p++;
 	}
  
  while(i!=1){
    int j = 0;
    bool found1 = true;
    bool found2 = true;
    bool found3 = true;
    
    while(j<i && i>1){
      if(input_takers[j] == "/"){
      	int val1 = input_takers[j-1].toInt();
        int val2 = input_takers[j+1].toInt();
        float res = val1 / val2;
        input_takers[j] = ".";
        input_takers[j+1] = ".";
        String myString = String(res);
        input_takers[j-1] = myString;
        found1 = false;
       	break;
     }
      j++;
    }
    j = 0;
    while(j<i && i>1 && found1 == true){
      if(input_takers[j] == "*"){
      	float val1 = input_takers[j-1].toFloat();
        float val2 = input_takers[j+1].toFloat();
        float res = val1 * val2;
        input_takers[j] = ".";
        input_takers[j+1] = ".";
        String myString = String(res);
        input_takers[j-1] = myString;
        found2 = false;
       	break;
     }
      j++;
    }
    j = 0;
    while(j<i && i>1 && found1==true && found2 == true){
      if(input_takers[j] == "-"){
      	float val1 = input_takers[j-1].toFloat();
        float val2 = input_takers[j+1].toFloat();
        float res = val1 - val2;
        input_takers[j] = ".";
        input_takers[j+1] = ".";
        String myString = String(res);
        input_takers[j-1] = myString;
        found3 = false;
       	break;
     }
      j++;
    }
    j = 0;
    while(j<i && i>1 && found1==true && found2==true && found3 == true){
      if(input_takers[j] == "+"){
      	float val1 = input_takers[j-1].toFloat();
        float val2 = input_takers[j+1].toFloat();
        float res = val1 + val2;
        input_takers[j] = ".";
        input_takers[j+1] = ".";
        String myString = String(res);
        input_takers[j-1] = myString;
       	break;
     }
      j++;
    }
    
    int d = 0;
    while(d<i-2){
      if(input_takers[d] == "."){
        String temp = input_takers[d];
        input_takers[d] = input_takers[d+2];
        input_takers[d+2] = temp;
      }
      d++;
    }
    	
   /* Serial.println();
        int p1 = 0;
  		while(p1<i){
    		Serial.print(input_takers[p1]);
    		Serial.print(" ");
    		p1++;
 		}*/
    i = i-2;
  }
  	float result = input_takers[0].toFloat();
    lcd.setCursor(0,2);
    lcd.print(result);
    Serial.println(result);
    delay(4000);
}

  
void getshow_val(String str){
  show_val = show_val + str;
}


long getNumber()
{
  long second = 0;
  while(1)
  {
    char Key = keypad.getKey();
    if(Key >= '0' && Key <= '9')
    {
      second = second * 10 + (Key - '0');
      lcd.clear();
      String myString = String(Key);
      getshow_val(myString);
      lcd.print(show_val);
     }
    
    if(Key == 'D') {
      break;
    }
 
  }  
   return second;
}
