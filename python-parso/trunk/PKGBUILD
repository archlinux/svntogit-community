# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

# Check compatibility with jedi on potential version bumps
_pkgbase=parso
pkgname=python-parso
epoch=1
pkgver=0.8.1
pkgrel=1
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
depends=('python')
makedepends=('python-setuptools' 'python-sphinx')
checkdepends=('python-pytest')
source=(https://github.com/davidhalter/parso/archive/v$pkgver/$_pkgbase-$pkgver.tar.gz)
sha512sums=('10cc36a4f288d06b8d06bf3995eafe8c6b5d46d0ab01ce6db4557c82f8c64c6792b438a5b7dea570a9690bad586ab4216161268be9c1979b91b3af50e1c8801c')
b2sums=('d8d2a025dfb6664d8deeabfc621f4dcf0c6f6e0769dc3a7081888436cce39685f7749ee4ed33c501e3690bec0c8b21d18195d585a8baf5fa8c1b1ae1bfad5680')

check() {
  cd "$_pkgbase-$pkgver"
  pytest test
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
