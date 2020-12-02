# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>
# Contributor: Timm Preetz <timm@preetz.us>

pkgname=python-pygments
pkgver=2.7.2
pkgrel=3
pkgdesc="Python syntax highlighter"
arch=('any')
url="https://pygments.org/"
license=('BSD')
depends=('python-setuptools')
makedepends=('python-sphinx')
checkdepends=('python-pytest')
provides=('pygmentize')
conflicts=('pygmentize')
replaces=('pygmentize')
source=(https://pypi.org/packages/source/P/Pygments/Pygments-$pkgver.tar.gz)
sha256sums=('381985fcc551eb9d37c52088a32914e00517e57f4a21609f48141ba08e193fa0')

build() {
  cd "$srcdir/Pygments-$pkgver"
  make -C doc html
}

check() {
  cd "$srcdir/Pygments-$pkgver"
  PYTHONDONTWRITEBYTECODE=1 pytest
}

package() {
  cd "$srcdir/Pygments-$pkgver"

  export PYTHONHASHSEED=0
  python3 setup.py install --root="$pkgdir" -O1
  install -Dm644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"

  mkdir -p "$pkgdir/usr/share/doc"
  cp -rT doc/_build/html "$pkgdir/usr/share/doc/$pkgname"
  install -Dm644 doc/pygmentize.1 -t "$pkgdir/usr/share/man/man1"
  install -Dm644 external/pygments.bashcomp \
    "$pkgdir/usr/share/bash-completion/completions/pygmentize"
}

# vim:set ts=2 sw=2 et:
