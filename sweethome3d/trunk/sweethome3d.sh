#!/bin/sh

APP_CLASSPATH=""
JAVA_EXEC=""
JAVA_OPTS="${JAVA_OPTS} -Xmx1024m"

if [ -n "${JAVA_HOME}" ]
then
  if [ -x "${JAVA_HOME}/bin/java" ]
  then
    JAVA_EXEC="${JAVA_HOME}/bin/java"
  fi
else
  JAVA_EXEC="$(which java)"
fi

if [ -z "${JAVA_EXEC}" ]
then
  echo "No 'java' executable can be found, please set JAVA_HOME variable or"
  echo "use the 'archlinux-java' script to set the Java version."
  exit 1
fi

# Find Java version
JAVA_VERSION="$(${JAVA_EXEC} -version 2>&1 | grep ' version ' | head -1 | cut -d' ' -f 3 | tr -d '"')"

# Fix for Java 16 compatibility
# https://bugs.archlinux.org/task/71255
# https://sourceforge.net/p/sweethome3d/bugs/1021/
if [ $(vercmp "${JAVA_VERSION}" "16") -gt 0 ]
then
  # Add illegal-access=permit argument
  JAVA_OPTS="${JAVA_OPTS} --add-opens=java.desktop/sun.awt=ALL-UNNAMED --add-opens=java.desktop/com.apple.eio=ALL-UNNAMED --add-opens=java.desktop/com.apple.eawt=ALL-UNNAMED"
fi

# Build classpath
APP_CLASSPATH="SweetHome3D.jar:Furniture.jar:Textures.jar:Examples.jar:Help.jar:iText-2.1.7.jar:freehep-vectorgraphics-svg-2.1.1c.jar:sunflow-0.07.3i.jar:jmf.jar:batik-svgpathparser-1.7.jar:jeksparser-calculator.jar:jnlp.jar"
if [ "${SWEETHOME3D_JAVA3D}" = "1.6" ]
then
  JAVA_OPTS="${JAVA_OPTS} -Djava.library.path=/usr/lib/sweethome3d/java3d-1.6 -Djogamp.gluegen.UseTempJarCache=false"
  APP_CLASSPATH="${APP_CLASSPATH}:/usr/lib/sweethome3d/java3d-1.6/j3dcore.jar:/usr/lib/sweethome3d/java3d-1.6/j3dutils.jar:/usr/lib/sweethome3d/java3d-1.6/vecmath.jar:/usr/lib/sweethome3d/java3d-1.6/gluegen-rt.jar:/usr/lib/sweethome3d/java3d-1.6/jogl-all.jar"
else
  JAVA_OPTS="${JAVA_OPTS} -Djava.library.path=/usr/lib/sweethome3d/java3d-1.5"
  APP_CLASSPATH="${APP_CLASSPATH}:/usr/lib/sweethome3d/java3d-1.5/j3dcore.jar:/usr/lib/sweethome3d/java3d-1.5/j3dutils.jar:/usr/lib/sweethome3d/java3d-1.5/vecmath.jar"
fi

cd "/usr/share/java/sweethome3d"

exec "${JAVA_EXEC}" \
     -classpath "${APP_CLASSPATH}" \
     ${JAVA_OPTS} \
     -Dcom.eteks.sweethome3d.applicationId=SweetHome3D#Installer \
     com.eteks.sweethome3d.SweetHome3D \
     -open "$1"

