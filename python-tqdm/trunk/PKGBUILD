# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.55.0
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools-scm')
checkdepends=('python-pytest' 'python-pytest-asyncio' 'python-numpy' 'python-pandas'
              'python-tensorflow')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('ca529a20c167b67b9efbdeeac65e820b0f28dc5cd2a386c1e6a139a16c004d0ccafdf5c388e6b6ec8f94fc8c4ced123453ce73fe9af42dcc5abd44f3df62e006')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd tqdm-$pkgver
  python setup.py build
}

check() {
  cd tqdm-$pkgver
  python setup.py egg_info
  python -m pytest
}

package() {
  cd tqdm-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENCE "$pkgdir"/usr/share/licenses/$pkgname/LICENCE
}

# vim:set ts=2 sw=2 et:
