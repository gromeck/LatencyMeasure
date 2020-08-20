# LatencyMeasure
A tool to measure latency from keybard or mouse input to a visual response on the screen.

## Challenge

If an application is used in a setup where LAN or WAN segments, technologies like X11 forwarding, VNC, RDP or simply web are involved, the latency might ends up in a poor, user experience.
I needed a tool to measure these latencies from the human input to the visual response at the users screen.

## Solution

I have setup a small circuit with an Arduino compatible micro controller to simulate a HID (human input device) event via USB and registering the change on the screen via a photo transistor. The device will meassure and display the time between these events.
The micro controller is capable to deliver a resulotion of 1 ms.

## What is in this respository?

### [Case](Case/)

In this directory you will find a 3D model of an enclosure for the device, as well as a sensor mount to hang on the screen.
These models are designed with [OpenSCAD](https://www.openscad.org/). Use the latest version of OpenSCAD (nightly build).

![Case](Ressources/Images/LatencyMeasure-Case.png)

### [Circuit](Circuit/)

The circuit around the micro controller is documented here.
The circuit is designed with [KiCad](https://kicad-pcb.org/).
A PDF version is included.

![Curcuit](Ressources/Images/LatencyMeasure-Circuit.png)

### [LatencyMeasure](LatencyMeasure/)

This is the sketch for the micro controller. Use the [ArduinoIDE](https://www.arduino.cc/en/main/software) to compile and upload in the micro controller.

### [TestClient](TestClient/)

This directory includes different test client supporting different setups like
 - an [HTML web application](TestClient/HTML/) to be run in a web browser,

   ![Screenshot-TestClient-HTML](Ressources/Screenshots/Screenshot-TestClient-HTML.png)
   
 - a [text-based application](TestClient/ncurses/) based on [NCURSES](https://invisible-island.net/ncurses/announce.html) written in C, and
 
   ![Screenshot-TestClient-ncurses](Ressources/Screenshots/Screenshot-TestClient-ncurses.png)
   
 - a [graphical application](TestClient/Qt4/) based on [Qt](https://www.qt.io/) written in C++.
 
   ![Screenshot-TestClient-Qt4](Ressources/Screenshots/Screenshot-TestClient-Qt4.png)

All test clients support the same functionality.

### [Ressources](Ressources/)

This directory holds images and screenshots.
