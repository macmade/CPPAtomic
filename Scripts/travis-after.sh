#!/bin/bash

# Reports code coverage to coveralls.io
source Scripts/xcenv-lib.sh
declare -r DIR_BUILD_LIB="${OBJECT_FILE_DIR_normal}/${CURRENT_ARCH}/"
source Scripts/xcenv-tests.sh
declare -r DIR_BUILD_TESTS="${OBJECT_FILE_DIR_normal}/${CURRENT_ARCH}/"
source Scripts/xcenv-helper.sh
declare -r DIR_BUILD_HELPER="${OBJECT_FILE_DIR_normal}/${CURRENT_ARCH}/"
xcode-coveralls --include CPPAtomic --project CPPAtomic.xcodeproj "${DIR_BUILD_LIB}" "${DIR_BUILD_TESTS}" "${DIR_BUILD_HELPER}"
