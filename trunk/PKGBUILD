# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: banbanchs <memory.silentvoyage@gmail.com>

pkgname=libck
pkgver=0.7.1
pkgrel=1
pkgdesc="A concurrency primitives, safe memory reclamation mechanisms C library"
arch=('x86_64')
url="http://concurrencykit.org"
license=('BSD' 'Apache' 'Custom')
depends=('glibc')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/concurrencykit/ck/archive/${pkgver}.tar.gz")
sha256sums=('97d2a21d5326ef79b4668be2e6eda6284ee77a64c0981b35fd9695c736c3d4ac')

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

