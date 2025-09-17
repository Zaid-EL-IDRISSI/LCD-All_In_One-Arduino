#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

double xpow;
float keypad;
int valuekeypad;
byte x = 0;
float lenmbr;
byte counter;
byte counterx = 0;
byte numberracine;
char operation = ' ';
byte GetResulta;
double resulta;
char operation1 = ' ';
char operation2 = ' ';
byte index = 0;
byte zid = 0;
float lenmbr1;
float lenmbr2;
float lenmbr3;
String numberstring;
byte charachternumberstring;

void setup() {
    lcd.begin(16,2);
    Serial.begin(9600);
}

void loop() {
    valuekeypad = analogRead(A0);

    if(counterx >= 2) {
        switch(valuekeypad) {
            case 183:
                lcd.scrollDisplayLeft();
                delay(40);
                break;
            case 222:
                lcd.scrollDisplayRight();
                delay(40);
                break;
        }
    }

    counter = x;

    // Get keypad number
    keypad = -14848;
    valuekeypad = analogRead(A0);
    switch(valuekeypad) {
        case 487: keypad = 1; break;
        case 465: keypad = 2; break;
        case 445: keypad = 3; break;
        case 330: keypad = 4; break;
        case 320: keypad = 5; break;
        case 310: keypad = 6; break;
        case 250: keypad = 7; break;
        case 244: keypad = 8; break;
        case 238: keypad = 9; break;
        case 197: keypad = 0; break;
    }

    if((x == 0) && (valuekeypad == 365) && (numberracine == 0) && (GetResulta == 0)) {
        numberracine = 1;
        lcd.setCursor(index,0);
        lcd.print("(r");
        index += 2;
        delay(60);
    }

    if((valuekeypad == 269) && ((x == 1) || (x == 2)) && (GetResulta == 0)) {
        index += zid;
        lcd.setCursor(index,0);
        lcd.print("p");
        x = 5;
        delay(60);
    }

    if((keypad != -14848) && (x == 5)) {
        xpow = pow(lenmbr, keypad);
        lenmbr = xpow;
        x = 6;
        index += 1;
        lcd.setCursor(index,0);
        lcd.print(keypad);
        lcd.setCursor(index+1,0);
        lcd.print("   ");
        if(numberracine == 1) {
            index += 1;
            lcd.setCursor(index,0);
            lcd.print(")");
        }
    }

    if((keypad != -14848) && (GetResulta == 0)) {
        if((counter == 0) && (x == 0)) {
            lenmbr = keypad;
            x = 1;
            zid = 1;
            lcd.setCursor(index,0);
            lcd.print(lenmbr);
            lcd.setCursor(index+1,0);
            lcd.print("   ");
            delay(60);
        }
        if((counter == 1) && (x == 1)) {
            lenmbr = lenmbr*10 + keypad;
            x = 2;
            zid = 2;
            lcd.setCursor(index,0);
            lcd.print(lenmbr);
            lcd.setCursor(index+2,0);
            lcd.print("   ");
            delay(60);
        }
        if((counter == 2) && (x == 2)) {
            lenmbr = lenmbr*10 + keypad;
            x = 3;
            zid = 3;
            lcd.setCursor(index,0);
            lcd.print(lenmbr);
            lcd.setCursor(index+3,0);
            lcd.print("   ");
            delay(60);
        }
        if((counter == 3) && (x == 3)) {
            lenmbr = lenmbr*10 + keypad;
            x = 4;
            zid = 4;
            lcd.setCursor(index,0);
            lcd.print(lenmbr);
            lcd.setCursor(index+4,0);
            lcd.print("   ");
            delay(60);
        }
    }

    if((valuekeypad == 189) && (GetResulta == 0) &&
       (((x != 5) && (x > 0) && (x < 7) && (counterx > 0)) ||
        ((x == 6) && (counterx == 0)) ||
        ((counterx == 0) && (numberracine == 1)) ||
        ((counterx == 0) && (x < 5) && (x > 0)))) {

        if((x < 5) && (numberracine == 1)) {
            index += zid;
            lcd.setCursor(index,0);
            lcd.print(")");
        }
        if(numberracine == 1) {
            lenmbr = sqrt(lenmbr);
            numberracine = 0;
        } else if(x < 5) {
            index += zid -1;
        }
        GetResulta = 1;
        x = 7;
    }

    if(((x > 0) && (x < 7) && (x != 5)) && (GetResulta == 0) && (counterx < 2) &&
       (valuekeypad == 426 || valuekeypad == 301 || valuekeypad == 233 || valuekeypad == 193)) {

        if((x < 5) && (numberracine == 1)) {
            index += zid;
            lcd.setCursor(index,0);
            lcd.print(")");
        }
        if(numberracine == 1) {
            lenmbr = sqrt(lenmbr);
            numberracine = 0;
        } else if(x < 5) {
            index += zid -1;
        }

        if(valuekeypad == 426) operation = '+';
        if(valuekeypad == 301) operation = '-';
        if(valuekeypad == 233) operation = '/';
        if(valuekeypad == 193) operation = '*';

        index += 1;
        lcd.setCursor(index,0);
        lcd.print(operation);
        index += 1;
        x = 7;
        delay(60);
    }

    if(x == 7) {
        switch(counterx) {
            case 0: lenmbr1 = lenmbr; operation1 = operation; counterx = 1; x = 0; break;
            case 1: lenmbr2 = lenmbr; operation2 = operation; counterx = 2; x = 0; break;
            case 2: lenmbr3 = lenmbr; counterx = 3; x = 0; break;
        }
    }

    if((GetResulta == 1) && (counterx == 1)) {
        resulta = lenmbr1;
        GetResulta = 3;
    }

    if((GetResulta == 1) && (counterx == 2)) {
        switch(operation1) {
            case '+': resulta = lenmbr1 + lenmbr2; break;
            case '-': resulta = lenmbr1 - lenmbr2; break;
            case '/': resulta = lenmbr1 / lenmbr2; break;
            case '*': resulta = lenmbr1 * lenmbr2; break;
        }
        if((operation == '/') && (lenmbr2 == 0)) GetResulta = 2;
        else GetResulta = 3;
    }

    if((GetResulta == 1) && (counterx == 3)) {
        if((((operation1 == '/') && (lenmbr2 != 0)) || (operation1 != '/')) &&
           (((operation2 == '/') && (lenmbr3 != 0)) || (operation2 != '/'))) {

            if(operation1 == '+') {
                switch(operation2) {
                    case '+': resulta = (lenmbr1 + lenmbr2) + lenmbr3; break;
                    case '-': resulta = (lenmbr1 + lenmbr2) - lenmbr3; break;
                    case '*': resulta = lenmbr1 + (lenmbr2 * lenmbr3); break;
                    case '/': resulta = lenmbr1 + (lenmbr2 / lenmbr3); break;
                }
            }

            if(operation1 == '-') {
                switch(operation2) {
                    case '+': resulta = (lenmbr1 - lenmbr2) + lenmbr3; break;
                    case '-': resulta = (lenmbr1 - lenmbr2) - lenmbr3; break;
                    case '*': resulta = lenmbr1 - (lenmbr2 * lenmbr3); break;
                    case '/': resulta = lenmbr1 - (lenmbr2 / lenmbr3); break;
                }
            }

            if(operation1 == '*') {
                switch(operation2) {
                    case '+': resulta = (lenmbr1 * lenmbr2) + lenmbr3; break;
                    case '-': resulta = (lenmbr1 * lenmbr2) - lenmbr3; break;
                    case '*': resulta = (lenmbr1 * lenmbr2) * lenmbr3; break;
                    case '/': resulta = (lenmbr1 * lenmbr2) / lenmbr3; break;
                }
            }

            if(operation1 == '/') {
                switch(operation2) {
                    case '+': resulta = (lenmbr1 / lenmbr2) + lenmbr3; break;
                    case '-': resulta = (lenmbr1 / lenmbr2) - lenmbr3; break;
                    case '*': resulta = (lenmbr1 / lenmbr2) * lenmbr3; break;
                    case '/': resulta = (lenmbr1 / lenmbr2) * lenmbr3; break;
                }
            }
            GetResulta = 3;
        } else GetResulta = 2;
    }

    switch(GetResulta) {
        case 2:
            lcd.setCursor(9,1);
            lcd.print("Error");
            break;
        case 3:
            numberstring = resulta;
            charachternumberstring = numberstring.length();
            index = 16 - charachternumberstring;
            lcd.setCursor(index-1,1);
            lcd.print("=");
            lcd.setCursor(index,1);
            lcd.print(resulta);
            break;
    }

    if(valuekeypad == 201) {
        GetResulta = 0;
        index = 0;
        counterx = 0;
        zid = 0;
        numberracine = 0;
        x = 0;
        operation = ' ';
        operation1 = ' ';
        operation2 = ' ';
        lenmbr = 0;
        lenmbr1 = 0;
        lenmbr2 = 0;
        lenmbr3 = 0;
        resulta = 0;
        lcd.clear();
        delay(60);
    }

    Serial.println(GetResulta);
}
