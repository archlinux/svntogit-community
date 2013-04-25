# Maintainer: Daniel Micay <danielmicay@gmail.com>

_hkgname=pcre-light
pkgname=haskell-pcre-light
pkgver=0.4
pkgrel=22
pkgdesc="A small, efficient and portable regex library for Perl 5 compatible regular expressions"
url="http://code.haskell.org/~dons/code/pcre-light"
license=(custom:BSD3)
arch=('i686' 'x86_64')
makedepends=()
depends=("ghc>=7.0.3-2"
         "sh"
         "haskell-bytestring-show"
         "pcre")
options=('strip')
source=("http://hackage.haskell.org/packages/archive/${_hkgname}/${pkgver}/${_hkgname}-${pkgver}.tar.gz")
install="$pkgname.install"
sha256sums=("b37f6ffab07b56540ba4cc410f3ad3c4e0e6e226c610c33f4b7daf70559c31f6")

build() {
  cd "$srcdir/$_hkgname-$pkgver"
  runhaskell Setup configure -O -p --enable-split-objs --enable-shared \
    --prefix=/usr --docdir=/usr/share/doc/$pkgname \
    --libsubdir=\$compiler/site-local/\$pkgid
  runhaskell Setup build
  runhaskell Setup haddock
  runhaskell Setup register --gen-script
  runhaskell Setup unregister --gen-script
  sed -i -r -e "s|ghc-pkg.*unregister[^ ]* |&'--force' |" unregister.sh
}

package() {
  cd "$srcdir/$_hkgname-$pkgver"
  install -Dm744 register.sh "$pkgdir/usr/share/haskell/$pkgname/register.sh"
  install -m744 unregister.sh "$pkgdir/usr/share/haskell/$pkgname/unregister.sh"
  install -dm755 "$pkgdir/usr/share/doc/ghc/html/libraries"
  ln -s /usr/share/doc/$pkgname/html "$pkgdir/usr/share/doc/ghc/html/libraries/$_hkgname"
  runhaskell Setup copy --destdir="$pkgdir"
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  rm -f "$pkgdir/usr/share/doc/$pkgname/LICENSE"
}
