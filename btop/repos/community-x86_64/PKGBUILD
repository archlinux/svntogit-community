# Maintainer: Caleb Maclennan <caleb@alerque.com>

pkgname=btop
pkgver=1.0.18
pkgrel=1
pkgdesc='A monitor of system resourecs, bpytop ported to C++'
arch=(x86_64 aarch64)
url="https://github.com/aristocratos/$pkgname"
license=(Apache)
depends=(gcc-libs)
_archive="$pkgname-$pkgver"
source=("$_archive.tar.gz::$url/archive/v$pkgver.tar.gz")
sha256sums=('29015bf7f34d87c7748f816f72f981f56f894946c6ec0faa330f71a8537781b7')

build() {
	cd "$_archive"
	make all
}

package() {
	cd "$_archive"
	make DESTDIR="$pkgdir" PREFIX=/usr install
}

