# Maintainer: Caleb Maclennan <caleb@alerque.com>

pkgname=btop
pkgver=1.0.15
pkgrel=1
pkgdesc='A monitor of system resourecs, bpytop ported to C++'
arch=(x86_64 aarch64)
url="https://github.com/aristocratos/$pkgname"
license=(Apache)
depends=(gcc-libs)
_archive="$pkgname-$pkgver"
source=("$_archive.tar.gz::$url/archive/v$pkgver.tar.gz")
sha256sums=('ddb1e396e220a8d9a1a84a8b0d84b907950adf0ead6f4c9261fbfbacaf0589d7')

build() {
	cd "$_archive"
	make all
}

package() {
	cd "$_archive"
	make DESTDIR="$pkgdir" PREFIX=/usr install
}

