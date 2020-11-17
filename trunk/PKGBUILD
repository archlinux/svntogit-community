# Maintainer: David Runge <dvzrv@archlinux.org>

_name=inflect
pkgname=python-inflect
pkgver=5.0.2
pkgrel=2
pkgdesc="Correctly generate plurals, singular nouns, ordinals, indefinite articles"
arch=('any')
url="https://github.com/jazzband/inflect"
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('ea97ec4a4a1a94a6218e60c20d63e483026beb1901abe2fa69f186a823f8a786b9a82af231fc42bf705146f650fdbfa5ff660cfbe821eceb53891ef2e91eaec3')
b2sums=('42b2524b00a8b71aca6f164de9b57708be172ce63bc62480e951d082bd68f082ad2fadb502321a5fc97ffa3af95f26935d0de855144863b9bd1dfbdf3bdae516')

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
