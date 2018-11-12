# Maintainer: Evgeniy Alekseev <arcanis at archlinux dot org>
# Contributor: Alex Chamberlain <alex at alexchamberlain dot co dot uk>
# Contributor: Kars Wang <jaklsy at gmail dot com>

pkgname=jq
pkgver=1.6
pkgrel=1
pkgdesc='Command-line JSON processor'
arch=('x86_64')
url='http://stedolan.github.io/jq/'
license=('MIT')
depends=('glibc' 'oniguruma')
makedepends=('autoconf' 'automake' 'bison' 'flex' 'python2')
source=("https://github.com/stedolan/jq/releases/download/${pkgname}-${pkgver}/${pkgname}-${pkgver}.tar.gz")
changelog=ChangeLog
sha512sums=('f5ae8be558ca2ff15324c378d623106b74bd0823be50835e23548584aa1eb24eb81f8f054693d5d3fe44f157d0735c5f0f40b9f21899ba068f2a11d1345ace19')

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

