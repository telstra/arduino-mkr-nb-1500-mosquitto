// libraries
#include <MKRNB.h>
#include <ArduinoMqttClient.h>

//The MKRNB lib needs this even if its blank
const char PINNUMBER[]     = "";

//broker url in here, demo is using eclipse test server

//broker port in here
int mqttPort = 1883;

//var things for storage
const char broker[] = "iot.eclipse.org";
int        port     = 1883;
const char topic[]  = "telstradev";

// initialize the library instance
NBClient client;
GPRS gprs;
NB nbAccess;

MqttClient mqttClient(client);

void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Warming up....");
  // connection state
  boolean connected = false;

  while (!connected) {
    if ((nbAccess.begin(PINNUMBER) == NB_READY) &&
        (gprs.attachGPRS() == GPRS_READY)) {
      connected = true;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  Serial.println("connecting to the mqtt broker...");

  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  mqttClient.onMessage(onMqttMessage);

  Serial.print("Subscribing to topic: ");
  Serial.println(topic);
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe(topic);

  // topics can be unsubscribed using:
  // mqttClient.unsubscribe(topic);

  Serial.print("Waiting for messages on topic: ");
  Serial.println(topic);
  Serial.println();

}

void loop() {

  mqttClient.poll();

  delay(2000);

  mqttClient.beginMessage(topic);
  mqttClient.print("hello world ");
  mqttClient.endMessage();

}


void onMqttMessage(int messageSize) {
  // we received a message, print out the topic and contents
  Serial.println("Received a message with topic '");
  Serial.print(mqttClient.messageTopic());
  Serial.print("', length ");
  Serial.print(messageSize);
  Serial.println(" bytes:");

  // use the Stream interface to print the contents
  while (mqttClient.available()) {
    Serial.print((char)mqttClient.read());
  }
  Serial.println();

  Serial.println();
  
}