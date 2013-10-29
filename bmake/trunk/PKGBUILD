# Maintainer: Alex Szczuczko <alex at szc dot ca>
# Contributor: Devin Cofer <ranguvar{AT]archlinux[DOT}us>
# Contributor: Imanol Celaya <ilcra1989@gmail.com>

pkgname=bmake
pkgver=20130730
pkgrel=1
pkgdesc="Portable version of the NetBSD 'make' build tool"
arch=('i686' 'x86_64')
url="http://www.crufty.net/help/sjg/bmake.html"
license=('BSD')
depends=('bmake-mk-files')
source=("http://www.crufty.net/ftp/pub/sjg/bmake-$pkgver.tar.gz")
sha256sums=('57f4fb71472ab8f1cb53e83fd043b3556c9624fa601f930415ba64489c9b0828')

build() {
    rm -rf bmake-build
    mkdir bmake-build
    cd bmake-build

    ../bmake/configure --prefix=/usr --with-default-sys-path=/usr/share/mk

    sh make-bootstrap.sh
}

package() {
    install -Dm755 bmake-build/bmake "$pkgdir"/usr/bin/bmake
    install -Dm644 bmake/bmake.1 "$pkgdir"/usr/share/man/man1/bmake.1
}
