// libraries
#include <MKRNB.h>
#include <PubSubClient.h>

//The MKRNB lib needs this even if its blank
const char PINNUMBER[]     = "";

#define TOKEN ""
#define MQTT_CLIENT_NAME "catm1" 

//broker url in here, demo is using eclipse test server
char mqttBroker[]  = "iot.eclipse.org";

//broker port in here
int mqttPort = 1883;

//var things for storage
char payload[100];
char topic[150];
char topicSubscribe[100];

//change this value to subscribe to a different topic
char subtopic[50] = "telstradev";

// initialize the library instance
NBClient client;
GPRS gprs;
NB nbAccess;

//connect the pubsub client
PubSubClient conn(client);

//for the callbacks from the broker
void callback(char* topic, byte* payload, unsigned int length) {
  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = NULL;
  String message(p);

  //output broker message to serial
  Serial.println("Incoming Message: " + message);
}

//connection and reconnection function 
void reconnect() {
    while (!conn.connected()) {
    
    // Attemp to connect
    if (conn.connect(MQTT_CLIENT_NAME, TOKEN, "")) {
      Serial.println("Connected");
      conn.subscribe("online");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(conn.state());
      Serial.println(" try again in 2 seconds");
      // Wait 2 seconds before retrying
      delay(2000);
    }
  }
}

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

  Serial.println("connecting...");

  //set the connection
  conn.setServer(mqttBroker, mqttPort);

  //set the callback 
  conn.setCallback(callback);

  //subscribe to a topic 
  sprintf(topicSubscribe, subtopic);

}

void loop() {

  //if the connection drops then reconnect it 
  if (!conn.connected()) {
    reconnect();
    conn.subscribe(topicSubscribe);   
  }
  conn.loop();

  //publish to the broker queue
  conn.publish(subtopic, "Hello MQTT world");

}