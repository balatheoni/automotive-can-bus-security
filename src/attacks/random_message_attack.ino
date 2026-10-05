#include <df_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 10;
MCPCAN CAN(SPI_CS_PIN);

bool canCommunicationEnabled = true;

void introduceInterference(int interferenceType);

void setup() {
  Serial.begin(115200);
  int count = 50;

  do {
    CAN.init();
    if (CAN_OK == CAN.begin(CAN_500KBPS)) {
      Serial.println("DFROBOT's CAN BUS Shield init ok!");
      break;
    } else {
      Serial.println("DFROBOT's CAN BUS Shield init fail");
      Serial.println("Please Init CAN BUS Shield again");
      delay(100);
      if (count <= 1) {
        Serial.println("Please give up trying!, trying is useless!");
        while (1);  // Stop further execution if initialization fails
      }
    }
  } while (count--);
}

void loop() {
  // Declare interferenceType here
  int interferenceType = random(3);  // Randomly choose an interference type (0, 1, or 2)

  // Create a data array with a header and random values
  unsigned char data[8];
  data[0] = 'D';  // Header remains the same

  // Generate and fill the data array with random values
  for (int i = 1; i < 8; i++) {
    data[i] = random(0, 256);  // Generate a random number between 0 and 255
  }

  // Send data: id = 0x7E8, standard frame, data len = 8, data: data buf
  if (canCommunicationEnabled) {
    CAN.sendMsgBuf(0x7E8, 0, 8, data);
  }

  // Introduce interference with a 10% chance
  if (random(0, 100) < 10) {
    introduceInterference(interferenceType);  // Pass interferenceType as an argument
  } else {
    delay(1000);  // Adding a delay of 1 second for demonstration
  }
}

void introduceInterference(int interferenceType) {
  switch (interferenceType) {
    case 0:  // Delaying communication
      Serial.println("Delaying communication! Communication disrupted.");
      delay(5000);  // Add a delay to simulate the time for interference
      break;

    case 1:  // Sending invalid data
      Serial.println("Sending invalid data! Communication disrupted.");
      unsigned char invalidData[8] = {'I', 'N', 'V', 'A', 'L', 'I', 'D', '!'};
      CAN.sendMsgBuf(0x7E8, 0, 8, invalidData);
      delay(1000);  // Add a delay after sending invalid data
      break;

    case 2:  // Disconnecting CAN bus (set flag to disable communication)
      Serial.println("Disconnecting CAN bus! Communication disrupted.");
      canCommunicationEnabled = false;
      delay(5000);  // Add a delay before re-enabling CAN communication
      break;
  }
}
