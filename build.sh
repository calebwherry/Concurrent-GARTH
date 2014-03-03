#! /bin/bash
########################################
########################################
##
##  Copyright (C) 2014 Korovasoft, Inc.
##
##  File:
##      \file build.sh
##
##  Description:
##      \brief Build script.
##
##  Author:
##      \author J. Caleb Wherry
##
########################################
########################################


#
# Start time:
#
START_TIME=$(date +%s)


#
# Build root:
#
BUILD_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )/build"
mkdir -p "${BUILD_ROOT}"


#
# Usage function:
#
usage()
{
	printf "Build script for Concurrent-GARTH.\n"
	printf "\n"
	printf "./build.sh\n"
	printf "\t-h, --help \t Usage details.\n"
	printf "\t-c, --clean \t Clean build files.\n"
	printf "\t-k, --keep-build-files \t Keep all build files.\n"
	printf "\t-l, --show-log \t Show build log.\n"
	printf "\n"
}


#
# Cmd line args:
#
while [ "$1" != "" ]; do
	PARAM=`echo $1 | awk -F= '{print $1}'`
	VALUE=`echo $1 | awk -F= '{print $2}'`
	case $PARAM in
		-h | --help)
    	usage
      exit 0
      ;;
		-c | --clean)
    	rm -rf "${BUILD_ROOT}"
			exit 0
      ;;
		-k | --keep-build-files)
			KEEP_BUILD_FILES=TRUE
			;;
		-l | --show-log)
			SHOW_LOG=TRUE
			;;
		*)
			echo "ERROR: Unknown parameter - \"$PARAM\"."
			usage
      exit 1
      ;;
	esac

	shift
done


#
# Get time stamp:
#
TIMESTAMP="`date +\"%Y-%m-%d_%T\"`"


#
# Build directory name:
#
BUILD_DIR="${BUILD_ROOT}/build_${TIMESTAMP}"


#
# Install directory name:
#
INSTALL_DIR="${BUILD_ROOT}/install_${TIMESTAMP}"


#
# Logfile name:
#
LOGFILE="${BUILD_ROOT}/build_${TIMESTAMP}.log"


#
# Exit status of commands:
#
STATUS=0


#
# Create build/install directories:
#
echo
echo -n "Creating build/install directories... "
(
mkdir "${BUILD_DIR}"
mkdir "${INSTALL_DIR}"
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
	echo "** ERROR: Could not create build/install directories, please check ${LOGFILE}. **"
	echo
	cat "${LOGFILE}"
	exit 1
else
	echo "done."
fi


#
# CD into new build directory:
#
cd "${BUILD_DIR}"


#
# Run cmake:
#
echo -n "Running 'cmake'... "
(
cmake ../../ -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}"
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
	echo "** ERROR: 'cmake' encountered a problem, please check ${LOGFILE}! **"
	echo
	cat "${LOGFILE}"
	exit 1
else
	echo "done."
fi


#
# Run make:
#
echo -n "Running 'make'... "
(
make
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
	echo "** ERROR: 'make' encountered a problem, please check ${LOGFILE}! **"
	echo
	cat "${LOGFILE}"
	exit 1
else
	echo "done."
fi


#
# Run make test:
#
echo -n "Running 'make test'... "
(
make test
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
	echo "** ERROR: 'make test' encountered a problem, please check ${LOGFILE}! **"
	echo
	cat "${LOGFILE}"
	exit 1
else
	echo "done."
fi


#
# Run make doc:
#
echo -n "Running 'make doc'... "
(
make doc
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
	echo "** ERROR: 'make doc' encountered a problem, please check ${LOGFILE}! **"
	echo
	cat "${LOGFILE}"
	exit 1
else
	echo "done."
fi


#
# Run make install:
#
echo -n "Running 'make install'... "
(
make install
) >> ${LOGFILE} 2>&1
STATUS=$?

if [ ${STATUS} -ne 0 ]
then
	echo "** ERROR: 'make install' encountered a problem, please check ${LOGFILE}! **"
	echo
	cat "${LOGFILE}"
	exit 1
else
	echo "done."
fi


#
# Show log if flag set:
#
if [ ! -z "${SHOW_LOG}" ]
then
	echo
	echo "Log file contents:"
	cat "${LOGFILE}"
	echo
fi


#
# Cleanup build if keep-files flag not set:
#
if [ -z "${KEEP_BUILD_FILES}" ]
then
	echo -n "Cleaning up build files..."
	cd ..
	rm -rf "${BUILD_ROOT}"
	echo " done."
fi


#
# Stop time:
#
STOP_TIME=$(date +%s)


#
# Elapsed time:
#
echo
echo "Build completed successfully in $(expr ${STOP_TIME} - ${START_TIME}) seconds!"
echo


#
# Exit cleanly:
#
exit 0