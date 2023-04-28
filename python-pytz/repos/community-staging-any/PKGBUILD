# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=python-pytz
pkgver=2023.3
pkgrel=1
arch=('any')
url="https://pypi.python.org/pypi/pytz"
license=("MIT")
pkgdesc="Cross platform time zone library for Python"
depends=('python')
makedepends=('python')
source=("https://pypi.io/packages/source/p/pytz/pytz-${pkgver}.tar.gz"
        "0001-Use-the-system-zoneinfo-from-the-tzdata-package.patch")
sha512sums=('3a39e9ec22bf1468e7415f60f10bf4a4e5b0b12bea2aeec45c5e63a916136c747fa0abd1b0612a99da962e743f28f24ebc43c1d73d96f0e98f7fb0ae6b62e319'
            '3cbd497313c3049a2ae04298118aefb6dfa9ec4626078c665c95c13a78ae944b33a68813aea0c53b02b0532b64221cca4a0cd2153bd91b3760916bc3c0f6df8f')
validpgpkeys=('C7ECC365AB6F255E1EB9BA1701FA998FBAC6374A')

prepare() {
    cd pytz-$pkgver

    patch -p2 -i ../0001-Use-the-system-zoneinfo-from-the-tzdata-package.patch
    rm -r pytz/zoneinfo/
}

build(){
    cd pytz-$pkgver
    python setup.py build
}

check(){
    cd pytz-$pkgver/pytz/tests

    python3 test_tzinfo.py
}

package(){
    cd pytz-$pkgver

    python3 setup.py install --root="$pkgdir"/

    install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
