# Maintainer: Caleb Maclennan <caleb@alerque.com>

pkgname=btop
pkgver=1.2.7
pkgrel=1
pkgdesc='A monitor of system resources, bpytop ported to C++'
arch=(x86_64)
url="https://github.com/aristocratos/$pkgname"
license=(Apache)
depends=(gcc-libs)
_archive="$pkgname-$pkgver"
source=("$url/archive/v$pkgver/$_archive.tar.gz")
sha256sums=('60075824ca4e14c1ca920b76ffb101fc2340c5342f3ba600b5c280389b69bbbf')

build() {
	cd "$_archive"
	make all
}

package() {
	cd "$_archive"
	make DESTDIR="$pkgdir" PREFIX=/usr install
}

