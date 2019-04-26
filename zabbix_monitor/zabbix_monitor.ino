/* Code built using https://github.com/interlegis/Arduino-Zabbix-Agent and https://github.com/levkov/sensor.im as reference */

// Libraries
#include "EmonLib.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Ethernet.h>
#include <SPI.h>

// User changeable parameters
#define nofSensors 13
byte mac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
IPAddress ip(192, 168, 0, 20);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

// Constants
#define MAX_CMD_LENGTH 25
#define p0 A0
#define p1 A1
#define p2 A2
#define p3 A3
#define p4 A4
#define p5 A5
#define p6 A8
#define p7 A9
#define p8 A10
#define p9 A11
#define p10 A12
#define p11 A13
#define p12 A14
#define p13 A15

// Constants //
const byte analogPorts[] = {p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13};
const byte digitalPorts[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34};

// Variables //
// Telnet received commands
String cmd;

// Time based calc
double lastmsec;
double msec;

// Sensor data
double celcius[2];
double amps[nofSensors];

// Sensor classes //
// Energy
EnergyMonitor emon[nofSensors];

// Temperature
OneWire oneWire0(digitalPorts[0]);
OneWire oneWire1(digitalPorts[1]);
OneWire oneWire2(digitalPorts[2]);
OneWire oneWire3(digitalPorts[3]);
OneWire oneWire4(digitalPorts[4]);
OneWire oneWire5(digitalPorts[5]);
OneWire oneWire6(digitalPorts[6]);
OneWire oneWire7(digitalPorts[7]);
OneWire oneWire8(digitalPorts[8]);
OneWire oneWire9(digitalPorts[9]);
OneWire oneWire10(digitalPorts[10]);
OneWire oneWire11(digitalPorts[11]);
OneWire oneWire12(digitalPorts[12]);

DallasTemperature sensor0(&oneWire0);
DallasTemperature sensor1(&oneWire1);
DallasTemperature sensor2(&oneWire2);
DallasTemperature sensor3(&oneWire3);
DallasTemperature sensor4(&oneWire4);
DallasTemperature sensor5(&oneWire5);
DallasTemperature sensor6(&oneWire6);
DallasTemperature sensor7(&oneWire7);
DallasTemperature sensor8(&oneWire8);
DallasTemperature sensor9(&oneWire9);
DallasTemperature sensor10(&oneWire10);
DallasTemperature sensor11(&oneWire11);
DallasTemperature sensor12(&oneWire12);

/* Ethernet config */
EthernetServer server(10050);
EthernetClient client;

//************Code************//

// Reset function
void resetClient(){
  client.stop();
}

void readTelnetCommand(char c) {
  if(cmd.length() == MAX_CMD_LENGTH) {
    cmd = "";
  }

  cmd += c;

  //Serial.print(c);

  if(c == '\n') {
    if(cmd.length() > 2) {
      // remove \r and \n from the string
      cmd = cmd.substring(0,cmd.length() - 1);
      parseCommand();
    }
  }
}

double getCurrent(byte i){
  // Request current
  amps[i] = emon[i].calcIrms(1480);

  if(amps[i] <= 100){ }

  delay(25);

  // Returns current
  return amps[i];
}

double getTemps(byte i){
  // Request temperatures
  sensor0.requestTemperatures();
  sensor1.requestTemperatures();
  sensor2.requestTemperatures();
  sensor3.requestTemperatures();
  sensor4.requestTemperatures();
  sensor5.requestTemperatures();
  sensor6.requestTemperatures();
  sensor7.requestTemperatures();
  sensor8.requestTemperatures();
  sensor9.requestTemperatures();
  sensor10.requestTemperatures();
  sensor11.requestTemperatures();
  sensor12.requestTemperatures();

  // Get last temperature in celcius
  celcius[0] = sensor0.getTempCByIndex(0);
  celcius[1] = sensor1.getTempCByIndex(0);
  celcius[2] = sensor2.getTempCByIndex(0);
  celcius[3] = sensor3.getTempCByIndex(0);
  celcius[4] = sensor4.getTempCByIndex(0);
  celcius[5] = sensor5.getTempCByIndex(0);
  celcius[6] = sensor6.getTempCByIndex(0);
  celcius[7] = sensor7.getTempCByIndex(0);
  celcius[8] = sensor8.getTempCByIndex(0);
  celcius[9] = sensor9.getTempCByIndex(0);
  celcius[10] = sensor10.getTempCByIndex(0);
  celcius[11] = sensor11.getTempCByIndex(0);
  celcius[12] = sensor12.getTempCByIndex(0);

  // Returns temperature in celcius
  return celcius[i];
}

//Commands received by agent on port 10050 parsing
void parseCommand() {
  // Sensor and syntax variables
  byte i;
  String cmdCurrent = "";

  //Serial.print("Resposta: ");

  //Serial.println("Parsing");

  // Sends agent ping
  if (cmd.equals("agent.ping")){           // Sends ping
    //Serial.print("1");
    server.println("1");
    resetClient();
  } else if(cmd.equals("temperature.t1")) {    // Sends air temperature
    //Serial.print(getTemps(0));
    server.println(getTemps(0));
    resetClient();
  } else if (cmd.equals("temperature.2")) {    // Sends air temperature
    //Serial.print(celcius[1]);
    server.println(getTemps(1));
    resetClient();
  } else if (cmd.equals("temperature.3")) {    // Sends air temperature
    //Serial.print(celcius[2]);
    server.println(getTemps(2));
    resetClient();
  } else if (cmd.equals("temperature.4")) {    // Sends air temperature
    //Serial.print(celcius[3]);
    server.println(getTemps(3));
    resetClient();
  } else if (cmd.equals("temperature.5")) {    // Sends air temperature
    //Serial.print(celcius[4]);
    server.println(getTemps(4));
    resetClient();
  } else if (cmd.equals("temperature.6")) {    // Sends air temperature
    //Serial.print(celcius[5]);
    server.println(getTemps(5));
    resetClient();
  } else if (cmd.equals("temperature.7")) {    // Sends air temperature
    //Serial.print(celcius[6]);
    server.println(getTemps(6));
    resetClient();
  } else if (cmd.equals("temperature.8")) {    // Sends air temperature
    //Serial.print(celcius[7]);
    server.println(getTemps(7));
    resetClient();
  } else if (cmd.equals("temperature.9")) {    // Sends air temperature
    //Serial.print(celcius[8]);
    server.println(getTemps(8));
    resetClient();
  } else if (cmd.equals("temperature.10")) {    // Sends air temperature
    //Serial.print(celcius[9]);
    server.println(getTemps(9));
    resetClient();
  } else if (cmd.equals("temperature.11")) {    // Sends air temperature
    //Serial.print(celcius[10]);
    server.println(getTemps(10));
    resetClient();
  } else if (cmd.equals("temperature.12")) {    // Sends air temperature
    //Serial.print(celcius[11]);
    server.println(getTemps(11));
    resetClient();
  } else if (cmd.equals("temperature.13")) {    // Sends air temperature
    //Serial.print(celcius[12]);
    server.println(getTemps(12));
    resetClient();
  } else{
    // Sends current
    for(i=0; i<=(nofSensors-1); i++){
      // Makes asked string
      cmdCurrent = "current.";
      if(i == 0){
        cmdCurrent += "c1";
      } else{
        cmdCurrent += (i+1);
      }

      //Serial.println(cmdCurrent);

      // Returns current
      if (cmd.equals(cmdCurrent)){
        //Serial.print(getCurrent(i));
        server.println(getCurrent(i));
        resetClient();
      }
    }
  }
  cmd = "";
}


void setup() {
  //Serial.begin(9600);

  // Starts ethernet shield
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();

  // SCT configuration : ( Amps / AnalogInput ) / Resistor : (100/0,05)/300
  byte i;
  for(i=0; i<=(nofSensors-1); i++){
    emon[i].current(analogPorts[i], 60);
    emon[i].calcIrms(1480);
  }

  delay(1000);
}

void loop() {
  // Client variables
  boolean connected = false;
  //Serial.println("Loop");

  client = server.available();
  if (client) {
    if (!connected) {
      //Serial.println("False");
      client.flush();
      connected = true;
    }
    if (client.available() > 0) {
      int command = client.read();
      //Serial.println(command);
      readTelnetCommand(command);
    }
  }
}
