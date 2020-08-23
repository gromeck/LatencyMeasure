
<div style="float:left;">
<img src="Ressources/Photos/LatencyMeasure-Breadboard-1.jpg" height="300px">
<img src="Ressources/Photos/LatencyMeasure-Breadboard-2.jpg" height="300px">
</div>

# LatencyMeasure
A tool to measure latency from keybard or mouse input to a visual response on the screen.

## Challenge

If an application is used in a setup where LAN or WAN segments, technologies like X11 forwarding, VNC, RDP or simply web are involved, the latency might ends up in a poor, user experience.
I needed a tool to measure these latencies from the human input to the visual response at the users screen.

## Solution

I have setup a small circuit with an Arduino compatible micro controller to simulate a HID (human input device) event via USB and registering the change on the screen via a photo transistor. The device will meassure and display the time between these events.
The micro controller is capable to deliver a resulotion of 1 ms.

## What is in this respository?

### [Circuit](Circuit/)

The circuit around the micro controller is documented here.
The circuit is designed with [KiCad](https://kicad-pcb.org/).
A PDF version is included.

The micro controller is a SparkFun Micro Pro 3.3V @ 8MHz. This controller is capable to work as a HID device (mouse or keyboard).

The photo transistor SFH300 (Note: don't use the infrared versions) is used as the sensor for the screen. The signal from the photo transistor and a reference voltage are the inputs for the used OpAmp LM393. These two inputs are also used as analog inputs, to allow the user an easy calibration of the sensor.

The buttons MODE and OK are used for the navigation of the controllers application. The RESET button does what it says.

To test the timing of the circuit, the sensor is placed over the LED and the controllers timing test is started. This confirms the resulution and the processing speed of the device.

To display the main menu, the different pages like configuration, calibration as well as the measurment and its results, a small OLED is used with 128x32px (which is 4 rows 20 characters each).

![Curcuit](Circuit/LatencyMeasure.png)

### [LatencyMeasure Sketch](LatencyMeasure/)

This is the sketch for the micro controller. Use the [ArduinoIDE](https://www.arduino.cc/en/main/software) to compile and upload into the micro controller.

Here are some screenshots from the OLED of the device in use.

<div style="float:left;">
<img src="Ressources/Screenshots/Screenshot-OLED-Menu-1.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Measurement-1.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Measurement-2.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Menu-2.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Configure-1.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Configure-2.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Configure-3.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Configure-4.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Configure-5.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Configure-6.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Configure-7.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Menu-3.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Calibrate-Sensor-1.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Calibrate-Sensor-2.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Calibrate-Sensor-3.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Menu-4.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Test-Timing-1.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Test-Timing-2.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Menu-5.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Device-Info-1.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Device-Info-2.png" height="64px">
<img src="Ressources/Screenshots/Screenshot-OLED-Device-Info-3.png" height="64px">
</div>

As a special feature, one pin of the micro controller is used to trigger a screenshot of the OLED. The display is then transfered as a [Portable BitMap file](https://en.wikipedia.org/wiki/Netpbm#File_formats) over the serial connection. There is also a script in the repository to post-process these as colorized PNG files.

### [TestClient](TestClient/)

This directory includes different test client supporting different setups like
 - an [HTML web application](TestClient/HTML/) to be run in a web browser,

   ![Screenshot-TestClient-HTML](TestClient/HTML/Screenshot.png)
   
 - a [text-based application](TestClient/ncurses/) based on [NCURSES](https://invisible-island.net/ncurses/announce.html) written in C, and
 
   ![Screenshot-TestClient-ncurses](TestClient/ncurses/Screenshot.png)
   
 - a [graphical application](TestClient/Qt4/) based on [Qt](https://www.qt.io/) written in C++.
 
   ![Screenshot-TestClient-Qt4](TestClient/Qt4/Screenshot.png)

All test clients support the same functionality.

### [Case](Case/)

In this directory you will find a 3D model of an enclosure for the device, as well as a sensor mount to hang on the screen.
These models are designed with [OpenSCAD](https://www.openscad.org/). Use the latest version of OpenSCAD (nightly build).

![Case](Case/LatencyMeasure.png)

### [Ressources](Ressources/)

This directory holds images and screenshots.
