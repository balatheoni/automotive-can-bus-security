#include <SPI.h> 
#include "df_can.h"

const int SPI_CS_PIN= 10;
MCPCAN CAN(SPI_CS_PIN);
unsigned char flagRecv=0;
unsigned char len=0;
unsigned char buf[8]={'0','0','0','0','0','0','0','0'};

void setup(){

Serial.begin(115200);
int count= 50;          // the max numbers of initializint the CAN-BUS, if initialize failed first!.

do{

CAN.init();   //must initialize the Can interface here!


if(CAN_OK == CAN.begin(CAN_500KBPS))
{
Serial.println("DFROBOT's CAN BUS Shield init ok!");
break;
}
else {
Serial.println("DFROBOT's CAN BUS Shield init fail");
Serial.println("Please Init CAN BUS Shield again");
delay(10);
if (count <= 1)
Serial.println("Please give up trying!, trying is useless!");
}
}
while(count--);

}

unsigned char data[8], data1[8];
unsigned char data2[8];


void loop()
{
int i;
int code;
unsigned long can_id;

// for (i=4; i<8; i++)
// data[i]= data[i] + 1;
//working 3
data[0] = 0x000; // 01 working //'0';//0
data[1] = 0x000;
data[2] = 0x000;
data[3] = 0x000;
data[4] = 0x000;
data[5] = 0x000;
data[6] = 0x000;
data[7] = 0x000;

data1[0] = 0x01;
data1[1] = 0x00;
data1[2] = 0x00;
data1[3] = 0x00;
data1[4] = 0x00;
data1[5] = 0x00;
data1[6] = 0x00;
data1[7] = 0x00;

data2[0] = 0x02;
data2[1] = 0x01;
data2[2] = 0x0C;
data2[3] = 0x55;
data2[4] = 0x55;
data2[5] = 0x55;
data2[6] = 0x55;
data2[7] = 0x55;


//CAN.sendMsgBuf (0x7e0, 0, 8, data); // 0x7e0 worked, 0x7df, 0x18db33f1

CAN.sendMsgBuf(0x317, 0, 8, data); // 0x7e0 worked, 0x7df, 0x18db33f1
CAN.sendMsgBuf(0x313, 0, 8, data1);
CAN.sendMsgBuf(0x212, 0, 8, data);
CAN.sendMsgBuf(0x326, 0, 8, data);
CAN.sendMsgBuf(0x414, 0, 8, data);
delay(10); // send data per 100ms
Serial.println("A... sending message:");
Serial.println("0x317");
Serial.println("0x313");
Serial.println("0x212");
Serial.println("0x326");
Serial.println("0x414");



for (i=0; i<8; i++)
Serial.println(data[i]);
Serial.println();
}
