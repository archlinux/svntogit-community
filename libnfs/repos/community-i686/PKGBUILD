# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=libnfs
pkgver=1.9.8
pkgrel=1
pkgdesc="client library for accessing NFS shares"
arch=('i686' 'x86_64')
url="https://github.com/sahlberg/libnfs"
license=('GPL')
depends=('glibc')
source=(
	"https://github.com/sahlberg/$pkgname/archive/$pkgname-$pkgver.tar.gz"
)
sha256sums=('e95af693e763a504eee72dacf3dc6c1001d83e40b807e7e1d0be2eaf48af779c')

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

