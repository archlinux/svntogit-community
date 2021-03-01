# Maintainer: David Runge <dvzrv@archlinux.org>

_name=inflect
pkgname=python-inflect
pkgver=5.2.0
pkgrel=3
pkgdesc="Correctly generate plurals, singular nouns, ordinals, indefinite articles"
arch=('any')
url="https://github.com/jazzband/inflect"
license=('MIT')
depends=('python')
makedepends=('python-setuptools_scm' 'python-toml')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('2883ffccd28c436908783855a282ff4346c74b14fe5899ed6b9fde0f0f1b97063119f7fbe927f1bf0d16761623abcdfe21439c12311bd2a11a70245b89fbce0b')
b2sums=('cf2327eb0aca6319b43076a0f52d7e5c52bad3be45cbc094e620d6219b0b05021d05c289992b36d3221d1e582352497fb278d9225ece49ddc0630f91199b1617')

prepare() {
  mv -v "${_name}-$pkgver" "$pkgname-$pkgver"
  cd "$pkgname-$pkgver"
  # we don't do linting
  sed '/addopts/d' -i pytest.ini
}

build() {
  cd "$pkgname-$pkgver"
  python setup.py build
}

check() {
  cd "$pkgname-$pkgver"
  export PYTHONPATH="build:${PYTHONPATH}"
  pytest -v
}

package() {
  cd "$pkgname-$pkgver"
  python setup.py install --skip-build \
                          --optimize=1 \
                          --root="${pkgdir}"
  install -vDm 644 {CHANGES,README}.rst \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
}
