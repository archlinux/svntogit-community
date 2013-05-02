# Maintainer: Christian Hesse <mail@eworm.de>

pkgname=f2fs-tools
pkgver=1.1.0
pkgrel=1
pkgdesc="Tools for Flash-Friendly File System (F2FS)"
arch=('i686' 'x86_64')
url="http://sourceforge.net/projects/f2fs-tools/"
license=('GPL')
source=('http://git.kernel.org/cgit/linux/kernel/git/jaegeuk/f2fs-tools.git/snapshot/f2fs-tools-1.1.0.tar.gz')

build() {
	cd "${pkgname}-${pkgver}"

	autoreconf -fi
	./configure --prefix=/usr
	make
}

package() {
	cd "${pkgname}-${pkgver}"

	make DESTDIR="${pkgdir}/" install
}

sha256sums=('c8cfb6895a0b3775f0df00a776fd451558739289684dd43f1fd75f876fa62867')
