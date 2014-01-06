#!/bin/sh
# Runs jEdit - Programmer's Text Editor

# If $HOME/.jedit or $HOME/.jedit/properties exists, don't do anything.
# If not, copy in a default property file.
if [ ! -e $HOME/.jedit ]; then
  if [ ! -e $HOME/.jedit/properties ]; then
    mkdir $HOME/.jedit
		cp /usr/share/jedit/default.props $HOME/.jedit/properties
  fi
fi

# Set jvm heap initial and maximum sizes (in megabytes).
JAVA_HEAP_MAX_SIZE=192

exec java -Xmx${JAVA_HEAP_MAX_SIZE}M -Dawt.useSystemAAFontSettings=lcd -jar "/usr/share/java/jedit/jedit.jar" "$@"
