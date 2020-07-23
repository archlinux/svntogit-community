#!/bin/sh
export PATH=$PATH:/usr/lib/emscripten
# Currently required because of https://github.com/emscripten-core/emscripten/issues/11415
export EM_IGNORE_SANITY=true
