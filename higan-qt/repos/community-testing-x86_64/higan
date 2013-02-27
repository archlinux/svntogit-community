#!/bin/sh

# Shared folders workaround
cp -ru /usr/share/higan ~/.config/

# Check for profiles and prompt user with a GUI
[ -e /usr/bin/higan-accuracy ] && tag1=accuracy
[ -e /usr/bin/higan-balanced ] && tag2=balanced
[ -e /usr/bin/higan-performance ] && tag3=performance
profile="$(Xdialog --stdout --no-tags --title "higan" --radiolist "Choose a profile" 0 0 0 "$tag1" "Accuracy" off "$tag2" "Balanced" off "$tag3" "Performance" off)"

# Launch selected profile
exec higan-$profile "$@"
