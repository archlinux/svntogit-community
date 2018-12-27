# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor:  Chris Severance aur.severach aATt spamgourmet dott com

_name=pathspec
pkgname=python-pathspec
pkgver=0.5.9
pkgrel=2
pkgdesc='Utility library for gitignore style pattern matching of file paths'
arch=('any')
url=https://github.com/cpburnz/python-path-specification
license=('custom:MPLv2')
depends=('python')
makedepends=('python-setuptools')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('54a5eab895d89f342b52ba2bffe70930ef9f8d96e398cccf530d21fa0516a873')

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  python -m unittest discover pathspec/tests
}

package() {
  cd $_name-$pkgver
  python setup.py install --root="$pkgdir"
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
