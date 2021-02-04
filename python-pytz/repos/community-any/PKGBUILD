# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=('python-pytz' 'python2-pytz')
pkgver=2021.1
pkgrel=1
arch=('any')
url="https://pypi.python.org/pypi/pytz"
license=("MIT")
makedepends=('python' 'python2')
source=("https://pypi.io/packages/source/p/pytz/pytz-${pkgver}.tar.gz"
        "0001-Use-the-system-zoneinfo-from-the-tzdata-package.patch")
sha512sums=('507e24e3c5c2c619d9f3c7f4c33d44d262e33656b07701d0db78f5d67b263ad845dccc4ff50e48c580b0f295cf97ed146af7b9259890a50bb6da4c82b70c439b'
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

    PYTHONHASHSEED=1 python3 setup.py install --root="$pkgdir"/

    install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}


package_python2-pytz(){
    depends=('python2')
    pkgdesc="Cross platform time zone library for Python"

    cd pytz2-$pkgver

    python2 setup.py install --root="$pkgdir"/

    install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
