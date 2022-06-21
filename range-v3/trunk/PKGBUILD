# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>
# Contributor: hexchain <i at hexchain.org>

pkgname=range-v3
pkgver=0.12.0
pkgrel=1
pkgdesc="Experimental range library for C++11/14/17"
arch=('any')
url='https://github.com/ericniebler/range-v3'
license=('custom')
makedepends=('cmake' 'ninja')
source=("$pkgname-$pkgver.tar.gz::https://github.com/ericniebler/range-v3/archive/${pkgver}.tar.gz")
sha512sums=('b8b632b8e0f2a3234ef61813212c237f648cd741e816ca57bd86f82f6459f7d755e2b70361d2aa43847874fb546a31a792ab1c3ba90292818ae7313438dc62d0')

build() {
    cd "${srcdir}/range-v3-${pkgver}"

    cmake \
        -Bbuild \
        -GNinja \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DRANGE_V3_TESTS=OFF \
        -DRANGE_V3_HEADER_CHECKS=OFF \
        -DRANGE_V3_EXAMPLES=OFF \
        -DRANGE_V3_PERF=OFF
    ninja -C build
}

package() {
    cd "${srcdir}/range-v3-${pkgver}"
    install -Dm644 "LICENSE.txt" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"

    DESTDIR="${pkgdir}/" ninja -C build install
    mv "$pkgdir"/usr/include/module.modulemap "$pkgdir"/usr/include/range-v3.modulemap
}
