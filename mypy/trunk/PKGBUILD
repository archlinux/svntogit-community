# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: icasdri <icasdri at gmail dot com>
# Contributor: hexchain <i@hexchain.org>

pkgname=mypy
pkgver=0.950
pkgrel=1
pkgdesc='Optional static typing for Python 2 and 3 (PEP484)'
url="http://www.mypy-lang.org/"
arch=('any')
license=('MIT')
depends=('python-psutil' 'python-typed-ast' 'python-mypy_extensions'
         'python-typing_extensions' 'python-tomli')
makedepends=('git' 'python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://pypi.org/packages/source/m/$pkgname/$pkgname-$pkgver.tar.gz")
sha256sums=('1b333cfbca1762ff15808a0ef4f71b5d3eed8528b23ea1c3fb50543c867d68de')

build() {
    cd "$pkgname-$pkgver"
    python setup.py build
}

package() {
    cd "$pkgname-$pkgver"
    python setup.py install --prefix="/usr" --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
