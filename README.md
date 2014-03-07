[![License](https://poser.pugx.org/leaphly/cart-bundle/license.png)](https://packagist.org/packages/leaphly/cart-bundle)

# Concurrent-GARTH

Concurrent GARTH (Genetic AlgoRiTHms) using C++: A Framework for Concurrent GAs.

Continuous integration is implemented on this repository using Travis-CI.

## Dependencies

This are the dependencies needed to use this library with its applications and automated building (Note: Version numbers are the latest that have been tested but are not necessarily the earliest versions that work correctly).

* C++ compiler that implements the complete(ish) C++11 standard. These are the ones that have currently been tested:
  * GNU GCC 4.8
  * Clang 3.2
  * MSVC 18.0
  * Intel 14.0
* CMake 2.8
* Doxygen
* Google Test
* Python3
* Pip

### Debian-based Dependency Installation

    $ sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
    $ sudo apt-get update
    $ sudo apt-get install g++-4.8 cmake libgtest-dev python3 python-pip
    $ sudo apt-get --no-install-recommends install doxygen
    $ pip install colorama
    $ cd /usr/src/gtest; sudo cmake CMakeLists.txt; sudo make; sudo cp *.a /usr/lib; cd -

You may also need to set a few environment variables/aliases to use the new packages just installed.

    $ export CC="gcc-4.8" CXX="g++-4.8"

## Installation

Run `build.py` at the root of the repo with the prefix needed for installation.

    $ python3 build.py --install-dir="<INSTALL_DIR>"
 
## Copyright

Copyright (C) 2014 Korovasoft, Inc.

## License
This project is released under the [MIT License](http://opensource.org/licenses/MIT). See the LICENSE file for more information.
