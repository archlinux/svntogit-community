# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: icasdri <icasdri at gmail dot com>
# Contributor: hexchain <i@hexchain.org>

pkgname=mypy
pkgver=0.931
pkgrel=2
pkgdesc='Optional static typing for Python 2 and 3 (PEP484)'
url="http://www.mypy-lang.org/"
arch=('any')
license=('MIT')
depends=('python-psutil' 'python-typed-ast' 'python-mypy_extensions'
         'python-typing_extensions' 'python-toml')
makedepends=('git' 'python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://pypi.org/packages/source/m/$pkgname/$pkgname-$pkgver.tar.gz")
sha256sums=('0038b21890867793581e4cb0d810829f5fd4441aa75796b53033af3aa30430ce')

build() {
    cd "$pkgname-$pkgver"
    python setup.py build
}

package() {
    cd "$pkgname-$pkgver"
    python setup.py install --prefix="/usr" --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
