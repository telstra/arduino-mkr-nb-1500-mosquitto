# Telstra Arduino MKR NB 1500 hello world mosquitto

This sketch demonstrates how to;

- Connect to a mosquitto broker using the pubsub and Arduino MQTT Client library
- Subscribe and Publish to a topic via a broker

## Prerequisites

1. A Telstra Arduino MKR NB 1500 board.
1. A Telstra SIM card with an active subscription.
1. A Mosquitto instance (demo one included in the sketch)
1. A computer with Arduino IDE installed 


## How to run using PubSubClient

### Load the sketch onto the device

Install the Arduino MKRNB and PubSubClient libraries via Sketch > Manage Libraries

Connect a data usb cable to the MKR NB 1500 and a computer with the Arduino IDE installed. 

Change the port where the Arduino MKR NB 1500 is connected.

Copy the code from the sketch file catm1_hello_mosquitto.ino, in the sketch folder from this repo, (or load it) into the Arduino IDE window 

Open serial monitor and click the upload button in the Arduino IDE. 

If everything works you should see "Incoming Message: Hello MQTT world" appear in the serial output box once the device has a connection. 

## How to run using Arduino MQTT client (Beta)

### Load the sketch onto the device

Install the Arduino ArduinoMqttClient library via Sketch > Manage Libraries

Connect a data usb cable to the MKR NB 1500 and a computer with the Arduino IDE installed. 

Change the port where the Arduino MKR NB 1500 is connected.

Copy the code from the sketch file catm1_hello_arduino.ino, in the sketch folder from this repo, (or load it) into the Arduino IDE window 

Open serial monitor and click the upload button in the Arduino IDE. 

If everything works you should see "Incoming Message: Hello MQTT world" appear in the serial output box once the device has a connection. 

