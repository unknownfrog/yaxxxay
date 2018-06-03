#!/bin/bash

if [ $# > 1 ]; then
  target=$1
else 
  targert=""
fi

for build in build/*;do
   pushd $build
   echo Building in $build
   cmake --build . -- $target
   popd
done 

