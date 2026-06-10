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
LM2596 5V Buck convertor
↓
Arduino Nano CH340

LM2596 5V Buck convertor
↓
DS3218
↓
Steering servo

3S LiPo battery balance lead
↓
3S balance lead connector
↓
cell voltage monitoring

# Car side electronics conections
Arduino Nano CH340
↓
NRF24L01 + PA + LNA Module
- powered through NRF24 adapter board/3.3V regulator
- 100µF and 10µF capactors placed near NRF module
- External 2.4GHz SMA antenna connected to NRF module

Arduino Nano CH340
↓
MPU6050
- 100nF Ceramic capactior used for power stability

Arduino Nano CH340
↓
Voltage sensor module
- USed for battery sensor voltage telementry

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
Magnet mounted on wheen/axle
- Used for wheel speed measurement

Arduino nano CH340
↓
HC-05 Bluetooth Module
↓
Phone telementry dashboard

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
18650 battry holder
↓
Power switch
↓
Arduino nano CH340

# Remote side electronics connections

Arduino Nano CH340
↓
NRF24L01 + PA + LNA
- powered through NRF24 adapter board/3.3V regulator
- 100µF and 10µF capactors placed near NRF module
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
- Extra control/saftey buttons

Arduino Nano CH340
↓
Status LEDs
- Remte status indicator

Arduino Nano CH340
↓
Buzzer
- remote side alerts and feedbacks


