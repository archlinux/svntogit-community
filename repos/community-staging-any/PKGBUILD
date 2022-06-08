# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.text
pkgver=3.8.0
pkgrel=1
pkgdesc='Module for text manipulation'
arch=('any')
url='https://github.com/jaraco/jaraco.text'
license=('MIT')
depends=('python-jaraco.functools' 'python-jaraco.context')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
conflicts=('python-jaraco')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.text/jaraco.text-$pkgver.tar.gz")
sha512sums=('3526f1371d8f2e7c79dff61941b1b4ead3d0f4b5144f0e22dbd098ec244b9ffddba4bbeaa0d817a80ff422fa5c7ae11d0959d3f56044d7c5f95d8c8a5de8ad2f')

build() {
  cd "$srcdir/jaraco.text-$pkgver"
  python -m build --wheel --no-isolation
}

package() {
  cd "$srcdir/jaraco.text-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
