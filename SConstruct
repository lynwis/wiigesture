"""
Scons build file for wiiGesture

author : andrea tarocchi
since : 20.10.2008
version : 0.0.1
"""
#START: config variables

#Absolute path of BOOST's includes
#if you use a relative (to this directory) path put a '#' at the start of the path.
#if you use an absolute path the initial '#' symbol is not needed.
BOOST_include = Split("""/home/lynwis/Projects/Libs/boost_1_36_0""")

#Absolute path of BOOST's libraries
#if you use a relative (to this directory) path put a '#' at the start of the path.
#if you use an absolute path the initial '#' symbol is not needed.
BOOST_lib = Split("""/usr/lib""")

ccflags = Split("""""") # compiler options

cppdefines = Split("""""") # cpp defines

libs = Split("""""") #libraries

libpath = Split("""""") + BOOST_lib #libraries paths

cpppath = Split("""#include""") + BOOST_include #include paths

#END: config variables

import os
main_env = Environment(ENV = os.environ)

main_env.Append(LIBS = libs)
main_env.Append(CCFLAGS = ccflags)
main_env.Append(CPPPATH = cpppath)
main_env.Append(LIBPATH = libpath)
main_env.Append(CPPDEFINES = cppdefines)

conf = Configure(main_env)
if not conf.CheckLib('boost_unit_test_framework'):
    print 'Did not find libboost_unit_test_framework. Install it; exiting!'
    Exit(1)
if not conf.CheckHeader('boost/numeric/ublas/matrix.hpp', language='C++'):
    print 'Did not find boost library headers. Install it; exiting!'
    Exit(1)
main_env = conf.Finish()

BuildDir('obj/Debug/src', 'src/', duplicate=0)
BuildDir('obj/Debug/tests', 'tests/', duplicate=0)
BuildDir('obj/Release/src', 'src/', duplicate=0)
BuildDir('obj/Release/tests', 'tests/', duplicate=0)

if 'Release' in COMMAND_LINE_TARGETS:
    env = main_env.Clone()
    env.Append(CCFLAGS = '-O2')
    SConscript('obj/Release/src/SConscript', 'env')

if 'Debug' in COMMAND_LINE_TARGETS:
    env = main_env.Clone()
    env.Append(CCFLAGS = '-g')
    SConscript('obj/Debug/src/SConscript', 'env')
    SConscript('obj/Debug/tests/SConscript', 'env')
