# M5StampFly Skeleton

Providing the skeleton firmware for M5Stack's StampFly and AtomJoyStick, feel free to customize it as you like.

## Policy

- Provides APIs for motor, IMU, attitude estimation, and ToF
- A 400Hz periodic function for control is provided, so you can easily create a flight program by adding your own code to it
- Provides telemetry logging functionality when combined with AtomJoyStick

## ToDo

- If requested, APIs for optical flow and barometric pressure can also be provided
- Conduct usage documentation and workshops

## Supported Controllers

- Kohei's Simple Firmware https://github.com/M5Fly-kanazawa/Simple_StampFly_Joy

## Where to Start Reading

### Start with "main_loop.cpp"
Please start by reading the void "loop_400Hz(void)" function in "main_loop.cpp". This is where you will likely add your original code.

### Next is "sensor.cpp"
Since sensor processing is written here, "sensor.cpp" is also important.

## Reference Materials

- StampFly & Atom Joystick Firmware Writing Guide https://docs.m5stack.com/en/guide/hobby_kit/stampfly/stamply_firmware
- Building and Writing Control Programs for StampFly https://rikei-tawamure.com/entry/2023/11/19/101426

### M5 Stamp Fly Related

- Original Firmware https://github.com/m5stack/M5StampFly
- Kohei's Firmware https://github.com/M5Fly-kanazawa/M5StampFly

|Specification|Overview|
|----|----|
|M5StampS3|ESP32-S3@Xtensa LX7, 8 MB-FLASH, Wi-Fi, OTG/CDC support|
|Distance Sensor|VL53L3CXV0DH/1 (0x52) @ max 3m|
|Optical Flow Sensor|PMW3901MB-TXQT|
|Barometric Sensor|BMP280 (0x76) @ 300-1100 hPa|
|3-axis Magnetic Sensor|BMM150 (0x10)|
|6-axis IMU Sensor|BMI270|
|Battery|300 mAh High Voltage Lithium Polymer Battery (LiHV)|
|Current Voltage Meter|INA3221AIRGVR (0x40)|
|Buzzer|Built-in Buzzer @ 5020|
|Product Size|107 x 107 x 30 mm|
|Product Weight|36.2 g|

### M5 Atom JoyStick Related

- Original Firmware https://github.com/m5stack/Atom-JoyStick
- Kohei's Simple Firmware https://github.com/M5Fly-kanazawa/Simple_StampFly_Joy
