# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Arthur Zamarin <arthurzam@gmail.com>
# Contributor: andrew.p <pan.pav.7c5@gmail.com>

pkgname=lightdm-gtk-greeter-settings
pkgver=1.2.2
pkgrel=8
pkgdesc='Settings editor for the LightDM GTK+ Greeter'
arch=(any)
url=https://github.com/xubuntu/lightdm-gtk-greeter-settings
license=(GPL3)
depends=(
  gtk-update-icon-cache
  lightdm-gtk-greeter
  python-gobject
)
makedepends=(
  git
  python-distutils-extra
)
_tag=6280b2e0386f589730233cdc4532b6110f743473
source=(git+https://github.com/Xubuntu/lightdm-gtk-greeter-settings.git#tag=${_tag})
b2sums=(SKIP)

build() {
  cd lightdm-gtk-greeter-settings
  python setup.py build
}

package() {
  cd lightdm-gtk-greeter-settings
  python setup.py install --root="${pkgdir}" --optimize=1 --xfce-integration
}

# vim: ts=2 sw=2 et:
