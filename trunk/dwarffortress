#!/bin/sh
export SDL_DISABLE_LOCK_KEYS=1 # Work around for bug in Debian/Ubuntu SDL patch.
#export SDL_VIDEO_CENTERED=1    # Centre the screen.  Messes up resizing.

pkgname=dwarffortress #To be set by PKGBUILD

if [[ ! -d "$HOME/.$pkgname" ]]; then
    mkdir "$HOME/.$pkgname"
    cp -rn /opt/"$pkgname"/data "$HOME/.$pkgname/"
    cp -rsn /opt/"$pkgname"/* "$HOME/.$pkgname/"
fi

cd "$HOME/.$pkgname"
exec ./libs/Dwarf_Fortress "$@"

