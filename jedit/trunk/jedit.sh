#!/bin/sh
#
# Runs jEdit - Programmer's Text Editor.
#

# Set jvm heap initial and maximum sizes (in megabytes).
JAVA_HEAP_MAX_SIZE=192

DEFAULT_JAVA_HOME="/usr/lib/jvm/java-6-openjdk"
if [ -z "$JAVA_HOME" ]; then
  JAVA_HOME="$DEFAULT_JAVA_HOME"
fi

# If $HOME/.jedit/properties exists, don't do anything.
# If not, copy in a default file
if [ ! -e $HOME/.jedit ]; then
  mkdir $HOME/.jedit
  if [ ! -e $HOME/.jedit/properties ]; then
		cp /usr/share/jedit/default.props $HOME/.jedit/properties
  fi
fi

# Launch application
exec "$JAVA_HOME/jre/bin/java" -Xmx${JAVA_HEAP_MAX_SIZE}M -jar "/usr/share/java/jedit/jedit.jar" "$@"
