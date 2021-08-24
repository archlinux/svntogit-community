# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Controbutor: Baptiste Jonglez <archlinux at bitsofnetworks dot org>

pkgname=fig2dev
pkgver=3.2.8.b
_upstreamver=3.2.8b
pkgrel=1
pkgdesc="Format conversion utility that can be used with xfig"
arch=('x86_64')
url="http://mcj.sourceforge.net/"
license=('custom')
depends=('libpng' 'libxpm' 'bc' 'netpbm' 'ghostscript')
makedepends=()
conflicts=('transfig')
replaces=('transfig')
provides=('transfig')
source=("https://downloads.sourceforge.net/mcj/${pkgname}-${_upstreamver}.tar.xz"
        "LICENSE")
sha256sums=('418a164aa9fad72d25bb4fec8d7b452fe3a2f12f990cf22e05c0eb16cecb68cb'
            'e7b5050c353602ff95c6baefea92eebabacbd90b8538495438c574f85c7f7514')

build() {
  cd "${pkgname}-${_upstreamver}"
  ./configure --prefix=/usr --enable-transfig
  make FIG2DEV_LIBDIR=/usr/share/fig2dev XFIGLIBDIR=/usr/share/xfig
}

check() {
  cd "${pkgname}-${_upstreamver}"
  make check
}

package() {
  cd "${pkgname}-${_upstreamver}"
  make DESTDIR="${pkgdir}" XFIGLIBDIR=/usr/share/xfig \
    FIG2DEV_LIBDIR=/usr/share/fig2dev MANPATH=/usr/share/man \
    install
  install -Dm644 ../LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
