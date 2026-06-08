# Bill of materials

## Main Electronics
Arduino Nano CH340; 2pc; car controller + remote controller

NRF24L01 + PA + LNA Module; 2pc; long range wireless link between car and remote

NRF24 External Antenna 2.4GHz SMA; 2pc; antennas for PA+LNA Modules

NRF24 adapter board/3.3v regulator; 2pc; gives stable 3.3v to NRF

100µF and 10µF capacitor; 2pc each; one near each NRF module to reduce voltage drops

100nF ceramic capacitor; 2-3pc; for MPU6050

3650 2200KV brushless motor; 1pc; to power the car;

ESC 60A; 1pc; controls brushless motor

DS3218 steel gear servo; 1pc; steering

DS3218 Servo; 1pc; DRS flap

Joy stick module; 2pc; one for steering & other for throttle

push buttons; 5-7 pc; ERS,DRS,Modes

LEDs; 4-8 pc; Status indication

buzzers; 2pc; car+remote alerts

power switch; 2pc; Car+remote

Servo extension wire 30cm; 2pc; extending servo connections

HC-05 Bluetooth module; 1pc; phone telemetry dashboard

7805 voltage regulator or 5V 3A buck converter; 1pc; servo power supply

1000µF 25V capacitor; 2pc; ESC voltage spike protection

Anti-spark XT60 connector; 1pc; prevents connection spark saves ESC from spark damage

3650 motor heat sink; 1pc; motor thermal management

ESC programming card; 1pc; ESC configuration

Tactile push button 6×6mm; 3-4pc; Arduino reset + mode buttons

Digital multimeter; 1pc; circuit testing and debugging

Perfboard 5×7cm; 2-3pc; permanent circuit mounting


## Sensors
MPU6050; 1pc; tilt angle, crash detection

Voltage sensor module; 1pc; battery telementry

temperature sensor; 2pc; motor + ESC monitor

Hall effect Sensor; 1pc; Wheel speed measurement

magnet; 1-2; used with hall sensor

3S balance lead connector; 1pc; Monitors each cell individually and prevents cell imbalance damage


## Optical Sensors
IR sensor; 2 to 4 pc; Experimental

LiDAR module; 2 to 4 pc; experimental


## Power system

### Car power system
3S LiPo battery; 2pc; main power source for the car + extra battery

IMAX B6 balance charger; 1pc; to charge the battery

"12V 5A power supply for charger; 1pc; to convert AC current to DC current as B6 charger needs DC current

3S LiPo low voltage alarm; 1pc; alarm triggers at 3.5V per cell

LiPo saftey bag(fire-proof); 1pc; safley charging the battery

LM2596 Buck converter 5V; 1pc; powers Arduino Nano, NRF24 modules, sensors and servos safely

AMS1117 3.3V regulator; 2pc; NRF modules

XT60 connectors; 3-4 pc; battery and esc power connection

Battery-strap/velcro-strap; 1-2pc; battery mounting and retention


### Remote power system
18650 battery holder; 1pc; remote controller power source

18650 Li-ion Cell 3000mAh protected; 2pc; powers the remote controller

18650 battery charger; 1pc; to charge the battery


## Drivetrain(dimensions to be known)
Rubber Wheel Set; 4pc; outdoor and rough-surface driving

Foam Wheel Set; 4pc; indoor and smooth-surface driving

Rear axle; 1pc; transfers power to rear wheels

Front axle/kingpin set; 1pc; front wheel mounting and steering support

Ball bearings; 4-8pc; reduce friction

Pinion gear; 1pc; mounted on motor shaft

Spur gear; 1pc; mounted on rear axle

Motor Mount; 1pc; secures motor to chassis

Wheel hubs/ wheel adapters; 4pc; connects wheels to axles

Steering linkage / Tie rods; 1 set; transfers servo movement to wheels

Steering Knuckles; 2pc; allows front wheel steering

Axle Collars; / Shaft stops; 2-4pc; prevent axle movement

Drive Coupler; 1pc; connects drivetrain components wherever required(if only design requires it)

Motor shaft adapter if required; 1pc; matches motor shaft to pinion gear bore

## Chassis and Body material
Corrugated cardboard sheet; many sheets; main chassis structure

White cardboard sheets; many sheets; body pannels and aerodynamic surfaces

Foam sheet; 1-2pc; paddind and component protection

carbon fiber vinyl wrap; 1 sheet; optional

A3 Grid paper prints; Several sheets; To draw Blueprints and design templates

Butter paper; Several sheets; Creating symmetrical body diagrams and cutouts

Hot glue sticks; many pcs; chassis assembly

Double sided tape; 1 roll; temporary mounting and wire management

Electrical Tape; 1 roll; insulation and wire management

Paint/markers; optional; for designing and colouring

## Wiring and connectors
Male-Male jumper wires; 1 pack; signal connection and testing

Male-Female jumper wires; 1 pack; module connection and testing

Female-Female jumper wires; 1 pack; sensor and module connections

Silicone Wire 14AWG red; 2m; (battery to ESC)

Silicone Wire 14AWG black; 2m; (battery to ESC)

Silicone Wire 22AWG red; 3m; (signal wiring)

Silicone Wire 22AWG black; 3m; (signal wiring)

Hookup wiring; 3-5 mtrs; low current power wiring

Heat Shrink Tube; 1-2 packs wire inulation and protection

Solder Wire; 1 roll; Permanant electrical connections

Dupont Connectors; 1 pack; custom wiring harness

Cable sleeving/wire loom; optional; wire protection and neat rounding

Zip ties; 1 pack; cable management

Wire labels/heat shrink labels; optional; identifiying wires

Terminal Block Connectors; optional; easy maintainence and testing

Electrical tape; 1 rolls; insulation and temporary wire securing

Helping hands soldering stand; 1pc; holds components during soldering

XT60 male pigtail 10cm; 2pc; battery connection harness

## Fasteners and Mounting hardware
M3 Screws; Assorted pack; component mounting

M3 Nuts; Assorted pack; securing screws

M3 washers; Assorted pack; load distribution and protection

Servo mounting screws; 1 set; mounting steering and DRS flap servo

Metal Standoffs 10mm Male-Female; 4-8 pc; mounting Arduino and electronics 

Velcro strips; 1 pack; securing electronics and battery

Double sided Foam tape; 1 roll; vibration isolation and mounting

zip ties; 1 pack; securing wires and components

rubber/foam pads; 1 pack; vibration damping

"Blue Loctite threadlocker; 1pc; prevents screw loosening from vibration

Adhesive cable tie mounts; 1 pack; anchor points for zip ties

# Note: ESC might have BEC inbuilt so i may remove it later...