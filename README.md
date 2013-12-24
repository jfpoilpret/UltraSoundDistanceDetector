UltraSoundDistanceDetector
==========================

This is an Arduino sketch example that calculates the distance between an ultrasonic sensor and an obstacle, then displays that distance to a 4-digit 7-segment LED display, through a display driver based on MAX-7219.

**IMPORTANT!** At the time of pushing this sketch to github, I don't have access to my circuits, so this is not tested yet! I will update this repo as soon as I can test it.

The example was created on [Eclipse](http://www.eclipse.org/) with an [Arduino plugin](http://www.baeyens.it/eclipse/).
Hence it can be directly compiled under the same environment but needs some adaptations to be compiled by the usual Arduino IDE. These adaptations are described inside UltraSoundDistanceDetector.cpp.

The sketch uses an HC-SR04 ultrasonic sensor for distance measurements and a special home-made display driver board, based on MAX7219 LED driver.

As the sketch is using the Arduino [LedControl library](http://playground.arduino.cc/uploads/Main/LedControl.zip), you have to install it first to your own setup.

The display driver schema was designed according to the following diagram:
![Display Driver schema](/docs/DisplayDriver-diagram.JPG)

The board is wired on a stripboard according to the following circuits:
![stripboard component side](/docs/DisplayDriver-board-1.JPG)
![stripboard copper side](/docs/DisplayDriver-board-2.JPG)

Note that, for designing, I have used [sPlan 7.0](http://www.abacom-online.de/uk/html/splan.html) for the diagram and [LochMaster 4.0](http://www.abacom-online.de/uk/html/lochmaster.html) for the stripboard circuit. These are simple and rather cheap tools that I was glad to pay for.
Here are the original files for the diagram and stripboard:
[schema](/docs/4DigitsMux.spl7) and [stripboard](/docs/4DigitsMux2.LM4)

If you don't want to buy sPlan or LochMaster, you can still open these files with free viewers for [sPlan](http://www.abacom-online.de/updates/sPlan70_Viewer.exe) and [LochMaster](http://www.abacom-online.de/updates/LochMaster40_Viewer.zip).

*NOTE* In the near future, I will create Arduino libraries for the display driver circuit and for the ultrasound sensor and push these into their own repos, so that the content of the current repo should be simplified.
