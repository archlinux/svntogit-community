# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=python-pytz
pkgver=2010o
pkgrel=1
pkgdesc="Cross platform time zone library for Python"
arch=('any')
url="http://pypi.python.org/pypi/pytz"
license=("MIT")
depends=('python2')
source=(http://pypi.python.org/packages/source/p/pytz/pytz-$pkgver.tar.bz2)
md5sums=('88b641aafc6025acf5368766b51b00d3')

build() {
    cd $srcdir/pytz-$pkgver

    # python2 fix
    sed -i 's_#!/usr/bin/env python_#!/usr/bin/env python2_' pytz/tzfile.py

    python2 setup.py install --root=$pkgdir/
    install -D LICENSE.txt $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

