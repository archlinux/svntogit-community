# Contributor: Alex Szczuczko <alex at szc dot ca>

pkgname="bmake-mk-files"
pkgver=20130401
pkgrel=1
pkgdesc="mk files needed by NetBSD make"
arch=('any')
url="http://www.crufty.net/help/sjg/bmake.html"
license=('BSD')
source=("http://www.crufty.net/ftp/pub/sjg/mk-$pkgver.tar.gz")
sha256sums=('12060dbe8656dd69daa12c521ca5af9236208066104939d8c53333da653469b0')

package() {
    cd mk

    sh install-mk "$pkgdir"/usr/share/mk
}
