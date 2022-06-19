# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>

_name=sphinxcontrib-spelling
pkgname=python-$_name
pkgver=7.5.1
pkgrel=1
pkgdesc="Spelling checker for Sphinx"
arch=('any')
url="https://sphinxcontrib-spelling.readthedocs.io/"
license=('BSD')
depends=('python-sphinx' 'python-pyenchant')
makedepends=('python-setuptools' 'python-pbr')
source=(https://files.pythonhosted.org/packages/source/s/$_name/$_name-$pkgver.tar.gz)
sha256sums=('0fc4c248639ecef3d48a04754feba174468e6b36b56c903025c50d60d6cfb4ef')

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
