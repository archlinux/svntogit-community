# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Juergen Hoetzel <juergen@archlinux.org>

pkgname=lxde-common
pkgver=0.99.2
pkgrel=3
pkgdesc='Common files of the LXDE Desktop'
arch=('any')
url='https://lxde.org/'
license=('GPL2')
groups=('lxde' 'lxde-gtk3')
backup=(etc/xdg/lxsession/LXDE/desktop.conf
        etc/xdg/lxsession/LXDE/autostart)
makedepends=('intltool')
optdepends=('gnome-themes-standard: default GTK+ theme'
            'lxde-icon-theme: default icon theme')
source=(https://downloads.sourceforge.net/lxde/$pkgname-$pkgver.tar.xz
        dbus-update-environment.patch
        default-config.patch)
sha256sums=('1cd9bc900960c995d48ffbbdc86ecffda7c806168c67aaa50c53113794234856'
            '87f1413f5bb371de45451fc7f82f9f80a23c90f5799bed173ec31589824c03bb'
            '6a31a706d0fd1cb168b495806bb4a646c019e3b9c4f6bc13aae9edb8b0372d9d')

prepare() {
    cd $pkgname-$pkgver
    patch -Np1 -i ../dbus-update-environment.patch
    patch -Np1 -i ../default-config.patch
}

build() {
    cd $pkgname-$pkgver
    ./configure --sysconfdir=/etc --prefix=/usr
    make
}

package() {
    cd $pkgname-$pkgver
    make DESTDIR="$pkgdir" install
}
