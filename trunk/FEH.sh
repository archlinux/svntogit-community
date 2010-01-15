#!/bin/bash
function directRendering() {
out=$(glxinfo | grep "direct rendering")
direct=${out#"direct rendering: "}
if [ "$direct" = "Yes" ]; then
  return 0
else
  return 1
fi
}

function colorDepth() {
out=$(xdpyinfo | grep "depth of root")
color=${out:27:2}
if [ "$color" = "24" ]; then
  return 0
else
  return 1
fi
}

directRendering
direct_ok=$?

colorDepth
color_ok=$?

exit_val=0

if [ $direct_ok -ne 0 ]; then
  echo "XBMC needs hardware accelerated OpenGL rendering."
  echo "Install an appropriate graphics driver."
  echo " "
  echo "Please consult XBMC Wiki for supported hardware"
  echo "http://xbmc.org/wiki/?title=Supported_hardware"
  exit_val=1
fi

if [ $color_ok -ne 0 ]; then
  echo "XBMC cannot run unless the"
  echo "screen color depth is atleast 24 bit."
  echo " "
  echo "Please reconfigure your screen."
  exit_val=1
fi

exit $exit_val
