# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Thomas Conneely <tc116 at le dot ac dot uk>
# with credit to
#   Maintainer: Arkham <arkham at archlinux dot us>
#   Contributor: roverorna <roverorna at gmail dot com>
# for the cnetworkmanager-git PKGBUILD

pkgname=cnetworkmanager
pkgver=0.21.1
pkgrel=3
pkgdesc="Command Line Interface for NetworkManager"
arch=('any')
url="http://vidner.net/martin/software/cnetworkmanager/"
license=('GPL')
depends=('networkmanager' 'dbus-python' 'pygobject')
makedepends=('setuptools')
source=("http://vidner.net/martin/software/cnetworkmanager/$pkgname-$pkgver.tar.gz")
options=(!emptydirs)
md5sums=('3703a43a6d6f3692cb8dbac6372834f2')

build() {
    cd $srcdir/$pkgname-$pkgver

    # python2 fix
    sed -i 's_#!/usr/bin/env python_#!/usr/bin/env python2_' networkmanager/applet/pbkdf2.py

    python2 setup.py install --root=$pkgdir/ --optimize=1
}
