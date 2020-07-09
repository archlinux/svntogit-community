# Maintainer: Giovanni Scafora <giovanni@archlinux.org>
# Contributor: danitool

pkgname=libgoom2
pkgver=2k4
pkgrel=5
pkgdesc="Shared library part of the Goom visualization plugin"
arch=('x86_64')
url="https://www.fovea.cc/?page=details_produits&id=goom"
license=('LGPL')
depends=('glibc')
options=('!emptydirs')
source=("https://downloads.sourceforge.net/project/goom/goom2k4/0/goom-2k4-0-src.tar.gz")
sha512sums=('790e3ab8dee122320ad8b3ae15f6a1cd2780222d5ae97979f614f16ba73b4b853960e7945ef9053ad9eddf9e29e69d0c52f0875d07c5c6c7cee41d764bf4ea5f')

build() {
  cd "${srcdir}/goom2k4-0"

  ./configure --prefix=/usr \
              --without-xmms \
              --without-sdl
  make
}

package() {
  cd "${srcdir}/goom2k4-0"

  make DESTDIR="${pkgdir}" install
}
