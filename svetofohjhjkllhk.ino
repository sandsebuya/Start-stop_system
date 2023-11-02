



#include <SoftwareSerial.h>
int blink_3speed = 250;
int R_light=10; // pin for red light
int Y_light=12;
int G_light=9;
SoftwareSerial bt(6, 7);

void light(int channel, int sleep,char se);

void light2(int channel,int channel2, int sleep,char se);

void blink(int channel,char se);

void setup()
{
bt.begin(9600);
Serial.begin(9600);
pinMode(R_light, OUTPUT); //красный
pinMode(Y_light, OUTPUT); //желтый
pinMode(G_light, OUTPUT); //зеленый
delay(1500);
}

void loop()
{
//digitalWrite(R_light, HIGH);
//val = digitalRead(R_light);
//if (val == HIGH)
//{
//bt.println('0');
//}
//delay(15000);




light(R_light,15000,'0');


//digitalWrite(R_light, LOW);
//bt.println('1');
//delay(100);

//for (i = 0; i < 3; i++) //фаза миганий красный светофора
//{
//bt.println('1');
//delay(blink_3speed*2);
//digitalWrite(R_light, HIGH);
//delay(blink_3speed*2);
//digitalWrite(R_light, LOW);
//delay((blink_3speed*2));
//bt.println('1');
//delay(100);
//}

//digitalWrite(Y_light, HIGH);
//val = digitalRead(Y_light);
//if (val == HIGH)
//{
//bt.println('1');
//}
//delay(3500);
//digitalWrite(Y_light, LOW);
//digitalWrite(R_light, LOW);




light2(R_light,Y_light,3500,'1');

//for (i = 0; i < 3; i++) //фаза миганий желтого светофора
//{
//bt.println('1');
//delay(blink_3speed);
//digitalWrite(Y_light, HIGH);
//delay(blink_3speed);
//digitalWrite(Y_light, LOW);
//delay(blink_3speed);
//}


//bt.println('1');
//digitalWrite(G_light, HIGH);
//val = digitalRead(G_light);
//if (val == HIGH)
//{
//bt.println('1');
//}
//delay(5000);
//digitalWrite(G_light, LOW);

light(G_light,5000,'1');


//for (i = 0; i < 3; i++) //фаза миганий зелёный светофора
//{
//bt.println('1');
//delay(blink_3speed);
//digitalWrite(G_light, HIGH);
//delay(blink_3speed);
//digitalWrite(G_light, LOW);
//delay(blink_3speed);
//}
blink(G_light,'1');
  digitalWrite(G_light, LOW);

}


void light(int channel, int sleep,char se){
  bt.println(se);
  digitalWrite(channel, HIGH);
  for(int i;i<sleep;i+=100){
  bt.println(se);
  delay(100);
  }
}

void light2(int channel,int channel2, int sleep,char se){
  bt.println(se);
  digitalWrite(channel, HIGH);
  digitalWrite(channel2, HIGH);
  for(int i=0;i<sleep;i+=100){
  bt.println(se);
  delay(100);
  }
  digitalWrite(channel, LOW);
  digitalWrite(channel2, LOW);
}

void blink(int channel,char se){

for (int i = 0; i < 3; i++) //фаза миганий зелёный светофора
{
bt.println(se);
delay(blink_3speed);
digitalWrite(channel, HIGH);
delay(blink_3speed);
digitalWrite(channel, LOW);
delay(blink_3speed);
}

digitalWrite(channel, LOW);
}
