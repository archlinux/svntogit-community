# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: schuay <jakob.gruber@gmail.com>
# Contributor: Andrea Scarpino <andrea@archlinux.org>
# Contributor: Allan McRae <allan@archlinux.org>
# Contributor: Dan McGee <dan@archlinux.org>

pkgname=qgit
pkgver=2.10
pkgrel=2
pkgdesc='A GIT GUI viewer built on Qt/C++'
url="https://github.com/tibirna/$pkgname"
arch=(x86_64)
license=(GPL)
makedepends=(cmake)
depends=(git
         hicolor-icon-theme
         qt5-base
         qt5-svg)
optdepends=(source-highlight)
source=("$pkgname::git+https://github.com/tibirna/qgit.git#tag=$pkgname-$pkgver")
md5sums=('SKIP')

prepare() {
	cd "$pkgname"
	mkdir -p build
}

build() {
	cd "$pkgname/build"
	cmake -DCMAKE_INSTALL_PREFIX="/usr" ..
	make
}

package() {
	cd "$pkgname/build"
	make DESTDIR="$pkgdir" install
}
