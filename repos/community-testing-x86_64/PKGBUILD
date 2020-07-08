# Maintainer: Baptiste Jonglez <baptiste--aur at jonglez dot org>
# Contributor: Anatol Pomozov <anatol dot pomozov at gmail>
# Contributor: Gustavo Alvarez <s1pkn07@gmail.com>
# Contributor: Kristjan Reinloo <mail at kreinloo dot net>
# Contributor: Pierre Bourdon <delroth@gmail.com>

pkgname=libnatpmp
pkgver=20150609
pkgrel=3
pkgdesc='A portable and fully compliant implementation of the NAT-PMP protocol'
arch=(x86_64)
url='http://miniupnp.free.fr/libnatpmp.html'
license=(BSD)
depends=(glibc)
source=("https://miniupnp.tuxfamily.org/files/libnatpmp-$pkgver.tar.gz")
sha1sums=('8a4eb09b9512c73ebe4b44b6b66b43504cb69539')

prepare() {
  cd $pkgname-$pkgver
  sed -e 's/CFLAGS = /CFLAGS += /' -i Makefile
}

build() {
  cd $pkgname-$pkgver
  make
}

package() {
  cd $pkgname-$pkgver
  make INSTALLPREFIX="$pkgdir/usr" INSTALLDIRINC="$pkgdir/usr/include" install
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -Dm644 natpmpc.1 "$pkgdir/usr/share/man/man1/natpmpc.1"
}
