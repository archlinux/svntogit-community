# Maintainer: David Runge <dvzrv@archlinux.org>

_name=inflect
pkgname=python-inflect
pkgver=4.1.0
pkgrel=2
pkgdesc="Correctly generate plurals, singular nouns, ordinals, indefinite articles"
arch=('any')
url="https://github.com/jazzband/inflect"
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('9a2ba4777f01475390976f3ac28f046d39d1f86cfdafd161cc7c8d33526aca35d44e6598ccf2a0b68d3511a64b67ed0991b51c78bda8f279cd706fd29a3fa514')
b2sums=('c15f6b0d5d93050283dfc4d691e9fdbc26bb2f71573d6b397834e87af62f3afb8f5cdb0448c531de37e84729c0c6ae0cf4ea7a7b081a9dd784f7c06b962d7def')

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
  pytest -v --ignore setup.py
}

package() {
  cd "$pkgname-$pkgver"
  python setup.py install --skip-build \
                          --optimize=1 \
                          --root="${pkgdir}"
  install -vDm 644 {{CHANGES,README}.rst,CONTRIBUTING.md} \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
}
