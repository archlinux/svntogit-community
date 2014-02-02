# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=libnfs
pkgver=1.9.2
pkgrel=1
pkgdesc="client library for accessing NFS shares"
arch=('i686' 'x86_64')
url="https://github.com/sahlberg/libnfs"
license=('GPL')
depends=('glibc')
source=("https://github.com/sahlberg/$pkgname/archive/$pkgname-$pkgver.tar.gz")

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
sha256sums=('77d9d543eb1ae3e36497e5a3d4f37c8dd3d66def8d11817d4ed84368bbbb225b')
