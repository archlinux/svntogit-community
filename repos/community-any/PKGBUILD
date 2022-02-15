# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jaraco.context
pkgver=4.1.1
pkgrel=2
pkgdesc="Context managers by jaraco"
url="https://github.com/jaraco/jaraco.context"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-pytest')
source=("https://github.com/jaraco/jaraco.context/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('d1def3f0f701d36f584a60c57837d5e4bf9121c5ce8387f734ac371164f5ba0fe04b73d4d0e16367cfcd6a13cf11ab5dab2afe798f18dfddba15700fe6779fe0')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cd jaraco.context-$pkgver
}

build() {
  cd jaraco.context-$pkgver
  python setup.py build
}

check() {
  cd jaraco.context-$pkgver
  python -m pytest
}

package() {
  cd jaraco.context-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
