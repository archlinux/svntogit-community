# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Michael Yeatts <mwyeatts@gmail.com>

pkgname=python-typing_extensions
pkgver=3.7.4.1
pkgrel=1
pkgdesc='Backported and Experimental Type Hints for Python 3.5+'
arch=(any)
url=https://github.com/python/typing/tree/master/typing_extensions
license=(custom)
depends=(python)
makedepends=(
  git
  python-setuptools
)
provides=(python-typing-extensions)
conflicts=(python-typing-extensions)
source=(git+https://github.com/python/typing.git#tag=7c00cacae00c4f3263e939e88b5e7739150851e5)
sha256sums=(SKIP)

pkgver() {
  cd typing

  git describe --tags
}

prepare() {
  cd typing

  git cherry-pick -n c943372c3c01f9fa62f8d80fd4f50c7603ef1ce4
}

build() {
  cd typing/typing_extensions

  python setup.py build
}

package() {
  cd typing/typing_extensions

  python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}"/usr/share/licenses/python-typing_extensions/
}

# vim: ts=2 sw=2 et:
