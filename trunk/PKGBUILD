# Maintainer: Evgeniy Alekseev <arcanis at archlinux dot org>
# Contributor: Alex Chamberlain <alex at alexchamberlain dot co dot uk>
# Contributor: Kars Wang <jaklsy at gmail dot com>

pkgname=jq
pkgver=1.6
pkgrel=3
pkgdesc='Command-line JSON processor'
arch=('x86_64')
url='https://stedolan.github.io/jq/'
license=('MIT')
depends=('glibc' 'oniguruma')
makedepends=('autoconf' 'automake' 'bison' 'flex' 'python2')
source=("https://github.com/stedolan/jq/releases/download/${pkgname}-${pkgver}/${pkgname}-${pkgver}.tar.gz")
changelog=ChangeLog
sha512sums=('5da71f53c325257f1f546a2520fe47828b495c953270df25ea0e37741463fdda72f0ba4d5b05b25114ec30f27a559344c2b024bacabf610759f4e3e9efadb480')

build() {
    cd "${pkgname}-${pkgver}"
    ./configure --prefix=/usr
    make
}

package() {
    cd "${pkgname}-${pkgver}"
    make DESTDIR="${pkgdir}" prefix=/usr install
    install -Dm644 COPYING "${pkgdir}/usr/share/licenses/${pkgname}/COPYING"
}

