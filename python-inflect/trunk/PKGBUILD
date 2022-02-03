# Maintainer: David Runge <dvzrv@archlinux.org>

_name=inflect
pkgname=python-inflect
pkgver=5.4.0
pkgrel=1
pkgdesc="Correctly generate plurals, singular nouns, ordinals, indefinite articles"
arch=(any)
url="https://github.com/jazzband/inflect"
license=(MIT)
depends=(python)
makedepends=(python-setuptools-scm python-toml)
checkdepends=(python-pytest)
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('48b7d38faf41b3f682226b66ea5493b7d4ff58a8db52c9b90092fc329aee761b090791deeda24234b9f9fa47d8db9b499e1f4304367ef3637c441959e8b8d005')
b2sums=('60898e019c04b9d86a1591c341f48e7e3093eaa4f93bb4f902f4d405f1151d705f902b792028ca97a85ed47ffe509bab758b3ec74878ec82f5dac3c953197ca0')

build() {
  cd "${_name}-$pkgver"
  python setup.py build
}

check() {
  cd "${_name}-$pkgver"
  export PYTHONPATH="build:${PYTHONPATH}"
  pytest -v -c /dev/null
}

package() {
  cd "${_name}-$pkgver"
  python setup.py install --optimize=1 --root="${pkgdir}"
  install -vDm 644 {CHANGES,README}.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
}
