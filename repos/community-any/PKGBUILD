# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

# Check compatibility with jedi on potential version bumps
_pkgbase=parso
pkgname=python-parso
epoch=1
pkgver=0.7.1
pkgrel=1
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
depends=('python')
makedepends=('python-setuptools' 'python-sphinx')
checkdepends=('python-pytest')
source=(https://github.com/davidhalter/parso/archive/v$pkgver/$pkgname-$pkgver.tar.gz.tar.gz)
sha512sums=('318969a7a941c4a0948e58643b07b6f5c446ea166b3a8e44a556f0677ec9a36d7dc8c6d37ca7bce3f8276ee3d7144e22fbaaeac90c738fb90f7e94a0cf8abf7d')
b2sums=('1e47c1dd6846d01aa5820d7cedc3eafcf12ea0d4a2e95fa3f54429633b1c12dc39a4abe237fa46eb629408006777bd1f512cf878025b55119568ac19729b8c19')

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
