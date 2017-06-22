# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=libnfs
pkgver=2.0.0
pkgrel=1
pkgdesc="client library for accessing NFS shares"
arch=('i686' 'x86_64')
url="https://github.com/sahlberg/libnfs"
license=('GPL')
depends=('glibc')
source=(
	"https://github.com/sahlberg/$pkgname/archive/$pkgname-$pkgver.tar.gz"
)
sha256sums=('7ea6cd8fa6c461d01091e584d424d28e137d23ff4b65b95d01a3fd0ef95d120e')

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

