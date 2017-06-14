# Maintainer: Bruno Pagani (a.k.a. ArchangeGabriel) <archange@archlinux.org>
# Contributor: Mirco Tischler <mt-ml at gmx dot de>

pkgname=fwupd
pkgver=0.9.3
pkgrel=3
pkgdesc='A simple daemon to allow session software to update firmware'
arch=('i686' 'x86_64')
url='https://github.com/hughsie/fwupd'
license=('GPL2')
depends=('appstream-glib' 'fwupdate' 'colord')
#makedepends=('meson' 'valgrind' 'docbook2x' 'gobject-introspection' 'gtk-doc')
makedepends=('meson' 'valgrind' 'docbook-utils' 'docbook-sgml' 'perl-sgmls'
             'gobject-introspection' 'gtk-doc')
source=(${pkgname}-${pkgver}.tar.gz::"${url}/archive/${pkgver}.tar.gz"
        'fix-missing-test-files.patch'
        'fix-failure-without-remote-d.patch'
        'fix-refresh-crash.patch')
sha256sums=('56840998a4a7757ac93732c4a51e203e1fef1497dc98ebc175310b132da2a2cc'
            'ee2bb86e1efaff2d4ca3f2ed55fd8b685cba2cb40debf1418d4e91e27dba00a7'
            '79a5ffc151067d52ff49af55b851b8bcd0976e47d1751268fb1bdd61b46f5dbe'
            '0718def1d7572e47822e76d4745971f64c8ec070de6d8778ea9816a218011bb8')

prepare() {
    cd ${pkgname}-${pkgver}
    patch -p1 -i ../fix-missing-test-files.patch
    patch -p1 -i ../fix-failure-without-remote-d.patch
    patch -p1 -i ../fix-refresh-crash.patch
}

build() {
    cd ${pkgname}-${pkgver}

    meson --prefix=/usr \
        --sysconfdir=/etc \
        --localstatedir=/var \
        --libexecdir=/usr/lib \
        --buildtype=plain \
        ../build

    ninja -v -C ../build
}

check() {
    ninja -C build test
}

package() {
    DESTDIR="${pkgdir}" ninja -C build install
}
