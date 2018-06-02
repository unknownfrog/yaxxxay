#!/bin/bash

for build in build/*;do
   pushd $build
   cmake --build
   popd
done 

