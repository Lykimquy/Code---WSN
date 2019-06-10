
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
Adafruit_INA219 ina219_A;
Adafruit_INA219 ina219_B(0x41);


void setup(void) 
{
  ina219_A.begin();  // Initialize first board (default address 0x40)
  ina219_B.begin();  // Initialize second board with the address 0x41


  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
   delay(1);
  }

  uint32_t currentFrequency;
    
Serial.println("Hello!");
  
Serial.println("Measuring voltage and current with INA219s ...");
}

void loop(void) 
{
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  shuntvoltage = ina219_A.getShuntVoltage_mV();
  busvoltage = ina219_A.getBusVoltage_V();
  current_mA = ina219_A.getCurrent_mA();
  power_mW = ina219_A.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);

  shuntvoltage = ina219_A.getShuntVoltage_mV();
  busvoltage = ina219_A.getBusVoltage_V();
  current_mA = ina219_A.getCurrent_mA();
  power_mW = ina219_A.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.println("Measuring voltage and current with INA219_A ...");
  Serial.print("Bus Voltage A:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt Voltage A: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load Voltage A:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current A:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power A:         "); Serial.print(power_mW); Serial.println(" mW");
 Serial.println("");
  delay(2000);
   Serial.println("Measuring voltage and current with INA219_B ...");
  shuntvoltage = ina219_B.getShuntVoltage_mV();
  busvoltage = ina219_B.getBusVoltage_V();
  current_mA = ina219_B.getCurrent_mA();
  power_mW = ina219_B.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  Serial.print("Bus Voltage B:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt Voltage B: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load Voltage B:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current B:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power B:         "); Serial.print(power_mW); Serial.println(" mW");
 Serial.println("");
  delay(2000);
}
