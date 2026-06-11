### Roadrunner Wiring Plan


## Car side

# Power Flow
3S LiPo Battery
↓
Anti-spark XT60 Connectors
↓
60A ESC
↓
3650 2200KV Brushless Motor


3S LiPo
↓
LM2596 5V Buck converter
↓
Arduino Nano CH340

LM2596 5V Buck converter
↓
DS3218
↓
Steering servo

3S LiPo battery balance lead
↓
3S balance lead connector
↓
cell voltage monitoring

# Car side electronics connections
Arduino Nano CH340
↓
NRF24L01 + PA + LNA Module
- powered through NRF24 adapter board/3.3V regulator
- 100µF and 10µF capacitors placed near NRF module
- External 2.4GHz SMA antenna connected to NRF module

Arduino Nano CH340
↓
MPU6050
- 100nF Ceramic capacitor used for power stability

Arduino Nano CH340
↓
Voltage sensor module
- Used for battery sensor voltage telemetry

Arduino nano CH340
↓
temperature sensor 1
- Monitor temperature of motor

Arduino nano CH340
↓
temperature sensor 2
- monitor temperature of ESC

Arduino Nano CH340
↓
Hall effect sensor
↓
Magnet mounted on wheel/axle
- Used for wheel speed measurement

Arduino Nano CH340
↓
Buzzer
↓
Car-side alerts and Failsafe warnings

Arduino Nano CH340
↓
Status LEDS
↓
Car status indication

## Remote side

# Remote side power flow
18650 Li-ion cells
↓
18650 battery holder
↓
Power switch
↓
Arduino nano CH340

# Remote side electronics connections

Arduino Nano CH340
↓
NRF24L01 + PA + LNA
- powered through NRF24 adapter board/3.3V regulator
- 100µF and 10µF capacitors placed near NRF module
- External 2.4GHz SMA antenna connected to NRF module

Arduino Nano CH340
↓
Joystick Module 1
- Throttle input

Arduino Nano CH340
↓
Joystick Module 2
- Steering input 

Arduino Nano CH340
↓
Push buttons
- DRS button
- ERS button
- Mode selection
- Extra control/safety buttons

Arduino Nano CH340
↓
Status LEDs
- Remote status indicator

Arduino Nano CH340
↓
Buzzer
- remote side alerts and feedback

# Communication Flow
- Remote control Mode

Remote Arduino Nano
↓
Remote NRF24L01 + PA + LNA
⇄
Car NRF24L01 + PA + LNA
↓
Car Arduino

- Gyro mode

MPU6050(On remote)
↓
Remote Arduino reads tilt
↓
Remote sends steering value via NRF24
↓
Car Arduino controls steering servo



# Telemetry Flow
Car Sensors
↓
Car Arduino
↓
NRF24
↓
Remote Arduino
↓
USB cable
↓
Phone dashboard
- shows data such as
1. Battery voltage
2. ERS
3. DRS
4. Wheel speed
5. Driving mode
6. NRF Signal strength
7. Temperature of ESC and Motor


##### Note:-
there is no specifications about DRS servo/motor planning;
It will be added later