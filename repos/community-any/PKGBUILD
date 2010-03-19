# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=python-pytz
pkgver=2010e
pkgrel=1
pkgdesc="Cross platform time zone library for Python"
arch=('any')
url="http://pypi.python.org/pypi/pytz"
license=("MIT")
depends=('python')
source=(http://pypi.python.org/packages/source/p/pytz/pytz-$pkgver.tar.bz2)
md5sums=('91542bfeaff33dc6839055a083d3bf67')

build() {
    cd $srcdir/pytz-$pkgver
    python setup.py install --root=$pkgdir/ || return 1 
    install -D LICENSE.txt $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

