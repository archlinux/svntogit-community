# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Bert Muennich <muennich at informatik.hu-berlin.de>
# Contributor: Brad Fanella <bradfanella@archlinux.us>

pkgname=sxiv
pkgver=24
pkgrel=1
pkgdesc='Simple X Image Viewer'
arch=('i686' 'x86_64')
license=('GPL2')
url='https://github.com/muennich/sxiv'
depends=('imlib2' 'desktop-file-utils' 'xdg-utils' 'hicolor-icon-theme' 'libexif' 'libxft')
source=("$pkgname-$pkgver.tar.gz"::"https://github.com/muennich/sxiv/archive/v$pkgver.tar.gz")
md5sums=('a929f8ae19f947a23594fdce2b3cf38d')

prepare() {
  cd "$pkgname-$pkgver"
  ln -s config.def.h config.h
}

build() {
  make -C "$pkgname-$pkgver"
}

package() {
  cd "$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
  make -C icon PREFIX=/usr DESTDIR="$pkgdir" install
  install -Dm644 sxiv.desktop "$pkgdir"/usr/share/applications/sxiv.desktop
}
