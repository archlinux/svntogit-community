# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>
# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Laurent Carlier <lordheavym@gmail.com>
# Contributor: DsTr <dstr@gmail.com>
# Contributor: Allan McRae <allan@archlinux.org>

pkgname=winetricks
pkgver=20220411
pkgrel=1
pkgdesc='Script to install various redistributable runtime libraries in Wine.'
url='https://wiki.winehq.org/winetricks'
license=('LGPL')
arch=('x86_64')
depends=('cabextract' 'perl' 'unzip' 'xorg-xmessage')
optdepends=('zenity: GUI for GNOME desktop'
            'kdialog: GUI for KDE desktop')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Winetricks/winetricks/archive/$pkgver.tar.gz")
sha512sums=('c4e77c5e62d2df56db6aa75979cc775f26472917108b0498c975458fd6f7ecbef52c329b7b6f33c12510176e105190bc538447b39348a42b7f1a8e07e5d92d09')

package() {
  depends+=('wine')

  cd winetricks-$pkgver
  make DESTDIR="$pkgdir" install
}
