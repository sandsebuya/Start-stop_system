//#include <SoftwareSerial.h>// программная реализация рх и тх

#include <OLED_I2C.h>                               // Подключаем библиотеку OLED_I2C для работы со шрифтами и графикой
OLED  myOLED(SDA, SCL, 20);// Определяем пины I2C интерфейса: UNO и NANO -- SDA - пин A4, SCL - пин A5; MEGA -- SDA - пин 20, SCL - пин 21, там в дуе написано Ж)

//SoftwareSerial bt(6, 7);// tx от модуля в digital 6, rx в 7 upd::: логи в дуе через сериалюсб
extern uint8_t SmallFont[];
unsigned long handshake_time;


void disp_test(){
myOLED.clrScr();
myOLED.print("Connecting...",CENTER,24);
myOLED.update();

}

void connection_error(){
myOLED.clrScr();
myOLED.print("A gde???///",CENTER,24);
myOLED.update();
}

void setup()
{
  //SoftwareSerial mySerial(6, 7);
  myOLED.begin(); // Инициализируем библиотеку OLED_I2C
  Serial3.begin(9600);//Я решил использовать сериал для логов, почему бы и нет
  SerialUSB.begin(9600);
  //bt.begin(9600);
  myOLED.setFont(SmallFont);
  disp_test();
  handshake_time= millis();
}

void loop()
{
  {
      char c = Serial3.read();
      switch (c){
      case '1':
        myOLED.clrScr();
        myOLED.setFont(SmallFont);
        myOLED.drawLine(64, 12, 64, 52);
        myOLED.update();     // Обновляем информацию на дисплее
        SerialUSB.println("Display is 1");
        SerialUSB.println(c);
        handshake_time=millis();
      break;
      case '0':
        myOLED.clrScr();
        myOLED.drawCircle(64, 32, 20);
        myOLED.update();
        SerialUSB.println("Display is 0");
        SerialUSB.println(c);
        handshake_time=millis();
      break;
      case '2':
        myOLED.clrScr();
        myOLED.drawCircle(64, 32, 20);
        myOLED.update();
        SerialUSB.println("Display is 2");
        SerialUSB.println(c);
        handshake_time=millis();
        break;
      }

    if((millis()-handshake_time)>20000){
      connection_error();
    }

  }
}