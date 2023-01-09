#!/usr/bin/env python3

import re, os, sys, platform, shutil
from pathlib import Path, PurePath
import pathlib
print(pathlib.__file__)
import subprocess as sp

# build script for SolarTherm -- use 'scons' to run it.
# philopsophy here is:
#    - Needed tools like 'solstice' etc should be in the PATH at build-time
#    - We will provide a script called 'st' that makes all required environment var settings
#      at run-time, to try to avoid any challenges for configuration for the end user.
#    - We assume that Solstice is installed on Windows using our Windows installer.
#    - Ultimately we are aiming for a setup process that can be completely automated using
#      standard package managers like apt-get and pacman, but we're not there yet.

default_prefix=Path.home()/'.local'
default_pyversion = "%d.%d" % (sys.version_info[0],sys.version_info[1])

#print('system',platform.system())
if platform.system()=="Windows" or "MINGW" in platform.system():
	if os.environ.get('MSYSTEM') == "MINGW64":
		default_prefix=Path(os.environ['HOME'])/'.local'
		default_install_omlibrary = '$PREFIX/lib/omlibrary'
		default_mpirun = 'mpiexec'
	else:
		raise RuntimeError("On Windows, you must use MSYS2 in 64-bit mode.")
else:
	default_install_omlibrary = Path(os.environ['HOME'])/'.openmodelica'/'libraries'#'$PREFIX/lib/omlibrary'
	default_mpirun = 'mpirun'

#---------------------------------------------------------------------------------------------------
# Install (nearly) all files in 'SolarTherm' folder

vars = Variables()
vars.AddVariables(
	PathVariable('PREFIX','File installation prefix',default_prefix,PathVariable.PathIsDirCreate)
	,PathVariable('INSTALL_OMLIBRARY','Installation path for Modelica code',default_install_omlibrary,PathVariable.PathIsDirCreate)
	,PathVariable('INSTALL_OM_ST','Installation path for Modelica SolarTherm library','$INSTALL_OMLIBRARY/SolarTherm', PathVariable.PathIsDirCreate)
)

env = Environment(variables=vars)

env['VERSION'] = '0.2'
env['SUBST_DICT'] = {
	'@VERSION@' : '$VERSION'
	,'@PYTHON@' : '$PYTHON'
	,'@PREFIX@' : '$PREFIX'
}

env.SConscript(
	['src/SConscript']
	, exports='env'
)

fre = re.compile(r'^(.*)\.(mo|motab|csv|CSV|txt|order)$')
#print("test.mo:",fre.match('test.mo'))
#sys.exit(1)
def fmatch(root,fns):
	for f in fns:
		if fre.match(f):
			yield str(Path(root)/f)

stfiles = []
for root,dirs,fns in os.walk('SolarTherm'):
	r1 = Path(root).relative_to('SolarTherm')
	env.Install('$INSTALL_OM_ST/%s'%(r1,),list(fmatch(root,fns)))

env.Alias('install',['#','$PREFIX','$INSTALL_OMLIBRARY'])

