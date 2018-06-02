#!/bin/bash

compilers=`ls /usr/bin/gcc-[4-9]* /usr/bin/clang-[4-9].0`

buildModes="DEBUG RELEASE RELWITHDEBINFO MINSIZEREL"

echo compiler = $compilers 
echo buildmode = $buildModes

for compiler in $compilers;do
    name=`basename $compiler`
    for buildmode in $buildModes;do
       sourceDir=$(pwd)
       dir=build/${name}-${buildmode}
       mkdir -p $dir
       pushd $dir
       cmake -GNinja -DCMAKE_CXX_COMPILER=$compiler -DCMAKE_BUILD_TYPE=$buildmode . $sourceDir
       popd
    done
done
