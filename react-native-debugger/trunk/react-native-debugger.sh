#!/bin/bash

: ${ELECTRON_DISABLE_SECURITY_WARNINGS=1}

export ELECTRON_DISABLE_SECURITY_WARNINGS

exec /usr/lib/react-native-debugger/react-native-debugger
