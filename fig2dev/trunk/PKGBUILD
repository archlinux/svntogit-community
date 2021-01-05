# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Controbutor: Baptiste Jonglez <archlinux at bitsofnetworks dot org>

pkgname=fig2dev
pkgver=3.2.7.b
_upstreamver=3.2.7b
pkgrel=2
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
sha1sums=('8097c178b7fff1023112250938cc87837c0f564e'
          'b8b712871615308b8b6add92f86d218437d652f2')

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
