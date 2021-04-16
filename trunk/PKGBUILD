# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: banbanchs <memory.silentvoyage@gmail.com>

pkgname=libck
pkgver=0.6.0
pkgrel=1
pkgdesc="A concurrency primitives, safe memory reclamation mechanisms C library"
arch=('x86_64')
url="http://concurrencykit.org"
license=('BSD' 'Apache' 'Custom')
depends=('glibc')
source=("${url}/releases/ck-${pkgver}.tar.gz")
sha256sums=('d7e27dd0a679e45632951e672f8288228f32310dfed2d5855e9573a9cf0d62df')

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

