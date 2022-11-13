# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>

_name=sphinxcontrib-spelling
pkgname=python-$_name
pkgver=7.7.0
pkgrel=1
pkgdesc="Spelling checker for Sphinx"
arch=('any')
url="https://sphinxcontrib-spelling.readthedocs.io/"
license=('BSD')
depends=('python-sphinx' 'python-pyenchant')
makedepends=('python-setuptools' 'python-pbr')
source=(https://files.pythonhosted.org/packages/source/s/$_name/$_name-$pkgver.tar.gz)
sha256sums=('56561c3f6a155b0946914e4de988729859315729dc181b5e4dc8a68fe78de35a')

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
