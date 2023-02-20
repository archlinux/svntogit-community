# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>

_name=sphinxcontrib-spelling
pkgname=python-$_name
pkgver=8.0.0
pkgrel=1
pkgdesc="Spelling checker for Sphinx"
arch=('any')
url="https://sphinxcontrib-spelling.readthedocs.io/"
license=('BSD')
depends=('python-sphinx' 'python-pyenchant')
makedepends=('python-build' 'python-installer' 'python-wheel'
             'python-setuptools' 'python-setuptools-scm')
source=(https://files.pythonhosted.org/packages/source/s/$_name/$_name-$pkgver.tar.gz)
sha256sums=('199d0a16902ad80c387c2966dc9eb10f565b1fb15ccce17210402db7c2443e5c')

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 -t "$pkgdir/usr/share/licenses/$pkgname" LICENSE
}

# vim:set ts=2 sw=2 et:
