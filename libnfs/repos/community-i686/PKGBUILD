# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=libnfs
pkgver=1.10.0
pkgrel=1
pkgdesc="client library for accessing NFS shares"
arch=('i686' 'x86_64')
url="https://github.com/sahlberg/libnfs"
license=('GPL')
depends=('glibc')
source=(
	"https://github.com/sahlberg/$pkgname/archive/$pkgname-$pkgver.tar.gz"
)
sha256sums=('7f6c62a05c7e0f0749f2b13f178a4ed7aaf17bd09e65a10bb147bfe9807da272')

#prepare() {
  #cd "$pkgname-$pkgname-$pkgver"

#}

build() {
	cd "$pkgname-$pkgname-$pkgver"

	autoreconf -vif
	./configure --prefix=/usr
	make
}

package() {
	cd "$pkgname-$pkgname-$pkgver"
	make DESTDIR="$pkgdir" install
}

