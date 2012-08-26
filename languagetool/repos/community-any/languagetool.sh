#!/bin/bash

file_present=false
asked_for_help=false

for arg in "$@"; do
  if [[ $arg != -* ]]; then
    file_present=true
  fi
  if [[ $arg == -h ]]; then
    asked_for_help=true
  fi
  if [[ $arg == --help ]]; then
    asked_for_help=true
  fi
done

CP=/usr/share/languagetool
for name in /usr/share/java/languagetool/*.jar ; do
  CP=$CP:$name
done
CLI_command='org.languagetool.Main'
GUI_command='org.languagetool.gui.Main'

if $asked_for_help; then
  echo "Command-line interface (CLI) help:"
  "$JAVA_HOME/bin/java" -cp $CP $CLI_command -h | sed "s/java -jar LanguageTool.jar/languagetool/"
  echo
  echo "Graphical user interface (GUI) help:"
  "$JAVA_HOME/bin/java" -cp $CP $GUI_command -h | sed "s/java org.languagetool.gui.Main/languagetool/"
else
  if $file_present; then
    "$JAVA_HOME/bin/java" -cp $CP $CLI_command "$@"
  else
    "$JAVA_HOME/bin/java" -cp $CP $GUI_command "$@"
  fi
fi

