# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Michael Yeatts <mwyeatts@gmail.com>

pkgname=python-typing_extensions
pkgver=3.10.0.0
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
_tag=edd78b2253abffc5cc82c32a43c22845fb7c465f
source=(git+https://github.com/python/typing.git#tag=${_tag})
sha256sums=(SKIP)

pkgver() {
  cd typing

  git describe --tags
}

prepare() {
  sed 's/3.7.4.2/3.7.4.3/g' -i typing/typing_extensions/setup.py
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
