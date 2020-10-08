# Embedded Measurement System
### Description 
Developed an embedded measurement system that scans surrounding quickly, and reconstruct an accurate graphical representation of the environment.

#### Example of a scanned narrow hallway:
![121106799_760159604827460_52969989181416527_n](https://user-images.githubusercontent.com/46755190/95444662-10343500-092c-11eb-96f6-97ed3e5d70f0.png)

### How it is built
The microcontroller is programmed with C and assembly. The measurement system requires
* MSP432E401Y MicroController
* VL53L1X Time of Flight sensor
* ULN2003 stepper motor

#### Circuit Schematic:
(The Time of Flight sensor is attached to the stepper motor)
![image20](https://user-images.githubusercontent.com/46755190/95446355-2c38d600-092e-11eb-9f07-e685d53aa24b.png)

### Files
* Excel dataset - Measured data point and exported from microcontroller
* Main.py - Python code for generating the graphical environment 
* MicroController_Code - contains all necessary files for microcontroller





