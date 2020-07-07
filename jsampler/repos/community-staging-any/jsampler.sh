#!/bin/sh

export PATH="/usr/lib/jvm/java-8-openjdk/bin/:${PATH}"

if [ $# -eq 0 ] || [ "$1" = "fantasia" ]; then
  java -jar /usr/share/java/jsampler/fantasia.jar
elif [ "$1" = "classic" ]; then
  java -jar /usr/share/java/jsampler/classic.jar
fi
