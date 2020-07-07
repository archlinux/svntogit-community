# Maintainer: David Runge <dave@sleepmap.de>
# Contributor: Ray Rashif <schiv@archlinux.org>
# Contributor: James Rayner <james@archlinux.org>

pkgname=schedtool
pkgver=1.3.0
pkgrel=7
pkgdesc="Query or alter a process' scheduling policy"
arch=('x86_64')
url="https://github.com/freequaos/schedtool"
license=('GPL2')
groups=('realtime')
depends=('glibc')
source=("https://github.com/freequaos/${pkgname}/archive/${pkgname}-${pkgver}.tar.gz")
sha512sums=('71b7bbc91ee86a83639b179c8cce70e0fd3acca3af3cbc51880cf1f177fdd901e1fb6d0ecea2aa40761608589e7b903431ac97d5046f9ec50535bad691af2964')

prepare() {
  mv -v "$pkgname-$pkgname-$pkgver" "$pkgname-$pkgver"
  cd "$pkgname-$pkgver"
  # fix install location of docs
  sed -e 's/(RELEASE)/(TARGET)/g' -i Makefile
}

build() {
  cd "$pkgname-$pkgver"
  make
}

package() {
  cd "$pkgname-$pkgver"
  make DESTPREFIX="$pkgdir/usr" install
}

# vim:set ts=2 sw=2 et:
