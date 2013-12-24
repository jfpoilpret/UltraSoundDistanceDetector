UltraSoundDistanceDetector
==========================

This is an Arduino sketch example that calculates the distance between an ultrasonic sensor and an obstacle, then displays that distance to a 4-digit 7-segment LED display, through a display driver based on MAX-7219.

The example was created on [Eclipse](http://www.eclipse.org/) with an [Arduino plugin](http://www.baeyens.it/eclipse/).
Hence it can be directly compiled under the same environment but needs some adaptations to be compiled by the usual Arduino IDE. These adaptations are described inside UltraSoundDistanceDetector.cpp.

The sketch uses an HC-SR04 ultrasonic sensor for distance measurements and a special home-made display driver board, based on MAX7219 LED driver.

The display driver schema follows the following diagram:

TODO 

The board is wired on a stripboard according to the following schema.

TODO

Note that I have used [sPlan 7.0](TODO) for the diagram and [LochMaster 4.0](TODO) for the stripboard circuit.
Here are the original files for the diagram and stripboard:

TODO

If you don't want to buy sPlan or LochMaster, you can still open these files with free viewers:

TODO
