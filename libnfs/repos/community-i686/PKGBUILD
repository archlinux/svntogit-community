# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=libnfs
pkgver=1.9.3
pkgrel=2
pkgdesc="client library for accessing NFS shares"
arch=('i686' 'x86_64')
url="https://github.com/sahlberg/libnfs"
license=('GPL')
depends=('glibc')
source=(
	"https://github.com/sahlberg/$pkgname/archive/$pkgname-$pkgver.tar.gz"
	'0001-nfs_normalize_path-don-t-strip-trailing-slash-from.patch'
)

prepare() {
  cd "$pkgname-$pkgname-$pkgver"

  patch -p1 -i "$srcdir/0001-nfs_normalize_path-don-t-strip-trailing-slash-from.patch"
}

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

sha256sums=(
	'9d1c988065b373ea25e195aedff4c33ca949fee41c61bdb38a26908bb618315a'
	'4a84a304a8364b89b90ef6bc43c9190e2ff600fd64fd15e6ecc20ab14eed78a5'
)
