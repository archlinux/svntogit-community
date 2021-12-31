# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>
# Contributor: Timm Preetz <timm@preetz.us>

pkgname=python-pygments
pkgver=2.11.0
pkgrel=1
pkgdesc="Python syntax highlighter"
arch=('any')
url="https://pygments.org/"
license=('BSD')
depends=('python-setuptools')
makedepends=('python-sphinx' 'python-wcag-contrast-ratio')
checkdepends=('python-pytest' 'python-lxml')
provides=('pygmentize')
conflicts=('pygmentize')
replaces=('pygmentize')
source=(https://pypi.org/packages/source/P/Pygments/Pygments-$pkgver.tar.gz)
sha256sums=('51130f778a028f2d19c143fce00ced6f8b10f726e17599d7e91b290f6cbcda0c')

build() {
  cd Pygments-$pkgver
  make -C doc html
}

check() {
  cd Pygments-$pkgver
  PYTHONDONTWRITEBYTECODE=1 pytest
}

package() {
  cd Pygments-$pkgver

  python3 setup.py install --root="$pkgdir" -O1
  install -Dm644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"

  mkdir -p "$pkgdir/usr/share/doc"
  cp -rT doc/_build/html "$pkgdir/usr/share/doc/$pkgname"
  install -Dm644 doc/pygmentize.1 -t "$pkgdir/usr/share/man/man1"
  install -Dm644 external/pygments.bashcomp \
    "$pkgdir/usr/share/bash-completion/completions/pygmentize"
}

# vim:set ts=2 sw=2 et:
