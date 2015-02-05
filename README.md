[![Build Status](https://travis-ci.org/calebwherry/Cpp-Libraries.png)](https://travis-ci.org/calebwherry/Concurrent-GARTH)
[![License](https://poser.pugx.org/leaphly/cart-bundle/license.png)](https://packagist.org/packages/leaphly/cart-bundle)

# Concurrent-GARTH-

Concurrent GARTH (Genetic AlgoRiTHms) using C++: A Framework for Concurrent GAs.

Continuous Integration is being run using [Travis-CI](https://travis-ci.org/).

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
* MPI (kind-of, not really used yet)

### Debian-based Dependency Installation

    $ sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
    $ sudo apt-get update
    $ sudo apt-get install build-essential g++-4.8 cmake libgtest-dev python3 python-pip libcr-dev mpich2 mpich2-doc
    $ sudo apt-get --no-install-recommends install doxygen
    $ pip install colorama
    $ cd /usr/src/gtest; sudo cmake CMakeLists.txt; sudo make; sudo cp *.a /usr/lib; cd -

You may also need to set a few environment variables/aliases to use the new packages just installed. Most likely these:

    $ export CC="gcc-4.8" CXX="g++-4.8"

## Installation

Run `build.py` at the root of the repo with the prefix needed for installation:

    $ python3 build.py --install-prefix="<INSTALL_DIR>"
 
If you just run the `build.py` script with no arguments, it will create a local out-of-source build and clean up after itself when it is done. This is extremely handy for testing since all you have to do is run `build.py` and see if anything fails. If not, everything will be cleaned up.

To keep the local build files around, supply the `-k, --keep-build` option.
 
## Copyright

Copyright (C) 2014 Korovasoft, Inc.

## License
This project is released under the [MIT License](http://opensource.org/licenses/MIT). See the LICENSE file for more information.
