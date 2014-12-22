# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=libnfs
pkgver=1.9.6
pkgrel=1
pkgdesc="client library for accessing NFS shares"
arch=('i686' 'x86_64')
url="https://github.com/sahlberg/libnfs"
license=('GPL')
depends=('glibc')
source=(
	"https://github.com/sahlberg/$pkgname/archive/$pkgname-$pkgver.tar.gz"
)

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

sha256sums=('75f49d967e9032e0ee4757f970f87c274c3503c968caba2be8a37df63d965f32')
