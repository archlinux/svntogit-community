# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Unknown47 <unknown47r@gmail.com>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Juergen Hoetzel <juergen@archlinux.org>

pkgname=pcmanfm
pkgver=1.3.2
pkgrel=1
pkgdesc='Extremely fast and lightweight file manager'
arch=('x86_64')
url='https://lxde.org/'
license=('GPL')
groups=('lxde')
depends=('libfm-gtk2' 'lxmenu-data')
makedepends=('intltool')
optdepends=('gvfs: for trash support, mounting with udisks and remote filesystems'
            'xarchiver: archive management')
source=(https://downloads.sourceforge.net/$pkgname/$pkgname-$pkgver.tar.xz)
sha256sums=('14cb7b247493c4cce65fbb5902611e3ad00a7a870fbc1e50adc50428c5140cf7')

build() {
  cd $pkgname-$pkgver
  ./configure --sysconfdir=/etc --prefix=/usr
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
