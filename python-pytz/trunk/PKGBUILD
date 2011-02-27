# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=python-pytz
pkgver=2011b
pkgrel=2
pkgdesc="Cross platform time zone library for Python"
arch=('any')
url="http://pypi.python.org/pypi/pytz"
license=("MIT")
depends=('python')
source=(http://pypi.python.org/packages/source/p/pytz/pytz-$pkgver.zip)
md5sums=('2e53b9d3141e6b8728a6c79ecf3afc0d')

build() {
    cd $srcdir/pytz-$pkgver
    python setup.py install --root=$pkgdir/
    install -D LICENSE.txt $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

