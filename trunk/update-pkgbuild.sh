#!/bin/bash

. PKGBUILD

FILE=$(wget -qO - https://addons.mozilla.org/en-US/firefox/addon/adblock-plus/versions/ | grep -oP "https://addons.mozilla.org/firefox/downloads/file/\d+/adblock_plus-$pkgver.xpi" | cut -d/ -f7)

sed -i "s|_file=.*|_file=$FILE|" PKGBUILD
updpkgsums
