# Maintainer: Caleb Maclennan <caleb@alerque.com>

pkgname=btop
pkgver=1.2.10
pkgrel=1
pkgdesc='A monitor of system resources, bpytop ported to C++'
arch=(x86_64)
url="https://github.com/aristocratos/$pkgname"
license=(Apache)
depends=(gcc-libs)
_archive="$pkgname-$pkgver"
source=("$url/archive/v$pkgver/$_archive.tar.gz")
sha256sums=('6f84579d3737b8fdfa6afb788b788569702d6f17ef294c9bc9404fefc7aae1a0')

build() {
	cd "$_archive"
	make all
}

package() {
	cd "$_archive"
	make DESTDIR="$pkgdir" PREFIX=/usr install
}

