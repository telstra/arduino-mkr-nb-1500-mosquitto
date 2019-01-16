# Telstra Arduino MKR NB 1500 hello world mosquitto

This sketch demonstrates how to;

- Connect to a mosquitto broker using the pubsub library
- Subscribe and Publish to a topic

## Prerequisites

1. A Telstra Arduino MKR NB 1500 board.
1. A Telstra SIM card with an active subscription.
1. A Mosquitto instance (demo one included in the sketch)
1. A computer with the Arduino IDE installed 
1. Install the Arduino MKRNB and PubSubClient libraries via Sketch > Manage Libraries

## How to run

### Load the sketch onto the device

Connect a data usb cable to the MKR NB 1500 and a computer with the Arduino IDE installed. 

Change the port where the Arduino MKR NB 1500 is connected.

Copy the sketch code, from the sketch folder in this repo, (or load it) into the Arduino IDE window 

Open serial monitor and click the upload button in the Arduino IDE. 

If everything works you should see "Incoming Message: Hello MQTT world" appear in the serial output box once the device has a connection. 


