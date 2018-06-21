#!/bin/bash -x

source PKGBUILD
wget https://www.rfc-editor.org/rfc/tar/RFC-all.tar.gz
wget https://www.rfc-editor.org/rfc/rfc-index.txt
scp RFC-all.tar.gz repos.archlinux.org:/srv/sources/other/community/rfc/RFC-all-$pkgver.tar.gz
scp rfc-index.txt repos.archlinux.org:/srv/sources/other/community/rfc/rfc-index-$pkgver.txt
