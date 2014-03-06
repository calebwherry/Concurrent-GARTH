#! /usr/bin/env python3
########################################
########################################
##
##  Copyright (C) 2014 Korovasoft, Inc.
##
##  File:
##      \file build.py
##
##  Description:
##      \brief Python build script.
##
##  Author:
##      \author J. Caleb Wherry
##
########################################
########################################


#
# Imports:
#
import subprocess
from os import path, getcwd, mkdir, chdir
from sys import exit, argv
from platform import system
from time import time
from datetime import datetime
from shutil import rmtree



#
# Print logfile to stdout function:
#
def displayLog(logFile):

	# Open file and print it to stdout:
	with open(logFile, 'r') as fin:
		print(fin.read())



#
# Build function: Unix
#
def unixBuild(log):

	print('Starting UNIX build...')
	print('')


	# Run make:
	print("Running 'make'... ", end='')
	returnCode = subprocess.call(["make"], stdout=log, stderr=subprocess.STDOUT)
	
	if returnCode != 0:
		print('ERROR!!! Please see log file for details: ' + log.name)
		displayLog(log.name)
		exit(1)

	print('done!')


	# Run make test:
	print("Running 'make test'... ", end='')
	returnCode = subprocess.call(["make", "test"], stdout=log, stderr=subprocess.STDOUT)

	if returnCode != 0:
		print('ERROR!!! Please see log file for details: ' + log.name)
		displayLog(log.name)
		exit(1)

	print('done!')


	# Run make doc:
	print("Running 'make doc'... ", end='')
	returnCode = subprocess.call(["make", "doc"], stdout=log, stderr=subprocess.STDOUT)

	if returnCode != 0:
		print('ERROR!!! Please see log file for details: ' + log.name)
		displayLog(log.name)
		exit(1)

	print('done!')


	# Run make install:
	print("Running 'make install'... ", end='')
	returnCode = subprocess.call(["make", "install"], stdout=log, stderr=subprocess.STDOUT)

	if returnCode != 0:
		print('ERROR!!! Please see log file for details: ' + log.name)
		displayLog(log.name)
		exit(1)

	print('done!')



#
# Build function: Windows
#
def windowsBuild(log):
	print('Starting Windows build...')
	print('')

  
	# Run msbuild:
	print("Running 'msbuild'... ", end='')
	returnCode = subprocess.call(["msbuild", "ALL_BUILD.vcxproj"], stdout=log, stderr=subprocess.STDOUT)
	
	if returnCode != 0:
		print('ERROR!!! Please see log file for details: ' + log.name)
		displayLog(log.name)
		exit(1)

	print('done!')



#
# Main function:
#
def main():

	# Start time for script:
	startTime = time()

	# Get timestamp:
	timeStamp = datetime.fromtimestamp(time()).strftime('%Y-%m-%d_%H-%M-%S')

	# Get current path:
	currentPath = path.abspath(getcwd())

	# Get script path:
	scriptPath = path.abspath(path.dirname(argv[0]))

	# Get OS:
	localOS = system()

	# Create build directories and cd into them:
	buildRoot = path.join(currentPath, 'local-build_' + timeStamp)
	buildFiles = path.join(buildRoot, 'build_files')
	installFiles = path.join(buildRoot, 'install_files')
	mkdir(buildRoot)
	mkdir(buildFiles)
	mkdir(installFiles)
	chdir(buildFiles)

	# Create logfile:
	logFile = path.join(buildRoot, 'build.log')
	log = open(logFile, 'w');

	# On all platforms, we at least have to run cmake first to get build files built:
	print("Running 'cmake'...", end='')
	returnCode = subprocess.call(["cmake", scriptPath, "-DCMAKE_INSTALL_PREFIX=" + installFiles], stdout=log, stderr=subprocess.STDOUT)

	if returnCode != 0:
		print('ERROR!!! Please see log file for details: ' + log.name)
		displayLog(log.name)
		exit(1)

	print('done!')
	print('')

	# Run build based on platform from this point on:
	if localOS == 'Linux' or localOS == 'Darwin':
		unixBuild(log)
	elif localOS == 'Windows':
		windowsBuild(log)
	else:
		print('**ERROR**: OS platform "' + localOS + '" not recognized; aborting!')
		exit(1)

	# Move back to script location and close log file:
	chdir(scriptPath)
	log.close()

	# Remove build directory if everything up till now has not exited:
	rmtree(buildRoot)
  
	# End execution time:
	endTime = time()

	# Display build script execution time:
	print('')
	print('Build script executed in %g seconds!' % (endTime - startTime))


#
# Main:
#
if __name__ == "__main__":
	main()
