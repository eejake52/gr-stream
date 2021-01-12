# gr-stream
OOT module for GnuRadioCompanion that selects from multiple input streams to a single output stream.

## Prerequisites - Hardware
  - None

## Prerequisites - Software
  - Unix style os (tested on Ubuntu 20.04)
  - GnuRadio 3.7.*

## Build 
  - in a terminal session, cd to the directory above your preferred destination, then:
```
git clone https://github.com/eejake52/gr-stream
cd gr-stream
mkdir build
cd build
cmake ../
make
sudo make install
sudo ldconfig
```

## Test
Try the SelectExample grc file
