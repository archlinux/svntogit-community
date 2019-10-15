# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Kaiting Chen <kaitocracy@gmail.com>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>
# Contributor: Eric Belanger <eric@archlinux.org>
# Contributor: Jan Fader <jan.fader@web.de>

pkgname=fish
pkgver=3.0.2
pkgrel=2
pkgdesc='Smart and user friendly shell intended mostly for interactive use'
url='https://fishshell.com/'
arch=('x86_64')
license=('GPL2')
depends=('glibc' 'gcc-libs' 'jq' 'ncurses' 'pcre2')
optdepends=('python: man page completion parser / web config tool'
            'pkgfile: command-not-found hook')
makedepends=('doxygen')
install=fish.install
source=(https://github.com/fish-shell/fish-shell/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz
        fish-fix-systemd-version.patch::https://github.com/fish-shell/fish-shell/commit/c6ec4235136e82c709e8d7b455f7c463f9714b48.patch)
sha256sums=('0421a3fdf5df54c14cddd4d764bc0931bbb4d37fb799205a9457c6eaba513166'
            'b74077f1ae695ec4cd31acc8e1d4140ed2323716e1d0fac1cc2c66d06329431a')
sha512sums=('d3a24f85d4ada891ec4f6b14733edb236ae67f34868b0c9115fa5ebae99202a747ee9aeec7c6b04702f9a608019d5964b9cdc9abc4e3edfd7aaa9335093d8881'
            'f4762c4fc6fcff7c52a9d10aa9b32d3470e0f5cee222927e2beccd0bb7fccf27fb628b33a9db7971362c38e53c2452f5cca513495bd6227e6b140afbd186217e')

prepare() {
  cd fish-shell-${pkgver}
  patch -p1 < ../fish-fix-systemd-version.patch
  echo ${pkgver} > version
  autoreconf -fiv
}

build() {
  cd fish-shell-${pkgver}
  ./configure \
    --prefix=/usr \
    --sysconfdir=/etc
  make
}

package() {
  cd fish-shell-${pkgver}
  make DESTDIR="${pkgdir}" install
}

# vim: ts=2 sw=2 et:
