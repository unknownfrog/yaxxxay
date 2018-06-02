#!/bin/bash

compilers=`ls /usr/bin/g++-[1-9]* /usr/bin/clang++-[6-9].[0-9]`

buildModes="DEBUG RELEASE RELWITHDEBINFO MINSIZEREL"

# echo compiler = $compilers 
# echo buildmode = $buildModes

for compiler in $compilers;do
    name=`basename $compiler`
    for buildmode in $buildModes;do
       sourceDir=$(pwd)
       config=${name}-${buildmode}
       dir=build/${config}
       mkdir -p $dir
       pushd $dir
       echo configure $config
       cmake -GNinja -DCMAKE_CXX_COMPILER=$compiler -DCMAKE_BUILD_TYPE=$buildmode . $sourceDir
       popd
    done
done
