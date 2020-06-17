#!/usr/bin/env sh

PATH="/usr/lib/jvm/java-8-openjdk/bin:${PATH}"
java -jar /usr/share/java/openapi-generator/openapi-generator-cli.jar "$@"
