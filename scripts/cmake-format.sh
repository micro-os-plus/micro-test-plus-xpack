#!/bin/bash
# pip3 install --user cmakelang pyyaml

# set -x
PYPATH="$(python3 -m site --user-base)"
echo cmake-format "$(${PYPATH}/bin/cmake-format --version)"
# "${PYPATH}/bin/cmake-format" --no-default --dump-config yaml --config-file "config/.cmake-format.yaml"

find . \( \( -type d -name "build" \) -o \( -type d -name "xpacks" \) -o \( -type d -name "node_modules" \) \) -prune -o \
  -type f \( -name "CMakeLists.txt" -o -name "*.cmake" \) -print \
  -exec "${PYPATH}/bin/cmake-format" --config-file "config/.cmake-format.yaml" --in-place {} +
