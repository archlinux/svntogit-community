# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=('python-pytz' 'python2-pytz')
pkgver=2021.3
pkgrel=1
arch=('any')
url="https://pypi.python.org/pypi/pytz"
license=("MIT")
makedepends=('python' 'python2')
source=("https://pypi.io/packages/source/p/pytz/pytz-${pkgver}.tar.gz"
        "0001-Use-the-system-zoneinfo-from-the-tzdata-package.patch")
sha512sums=('c45099f319592976b7715d9973496a2c7438a1b958ef8b90a1ad1fb97e7035624fe6191796727d4b7edf3236271bea4d864e25d1d92431e8cf767ac798448882'
            '3cbd497313c3049a2ae04298118aefb6dfa9ec4626078c665c95c13a78ae944b33a68813aea0c53b02b0532b64221cca4a0cd2153bd91b3760916bc3c0f6df8f')
validpgpkeys=('C7ECC365AB6F255E1EB9BA1701FA998FBAC6374A')

prepare() {
    cd pytz-$pkgver

    patch -p2 -i ../0001-Use-the-system-zoneinfo-from-the-tzdata-package.patch
    rm -r pytz/zoneinfo/
}

build(){
    cp -rf pytz-$pkgver pytz2-$pkgver
}

check(){
    cd pytz-$pkgver/pytz/tests

    python3 test_tzinfo.py
    python2 test_tzinfo.py
}

package_python-pytz(){
    depends=('python')
    pkgdesc="Cross platform time zone library for Python"

    cd pytz-$pkgver

    python3 setup.py install --root="$pkgdir"/

    install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}


package_python2-pytz(){
    depends=('python2')
    pkgdesc="Cross platform time zone library for Python"

    cd pytz2-$pkgver

    python2 setup.py install --root="$pkgdir"/

    install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
