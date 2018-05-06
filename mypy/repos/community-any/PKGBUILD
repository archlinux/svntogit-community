# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: icasdri <icasdri at gmail dot com>
# Contributor: hexchain <i@hexchain.org>

pkgname=mypy
pkgver=0.600
pkgrel=2
pkgdesc='Optional static typing for Python 2 and 3 (PEP484)'
url="http://www.mypy-lang.org/"
arch=('any')
license=('MIT')
depends=('python' 'python-psutil' 'python-typed-ast')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/python/mypy/archive/v$pkgver.tar.gz")
sha256sums=('29d57a1cafabee3aebbbcc66ec82a92b838e80af2b50e90c6acb88d6756bb40e')

build() {
    cd "$pkgname-$pkgver"
    python setup.py build
}

package() {
    cd "$pkgname-$pkgver"
    python setup.py install --prefix="/usr" --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
