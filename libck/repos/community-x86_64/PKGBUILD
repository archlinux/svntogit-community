# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: banbanchs <memory.silentvoyage@gmail.com>

pkgname=libck
pkgver=0.7.0
pkgrel=1
pkgdesc="A concurrency primitives, safe memory reclamation mechanisms C library"
arch=('x86_64')
url="http://concurrencykit.org"
license=('BSD' 'Apache' 'Custom')
depends=('glibc')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/concurrencykit/ck/archive/${pkgver}.tar.gz")
sha256sums=('e730cb448fb0ecf9d19bf4c7efe9efc3c04dd9127311d87d8f91484742b0da24')

build() {
    cd "$srcdir/ck-$pkgver"
    ./configure --prefix=/usr
    make
}

package() {
    cd "$srcdir/ck-$pkgver"
    make DESTDIR="$pkgdir/" install
    # install license
    install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}

