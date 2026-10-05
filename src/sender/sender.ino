#include <SPI.h>
#include "df_can.h"

const int SPI_CS_PIN = 10;
MCPCAN CAN(SPI_CS_PIN);

void setup() {
    Serial.begin(115200);

    int count = 50;

    do {
        CAN.init();

        if (CAN_OK == CAN.begin(CAN_500KBPS)) {
            Serial.println("CAN Bus Shield initialized successfully.");
            break;
        } else {
            Serial.println("CAN Bus Shield initialization failed.");
            Serial.println("Retrying...");

            delay(1000);

            if (count <= 1) {
                Serial.println("CAN initialization failed.");
            }
        }

    } while (count--);
}

void loop() {

    unsigned char data[8] = {
        0x02,
        0x01,
        0x0C,
        0x55,
        0x55,
        0x55,
        0x55,
        0x55
    };

    CAN.sendMsgBuf(0x7DF, 0, 8, data);

    Serial.println("Sender: CAN message transmitted");
    Serial.println("CAN ID: 0x7DF");

    Serial.print("Payload: ");

    for (int i = 0; i < 8; i++) {
        Serial.print(data[i], HEX);
        Serial.print(" ");
    }

    Serial.println();
    Serial.println();

    delay(1000);
}
