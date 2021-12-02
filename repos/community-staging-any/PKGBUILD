# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

# Check compatibility with jedi on potential version bumps
_pkgbase=parso
pkgname=python-parso
epoch=1
pkgver=0.8.2
pkgrel=3
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
depends=('python')
makedepends=('python-setuptools' 'python-sphinx')
checkdepends=('python-pytest')
source=(https://github.com/davidhalter/parso/archive/v$pkgver/$_pkgbase-$pkgver.tar.gz
        7652d3904be3fd5513581a8250d95df31a8cef06.patch::https://github.com/davidhalter/parso/commit/7652d3904be3fd5513581a8250d95df31a8cef06.patch)
sha512sums=('a90810ad89301d804d215392ed77593b015f13bc7ef8512302a8893b314a9e74c15e2aaa77157c8595a134d3481e8115f306f9628835271478837ec6f19e645f'
            'a60f8e1030e08b18251dac49e81a9e9cfac5e367af44fae94c4ef19ba857311df49264b2c3327d4fdc17005f03c0d71d67a4fbb907627a96869ed18ec0d25bfa')
b2sums=('f4e86ae55140adc9bbfdd34a8044e7fdfbf9d318a6385ac5feedc07127061943c2d690581af144f158846e3bf6f82124046c7e625369a4055ab92a54f9210c49'
        '767f63dcb6a8368a94162bd1e30614d19ae234b0554a00ef2821260b0992eb7f3ca2d8342571822e5bc8afd5c81b68f538de20ac976414f8f9878a82b4ecd10c')

prepare() {
  cd "$_pkgbase-$pkgver"
  patch -p1 <"$srcdir"/7652d3904be3fd5513581a8250d95df31a8cef06.patch
}

check() {
  cd "$_pkgbase-$pkgver"
  # test_python_excetion_matches broke with 3.10 due to exception formatting changes.
  # https://github.com/davidhalter/parso/issues/192
  pytest test -k 'not test_python_exception_matches'
}

build() {
  cd "$_pkgbase-$pkgver"
  python setup.py build
  sphinx-build -b text docs docs/_build/text
  sphinx-build -b man docs docs/_build/man
}

package() {
  cd "$_pkgbase-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm 644 LICENSE.txt -t "$pkgdir/usr/share/licenses/$pkgname"
  install -Dm 644 CHANGELOG.rst README.rst docs/_build/text/*.txt -t "$pkgdir/usr/share/doc/$pkgname"
  install -Dm 644 docs/_build/man/parso.1 "$pkgdir/usr/share/man/man1/$pkgname.1"
}

# vim: ts=2 sw=2 et:
