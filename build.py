#!/usr/bin/env python3
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
import argparse, subprocess
from os import path, getcwd, mkdir, chdir
from sys import exit, argv
from platform import system
from time import time
from datetime import datetime
from shutil import rmtree
from glob import glob
from colorama import init, Fore


#
# Print logfile to stdout - function:
#
def displayLog(log):

  print('')
  print(Fore.CYAN + '#############################')
  print(Fore.CYAN + 'Dumping log file: ' + log.name)
  print(Fore.CYAN + '#############################')
  print('')

  # Open file and print it to stdout:
  with open(log.name, 'r') as fin:
    print(fin.read())

  print('')
  print(Fore.CYAN + '#############################')
  print(Fore.CYAN + 'End log dump.')
  print(Fore.CYAN + '#############################')
  print('')



#
# Build function: Unix
#
def unixBuild(log):

  print('Starting UNIX build...')

  # Run make:
  print("\tRunning 'make'... ", end='')
  returnCode = subprocess.call(["make"], stdout=log, stderr=subprocess.STDOUT)
  
  if returnCode != 0:
    print(Fore.RED + 'ERROR!!! Please see log file for details: ' + log.name)
    displayLog(log)
    exit(1)
  print(Fore.GREEN + 'done!')


  # Run make test:
  print("\tRunning 'make test'... ", end='')
  returnCode = subprocess.call(["make", "test"], stdout=log, stderr=subprocess.STDOUT)

  if returnCode != 0:
    print(Fore.RED + 'ERROR!!! Please see log file for details: ' + log.name)
    displayLog(log)
    exit(1)
  print(Fore.GREEN + 'done!')


  # Run make doc:
  print("\tRunning 'make doc'... ", end='')
  returnCode = subprocess.call(["make", "doc"], stdout=log, stderr=subprocess.STDOUT)

  if returnCode != 0:
    print(Fore.RED + 'ERROR!!! Please see log file for details: ' + log.name)
    displayLog(log)
    exit(1)
  print(Fore.GREEN + 'done!')


  # Run make install:
  print("\tRunning 'make install'... ", end='')
  returnCode = subprocess.call(["make", "install"], stdout=log, stderr=subprocess.STDOUT)

  if returnCode != 0:
    print(Fore.RED + 'ERROR!!! Please see log file for details: ' + log.name)
    displayLog(log)
    exit(1)
  print(Fore.GREEN + 'done!')

  # End of unix build:
  print('UNIX build complete!')
  print('')



#
# Build function: Windows
#
def windowsBuild(log):
  print('Starting Windows build...')
  
  # Run msbuild:
  print("\tRunning 'msbuild'... ", end='')
  returnCode = subprocess.call(["msbuild", "ALL_BUILD.vcxproj"], stdout=log, stderr=subprocess.STDOUT)
  
  if returnCode != 0:
    print(Fore.RED + 'ERROR!!! Please see log file for details: ' + log.name)
    displayLog(log)
    exit(1)
  print(Fore.GREEN + 'done!')

  # End of windows build:
  print('Windows build complete!')
  print('')


#
# Main function:
#
def main():

  #
  # Start time for script:
  #
  startTime = time()


  #
  # Argument parsing:
  #
  parser = argparse.ArgumentParser()
  parser.add_argument("-i", "--install-prefix", help="Prefix for the install directory.", type=str, default="")
  parser.add_argument("-c", "--clean", help="Remove all build directories in current working directory matching 'local-build_*' and exit.", action="store_true")
  parser.add_argument("-k", "--keep-build", help="Keep current build directory, do not remove after build completes.", action="store_true")
  parser.add_argument("-d", "--display-log", help="Display build log to stdout.", action="store_true")
  args = parser.parse_args()


  #
  # Build script init output:
  #
  print('')
  print(Fore.MAGENTA + '######################')
  print(Fore.MAGENTA + 'Automated Build Script')
  print(Fore.MAGENTA + '######################')
  print('')


  #
  # Clean build directories if clean specified:
  #
  if args.clean:
    print("Removing all build directories matching 'local-build_*'... ", end='')
    buildDirs = glob('local-build_*')
    buildDirs = filter(path.isdir, buildDirs)
    for dir in buildDirs: rmtree(dir)
    print(Fore.GREEN + 'done!')
    print('')
    exit(0)


  # Get timestamp:
  timeStamp = datetime.fromtimestamp(time()).strftime('%Y-%m-%d_%H-%M-%S')

  # Get current path:
  currentPath = path.abspath(getcwd())

  # Get script path:
  # TODO: This SHOULD be cross-platform but some people say it isn't because of the argv... 
  # I have yet to come across a situation where this fails so I'm leaving it.
  scriptPath = path.abspath(path.dirname(argv[0]))

  # Get OS:
  localOS = system()

  # Create build directories:
  buildRoot = path.join(currentPath, 'local-build_' + timeStamp)
  buildDir = path.join(buildRoot, 'build_files')
  mkdir(buildRoot)
  mkdir(buildDir)

  # Create install directory if prefix was not supplied:
  if args.install_prefix == "":
    installDir = path.join(buildRoot, 'install_files')
    mkdir(installDir)
  else:
    installDir = path.join(args.install_prefix)

  # Move into build directory:
  chdir(buildDir)

  # Create logfile:
  logFile = path.join(buildRoot, 'build.log')
  log = open(logFile, 'w');

  # On all platforms, we at least have to run cmake first to get build files built:
  print("Running 'cmake'... ", end='')
  returnCode = subprocess.call(["cmake", scriptPath, "-DCMAKE_INSTALL_PREFIX=" + installDir], stdout=log, stderr=subprocess.STDOUT)

  if returnCode != 0:
    print(Fore.RED + 'ERROR!!! Please see log file for details: ' + log.name)
    displayLog(log)
    exit(1)
  print(Fore.GREEN + 'done!')
  print('')

  # Run build based on platform from this point on:
  if localOS == 'Linux' or localOS == 'Darwin':
    unixBuild(log)
  elif localOS == 'Windows':
    windowsBuild(log)
  else:
    print(Fore.RED + '**ERROR**: OS platform "' + localOS + '" not recognized; aborting!')
    exit(1)

  # Display log if cmd argument set:
  if args.display_log:
    displayLog(log)

  # Close log file:
  log.close()

  # Remove build directory if everything up till now has not exited and keep build flag not set:
  chdir(scriptPath)
  if not args.keep_build:
    print('Removing current build directory (-k, --keep-build to disable)... ', end='')
    rmtree(buildRoot)
    print(Fore.GREEN + 'done!')
    print('')
  
  # End execution time:
  endTime = time()

  # Display build script execution time:
  print(Fore.MAGENTA + 'Build script executed in %g seconds!' % (endTime - startTime))
  print('')


#
# Main:
#
if __name__ == "__main__":


  #
  # Init colorama:
  #
  init(autoreset=True)


  #
  # Call main function:
  #
  main()
