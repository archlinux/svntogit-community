# Maintainer: David Runge <dvzrv@archlinux.org>

_name=inflect
pkgname=python-inflect
pkgver=5.3.0
pkgrel=4
pkgdesc="Correctly generate plurals, singular nouns, ordinals, indefinite articles"
arch=('any')
url="https://github.com/jazzband/inflect"
license=('MIT')
depends=('python')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('f5baf65fb7a6ba59c91a36a17acb0abda3efc74fef56b3a3d99c100b2c6e94c5aafb08ab37310ce410631ac928e9c24a4a4c5e6b5c7d8f907c3d999f4a70cce4')
b2sums=('20c591012a5a6692c3da3a39f4aeaaae290da5ba723af5c9ac90f7d28112a1894acf082633f8f673f6d903f756b9bb70c6c3366762e872cf7ca6c6d5edf1c99c')

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
  python setup.py install --optimize=1 --root="${pkgdir}"
  install -vDm 644 {CHANGES,README}.rst \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
}
