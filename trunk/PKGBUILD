# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: rilian-la-te <ria.freelander@gmail.com>
# Contributor: Kaizhao Zhang <zhangkaizhao@gmail.com>

pkgname=appmenu-gtk-module
pkgver=0.7.6
pkgrel=1
pkgdesc="Application Menu GTK+ Module"
depends=()
makedepends=(meson gtk3 gtk2)
optdepends=('gtk3: GTK3 module' 'gtk2: GTK2 module')
url="https://gitlab.com/vala-panel-project/vala-panel-appmenu/"
arch=(x86_64)
license=(LGPL3)
source=("https://gitlab.com/vala-panel-project/vala-panel-appmenu/-/archive/$pkgver/vala-panel-appmenu-$pkgver.tar.gz"
        80-appmenu-gtk-module)
sha256sums=('6ade911726c5cfa6e49416b7480c286cd5e098a7a1105f7f027827e3c3a4e119'
            '4c006c4ea7b8556070ad6d35529d3a9e23da8033429e34d1824c25942d969fbc')

build() {
  meson build vala-panel-appmenu-$pkgver/subprojects/$pkgname \
    --prefix=/usr
  ninja -C build
}

package() {
  DESTDIR="$pkgdir" ninja install -C build
  install -Dm755 80-appmenu-gtk-module -t "$pkgdir"/etc/X11/xinit/xinitrc.d/
}
