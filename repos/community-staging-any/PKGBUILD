# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=python-pytz
pkgver=2010h
pkgrel=2
pkgdesc="Cross platform time zone library for Python"
arch=('any')
url="http://pypi.python.org/pypi/pytz"
license=("MIT")
depends=('python2')
source=(http://pypi.python.org/packages/source/p/pytz/pytz-$pkgver.tar.bz2)
md5sums=('3c24fd25971b730d6db0426487a21ae0')

build() {
    cd $srcdir/pytz-$pkgver

    # python2 fix
    sed -i 's_#!/usr/bin/env python_#!/usr/bin/env python2_' pytz/tzfile.py

    python2 setup.py install --root=$pkgdir/
    install -D LICENSE.txt $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

