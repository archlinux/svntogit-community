# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: icasdri <icasdri at gmail dot com>
# Contributor: hexchain <i@hexchain.org>

pkgname=mypy
pkgver=0.600
pkgrel=3
pkgdesc='Optional static typing for Python 2 and 3 (PEP484)'
url="http://www.mypy-lang.org/"
arch=('any')
license=('MIT')
depends=('python' 'python-psutil' 'python-typed-ast')
makedepends=('python-setuptools' 'git')
source=("$pkgname-$pkgver.tar.gz::https://pypi.org/packages/source/m/$pkgname/$pkgname-$pkgver.tar.gz")
sha256sums=('bc251cb31bc236d9fe4bcc442c994c45fff2541f7161ee52dc949741fe9ca3dd')

build() {
    cd "$pkgname-$pkgver"
    python setup.py build
}

package() {
    cd "$pkgname-$pkgver"
    python setup.py install --prefix="/usr" --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
