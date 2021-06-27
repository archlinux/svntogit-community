#!/bin/sh

APP_CLASSPATH=""
JAVA_EXEC=""
JAVA_OPTS="${JAVA_OPTS} -Xmx1024m --illegal-access=permit"

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

# Build classpath
APP_CLASSPATH="SweetHome3D.jar:Furniture.jar:Textures.jar:Examples.jar:Help.jar:iText-2.1.7.jar:freehep-vectorgraphics-svg-2.1.1b.jar:sunflow-0.07.3i.jar:jmf.jar:batik-svgpathparser-1.7.jar:jeksparser-calculator.jar:jnlp.jar"
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

