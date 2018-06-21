#!/bin/bash -x

source PKGBUILD
wget https://docs.python.org/3/archives/python-$pkgver-docs-html.tar.bz2
scp python-$pkgver-docs-html.tar.bz2 repos.archlinux.org:/srv/sources/other/community/python-docs/
