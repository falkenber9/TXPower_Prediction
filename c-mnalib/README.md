c-mnalib
========
<img src="logo.png" height="50" style="float: left;"/>
C-mnalib is a C library for easy access and configuration of mobile network modems, e.g., LTE modems.
The library focuses on providing access to network quality indicators and network parameters of the modems.

Please contact <robert.falkenberg@tu-dortmund.de> for further information about this library.

## Library Overview

### Supported Devices
* Sierra Wireless MC7455 (via AT commands)

### Dependencies
This list is based on Archlinux packages. Other distributions might differ.

#### Library:

* base-devel
    * cmake
    * pkg-config
    * gcc
    * binutils
* glib2
* curl
* libcurl-compat
* libgudev


#### Scripts:

* autossh     (for automatic reverse tunnels)


## Installation
Clone this respository in a working directory and build using cmake. Make sure you have installed the required dependencies.

```
 # cd c-mnalib
 # mkdir build
 # cd build
 # cmake ../
 # make
```

Optional (untested yet):

```
 # sudo make install
```

## Example

```
 # cd build/src/examples
 # ./traffic_test -n 10 -p 30 -s 1000000 -o /tmp/tracefile.txt
```


## License
See the [LICENSE](LICENSE.md) file for license rights and limitations (MIT).

