# Maintainer: Jiachen YANG <farseerfc@archlinux.org>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: xyzzy <628208@gmail.com>

pkgname=flameshot
pkgver=12.1.0
pkgrel=1
pkgdesc="Powerful yet simple to use screenshot software"
arch=('x86_64')
url="https://github.com/flameshot-org/flameshot"
license=('GPL')
depends=('qt5-svg' 'hicolor-icon-theme' 'kguiaddons')
makedepends=('make' 'qt5-tools' 'cmake')
optdepends=(
    'gnome-shell-extension-appindicator: for system tray icon if you are using Gnome'
    'grim: for wlroots wayland support'
    'xdg-desktop-portal: for wayland support, you will need the implementation for your wayland desktop environment'
)
source=("${pkgname}-v${pkgver}.tar.gz::${url}/archive/v${pkgver}.tar.gz")
sha256sums=('c82c05d554e7a6d810aca8417ca12b21e4f74864455ab4ac94602668f85ac22a')

prepare() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  mkdir -p build
}

build() {
  cd "${srcdir}/${pkgname}-${pkgver}/build"
  cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DUSE_WAYLAND_CLIPBOARD=1
  make
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}/build"
  make DESTDIR="${pkgdir}" install

  # zsh _flameshot completion is provided by zsh-completions so exclude from packaging
  rm -rf ${pkgdir}/usr/share/zsh/
}
