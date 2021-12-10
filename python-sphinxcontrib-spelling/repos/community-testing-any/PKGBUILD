# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>

_name=sphinxcontrib-spelling
pkgname=python-$_name
pkgver=7.3.0
pkgrel=2
pkgdesc="Spelling checker for Sphinx"
arch=('any')
url="https://sphinxcontrib-spelling.readthedocs.io/"
license=('BSD')
depends=('python-sphinx' 'python-pyenchant')
makedepends=('python-setuptools' 'python-pbr')
source=(https://files.pythonhosted.org/packages/source/s/$_name/$_name-$pkgver.tar.gz)
sha256sums=('a11799366f02fbd3390abf6aa2d4f0fe34df9be6e5ac0b1c8139dbd6c7fb0c99')

build() {
  cd $_name-$pkgver
  python setup.py build
}

package() {
  cd $_name-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir/usr/share/licenses/$pkgname" LICENSE
}

# vim:set ts=2 sw=2 et:
