#!/bin/bash
clang-format --style=file:config/.clang-format -i --verbose \
  src/*.cpp \
  include/micro-os-plus/*.h \
  include/micro-os-plus/micro-test-plus/*.h \
  include/micro-os-plus/micro-test-plus/inlines/*.h
