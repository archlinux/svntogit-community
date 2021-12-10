# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Michael Yeatts <mwyeatts@gmail.com>

pkgname=python-typing_extensions
pkgver=3.10.0.2
pkgrel=4
pkgdesc='Backported and Experimental Type Hints for Python 3.5+'
arch=(any)
url=https://github.com/python/typing/tree/master/typing_extensions
license=(custom)
depends=(python)
makedepends=(
  git
  python-setuptools
)
checkdepends=(python-tests)
provides=(python-typing-extensions)
conflicts=(python-typing-extensions)
_tag=7552efe8b5f96f0e63f8e77711a4cf03cae92921
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

check() {
  cd typing/typing_extensions

  python -m venv --system-site-packages test-env
  test-env/bin/python setup.py install --optimize=1 --skip-build
  test-env/bin/python src_py3/test_typing_extensions.py
}

package() {
  cd typing/typing_extensions

  python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}"/usr/share/licenses/python-typing_extensions/
}

# vim: ts=2 sw=2 et:
