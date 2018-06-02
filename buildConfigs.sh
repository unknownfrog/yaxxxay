#!/bin/bash

for build in build/*;do
   pushd $build
   ninja
   popd
done 

