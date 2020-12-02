# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-zipp
pkgver=3.4.0
pkgrel=3
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-jaraco' 'python-func-timeout')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jaraco/zipp/archive/v$pkgver.tar.gz")
sha512sums=('ef76ed1bf104990c990b4857a13b9ffaa5ec12ce324d978562c0eefd2e784500b874d69dfda87b7910eb676d8eb4cc26cf46c38553c604c4f8aea9143b97b8dc')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd zipp-$pkgver
  python setup.py build
}

check() {
  cd zipp-$pkgver
  python -m unittest discover
}

package() {
  cd zipp-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
