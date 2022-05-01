# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>

_name=sphinxcontrib-spelling
pkgname=python-$_name
pkgver=7.3.3
pkgrel=1
pkgdesc="Spelling checker for Sphinx"
arch=('any')
url="https://sphinxcontrib-spelling.readthedocs.io/"
license=('BSD')
depends=('python-sphinx' 'python-pyenchant')
makedepends=('python-setuptools' 'python-pbr')
source=(https://files.pythonhosted.org/packages/source/s/$_name/$_name-$pkgver.tar.gz)
sha256sums=('3819d12629d95e0c909224fa40b462a67e0adb321d50283d7fc0d11686c8ac7e')

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
