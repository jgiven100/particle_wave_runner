#!/bin/bash
find src/ -iname *.h -o -iname *.cpp | xargs clang-format -style=file -i
find include/ -iname *.h -o -iname *.cpp | xargs clang-format -style=file -i
