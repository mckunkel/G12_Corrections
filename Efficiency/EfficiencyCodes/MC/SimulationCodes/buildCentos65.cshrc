#!/bin/csh

########################################################################
# PREFIX and non-system programs/libraries
########################################################################

### prefix area
#setenv PREFIX /work/clas/clasg12/mkunkel/clas_builds/CENTOS65/clas_64_trunk
setenv PREFIX /u/group/clas/builds/centos65/trunk

### non-system builds of programs and libraries
setenv GCC /apps/gcc/4.8.0
setenv ROOT /apps/root/5.34.05
setenv CERN /apps/cernlib/x86_64_rhel6_4.7.2/2005
#setenv CERN_LEVEL 2005
setenv PYTHON /apps/python
setenv SCONS /apps/scons
setenv BOOST /group/clas/boost/boost-1.53.0
setenv PLUTO_BUILD /work/clas/clasg12/mkunkel/PLUTO/pluto_v5.42
setenv PLUTO_SRC $PLUTO_BUILD/src
setenv PLUTO_LIB $PLUTO_BUILD/lib
setenv PLUTO_INC $PLUTO_BUILD/src
setenv PLUTO_PLUGINS $PLUTO_BUILD/plugins
setenv ROOT_FASTMC /u/home/mkunkel/FASTMC_CVS/tracking/root_fastmc
setenv FASTMC /u/home/mkunkel/FASTMC_CVS/tracking/fastmc/clasev/
########################################################################
# PATH
########################################################################

setenv PATH .:${PREFIX}/bin
setenv PATH ${PATH}:${PREFIX}/scripts
setenv PATH $CERN/bin:$PATH
setenv PATH ${PATH}:${GCC}/bin
setenv PATH ${PATH}:${ROOT}/root/bin
setenv PATH ${PATH}:${PYTHON}/bin
setenv PATH ${PATH}:${SCONS}/bin
setenv PATH ${PATH}:${PREFIX}/build/bin
### standard system paths
setenv PATH ${PATH}:/site/bin:/apps/bin
setenv PATH ${PATH}:/usr/bin:/bin:/usr/sbin:/sbin

setenv PATH ${PATH}:./bin:./build/bin

########################################################################
# LD_LIBRARY_PATH
########################################################################

### run-time library loading path
setenv LD_LIBRARY_PATH .:${PREFIX}/lib

setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${GCC}/lib64
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${ROOT}/root/lib
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${PYTHON}/lib
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${SCONS}/lib

setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${BOOST}/lib
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${PREFIX}/build/lib
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${ROOT_FASTMC}
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${FASTMC}
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${CERN}/lib
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${PLUTO_BUILD}
########################################################################
# PYTHONPATH
########################################################################

### python modules search path

#setenv PYTHONPATH ${PREFIX}/lib/python
setenv PYTHONPATH ${PREFIX}

########################################################################
# sources for build directories
########################################################################

setenv MYSQLINC /usr/include/mysql
setenv MYSQLLIB /usr/lib64/mysql

setenv TCLLIB /usr/lib64

setenv BOOSTINC ${BOOST}
setenv BOOSTLIB ${BOOST}/lib



setenv CLAS6INC ${PREFIX}/build/include
setenv CLAS6LIB ${PREFIX}/build/lib
setenv CLAS6BIN ${PREFIX}/build/bin

########################################################################
# misc
########################################################################

setenv CLAS_PARMS /group/clas/parms
#setenv CLAS_CALDB_RUNINDEX calib_user.RunIndexg12_mk
setenv CLAS_CALDB_RUNINDEX calib_user.RunIndexg12
rehash

