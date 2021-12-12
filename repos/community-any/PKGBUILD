# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor:  Chris Severance aur.severach aATt spamgourmet dott com

_name=pathspec
pkgname=python-pathspec
pkgver=0.9.0
pkgrel=3
pkgdesc='Utility library for gitignore style pattern matching of file paths'
arch=('any')
url=https://github.com/cpburnz/python-path-specification
license=('MPL2')
depends=('python')
makedepends=('python-setuptools')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('e564499435a2673d586f6b2130bb5b95f04a3ba06f81b8f895b651a3c76aabb1')
b2sums=('00b48f6987a074e23ac6f344a44ac8f265463bdd87907cb8a602c690a739d1a9a673182fc4d61a6e2ffc02acb6632591b873e435f9fc3893e1cc48015e120a16')

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
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim:set ts=2 sw=2 et:
