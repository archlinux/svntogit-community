# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Lex Black <autumn-wind@web.de>
# Contributor: Arthur Zamarin <arthurzam@gmail.com>

pkgname=openlibm
pkgver=0.8.1
pkgrel=1
pkgdesc='Standalone implementation of C mathematical functions'
arch=(x86_64)
url='https://openlibm.org/'
license=(BSD)
depends=(glibc)
source=(https://github.com/JuliaLang/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('ba8a282ecd92d0033f5656bb20dfc6ea3fb83f90ba69291ac8f7beba42dcffcf')

prepare() {
  cd $pkgname-$pkgver
  sed -e 's|/usr/local|/usr|' -i Make.inc
}

build() {
  cd $pkgname-$pkgver
  make prefix=/usr
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install

  install -Dm644 LICENSE.md -t "$pkgdir"/usr/share/licenses/$pkgname/
}
