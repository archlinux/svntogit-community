# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor : Ionut Biru <ibiru@archlinux.org>
# Contributor: Roman Kyrylych <roman@archlinux.org>
# Contributor: Alexander Mieland (dma147) <dma147@linux-stats.org>
# Contributor: Thorsten Töpper <atsutane-tu@freethoughts.de>
# Contributor: Baptiste Jonglez <baptiste--aur at jonglez dot org>

pkgname=confuse
pkgver=3.3
pkgrel=3
pkgdesc='C-library for parsing configuration files'
arch=('x86_64')
url='https://github.com/libconfuse/libconfuse'
license=('ISC')
depends=('glibc')
source=("https://github.com/libconfuse/libconfuse/releases/download/v${pkgver}/${pkgname}-${pkgver}.tar.gz")
options=('!emptydirs')
sha256sums=('3a59ded20bc652eaa8e6261ab46f7e483bc13dad79263c15af42ecbb329707b8')

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  ./configure --prefix=/usr --enable-shared
  make
}

check() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  make check
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  make DESTDIR="${pkgdir}" install
  install -D -m 644 -t "${pkgdir}/usr/share/licenses/${pkgname}/" LICENSE
}
