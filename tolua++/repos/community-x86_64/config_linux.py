## This is the linux configuration file
# This file was adapted to be used with ArchLinux
# Use 'scons -h' to see the list of command line options available

# Compiler flags (based on ArchLinux's installation of lua)
#LINKFLAGS = ['-g']
CCFLAGS = ['-I/usr/include/lua5.1', '-O2', '-ansi', '-Wall', '-fPIC']
#CCFLAGS = ['-g']

# this is the default directory for installation. Files will be installed on
# <prefix>/bin, <prefix>/lib and <prefix>/include when you run 'scons install'
#
# You can also specify this directory on the command line with the 'prefix'
# option
#
# You can see more 'generic' options for POSIX systems on config_posix.py

prefix = '/usr'

# libraries (based on ArchLinux's installation of lua)
LIBS = ['lua5.1', 'dl', 'm']

