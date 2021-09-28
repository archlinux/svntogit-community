# Maintainer: Caleb Maclennan <caleb@alerque.com>

pkgname=btop
pkgver=1.0.10
pkgrel=1
pkgdesc='A monitor of system resourecs, bpytop ported to C++'
arch=(x86_64 aarch64)
url="https://github.com/aristocratos/$pkgname"
license=(Apache)
depends=(gcc-libs)
_archive="$pkgname-$pkgver"
source=("$_archive.tar.gz::$url/archive/v$pkgver.tar.gz")
sha256sums=('b4ae49ef7414a88618d182856214b96b9eca53a9cffec0e250070399bc98a7cf')

build() {
	cd "$_archive"
	make all
}

package() {
	cd "$_archive"
	make DESTDIR="$pkgdir" PREFIX=/usr install
}

