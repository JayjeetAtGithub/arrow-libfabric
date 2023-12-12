#!/bin/bash
set -ex

. ~/spack/share/spack/setup-env.sh
spack load mercury

cmake .
make -j32