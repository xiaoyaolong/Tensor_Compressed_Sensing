MATLAB="/Applications/MATLAB_R2011a.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/ccaiafa/.matlab/R2011a"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for Calc_cii_8" > Calc_cii_8_mex.mki
echo "CC=$CC" >> Calc_cii_8_mex.mki
echo "CFLAGS=$CFLAGS" >> Calc_cii_8_mex.mki
echo "CLIBS=$CLIBS" >> Calc_cii_8_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> Calc_cii_8_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> Calc_cii_8_mex.mki
echo "CXX=$CXX" >> Calc_cii_8_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> Calc_cii_8_mex.mki
echo "CXXLIBS=$CXXLIBS" >> Calc_cii_8_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> Calc_cii_8_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> Calc_cii_8_mex.mki
echo "LD=$LD" >> Calc_cii_8_mex.mki
echo "LDFLAGS=$LDFLAGS" >> Calc_cii_8_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> Calc_cii_8_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> Calc_cii_8_mex.mki
echo "Arch=$Arch" >> Calc_cii_8_mex.mki
echo OMPFLAGS= >> Calc_cii_8_mex.mki
echo OMPLINKFLAGS= >> Calc_cii_8_mex.mki
echo "EMC_COMPILER=unix" >> Calc_cii_8_mex.mki
echo "EMC_CONFIG=debug" >> Calc_cii_8_mex.mki
"/Applications/MATLAB_R2011a.app/bin/maci64/gmake" -B -f Calc_cii_8_mex.mk
