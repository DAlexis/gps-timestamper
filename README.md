GPS timestamper project
=======================

Open-source device based on STM32 that provides precision time stamps
of trigger signal connected to input. It use GPS PPS signal to provide
~1uS precision time mesurment. Also it makes self-calibration by PPS
every second.

Device may be used to synchronize any signals and data streams without
wired or wireless connection i.e. in geophysical researches, lightning 
detection networks, seismology and others

Currently project in protortype state and under development. Primary
function (precision timestamping) works correctly.

# Build
To build firmware you may have installed `arm-gcc` toolchain on your
linux system. If you do not need unit tests, simply comment out
corresponding line in root CMakeLists.txt (to build tests `gtest` should
be installed on your system)

Run `build.sh` and thats all. To flash MCU, connect ST-Link device to
PC and then run `flash.sh`.
