# Arduino-based Mini Disinfectant Chamber
This code will provide a simple arduino mechanism to run a mini disinfectant chamber. In this disinfectant chamber, we will be able to automatically spray disinfectant to medium sized object such as package and food delivery. This chamber should provide contactless receiving between the courier and the recipient thus decreasing the possibility of COVID-19 spread. 

## Tools and Materials
1. Wemos D1 R1 microcontroller
2. 5V Relay
3. 12V Water pump
4. Breadboard
5. Ultrasonic Sensor(HV-SR04)

## Circuit Diagram
![alt text](https://i.imgur.com/NIf5nXh.png)

## Frame Design
We have several prototypes from different materials but we ended up using acrylic sheet to make the final frame. 
### 3D Design Render
![alt text](https://i.imgur.com/8aEHvI4.png)
### Final Frame
![alt text](https://i.imgur.com/lvVbiEq.jpg)
![alt text](https://i.imgur.com/fS3uBbo.jpg)

## Additional Feature
We connect the program with IFTTT(If This Then That) Webhook services to launch an push notification in the IFTTT smartphone app. We utilize MDevolution's code to use webhook service with ESP8266 from https://gist.github.com/MDevolution/a2ca7257922a859ba24554255b21b7d1.

## Contributor
- William Nathan
- Stefan Rafael Muljadi
- Immanuel Krisliandi
