# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-qthelp
pkgname=python-sphinxcontrib-qthelp
pkgver=1.0.2
pkgrel=1
pkgdesc='Sphinx extension which outputs QtHelp document'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-qthelp
license=('BSD')
depends=('python-sphinx')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('79465ce11ae5694ff165becda529a600c754f4bc459778778c7017374d4d406f')

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  pytest
}

package() {
  cd $_name-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
